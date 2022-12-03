// Copyright (C) 2002-2012 Nikolaus Gebhardt / Thomas Alten
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#include "IrrCompileConfig.h"
#include "IBurningShader.h"

#ifdef _NIRT_COMPILE_WITH_BURNINGSVIDEO_

// compile flag for this file
#undef USE_ZBUFFER
#undef IPOL_Z
#undef CMP_Z
#undef WRITE_Z

#undef IPOL_W
#undef CMP_W
#undef WRITE_W

#undef SUBTEXEL
#undef INVERSE_W

#undef IPOL_C0
#undef IPOL_C1
#undef IPOL_C1_FOG
#undef IPOL_T0
#undef IPOL_T1

// define render case
#define SUBTEXEL
#define INVERSE_W

#define USE_ZBUFFER
#define IPOL_W
#define CMP_W
#define WRITE_W

#define IPOL_C0
#define IPOL_C1
#define IPOL_T0
#define IPOL_T1

// apply global override
#ifndef SOFTWARE_DRIVER_2_PERSPECTIVE_CORRECT
#undef INVERSE_W
#endif

#ifndef SOFTWARE_DRIVER_2_SUBTEXEL
#undef SUBTEXEL
#endif

#if BURNING_MATERIAL_MAX_COLORS < 1
#undef IPOL_C0
#endif

#if BURNING_MATERIAL_MAX_COLORS < 2
#undef IPOL_C1
#endif


#if !defined ( SOFTWARE_DRIVER_2_USE_WBUFFER ) && defined ( USE_ZBUFFER )
#ifndef SOFTWARE_DRIVER_2_PERSPECTIVE_CORRECT
#undef IPOL_W
#endif
#define IPOL_Z

#ifdef CMP_W
#undef CMP_W
#define CMP_Z
#endif

#ifdef WRITE_W
#undef WRITE_W
#define WRITE_Z
#endif

#endif

burning_namespace_start

class CTR_transparent_reflection_2_layer : public IBurningShader
{
public:

	//! constructor
	CTR_transparent_reflection_2_layer(CBurningVideoDriver* driver);

	//! draws an indexed triangle list
	virtual void drawTriangle(const s4DVertex* burning_restrict a, const s4DVertex* burning_restrict b, const s4DVertex* burning_restrict c) override;
	virtual void OnSetMaterialBurning(const SBurningShaderMaterial& material) override;

private:
	void fragmentShader();

	E_MATERIAL_TYPE MaterialType;

};

//! constructor
CTR_transparent_reflection_2_layer::CTR_transparent_reflection_2_layer(CBurningVideoDriver* driver)
	: IBurningShader(driver, EMT_REFLECTION_2_LAYER)
{
#ifdef _DEBUG
	setDebugName("CTR_transparent_reflection_2_layer");
#endif
}

void CTR_transparent_reflection_2_layer::OnSetMaterialBurning(const SBurningShaderMaterial& material)
{
	MaterialType = material.org.MaterialType;

}

/*!
*/
void CTR_transparent_reflection_2_layer::fragmentShader()
{
	tVideoSample* dst;

#ifdef USE_ZBUFFER
	fp24* z;
#endif

	s32 xStart;
	s32 xEnd;
	s32 dx;


#ifdef SUBTEXEL
	f32 subPixel;
#endif

#ifdef IPOL_Z
	f32 slopeZ;
#endif
#ifdef IPOL_W
	fp24 slopeW;
#endif
#ifdef IPOL_C0
	sVec4 slopeC[BURNING_MATERIAL_MAX_COLORS];
#endif
#ifdef IPOL_T0
	sVec2 slopeT[BURNING_MATERIAL_MAX_TEXTURES];
#endif

	// apply top-left fill-convention, left
	xStart = fill_convention_left(line.x[0]);
	xEnd = fill_convention_right(line.x[1]);

	dx = xEnd - xStart;

	if (dx < 0)
		return;

	// slopes
	const f32 invDeltaX = fill_step_x(line.x[1] - line.x[0]);

#ifdef IPOL_Z
	slopeZ = (line.z[1] - line.z[0]) * invDeltaX;
#endif
#ifdef IPOL_W
	slopeW = (line.w[1] - line.w[0]) * invDeltaX;
#endif
#ifdef IPOL_C0
	slopeC[0] = (line.c[0][1] - line.c[0][0]) * invDeltaX;
#endif
#ifdef IPOL_C1
	slopeC[1] = (line.c[1][1] - line.c[1][0]) * invDeltaX;
#endif
#ifdef IPOL_T0
	slopeT[0] = (line.t[0][1] - line.t[0][0]) * invDeltaX;
#endif
#ifdef IPOL_T1
	slopeT[1] = (line.t[1][1] - line.t[1][0]) * invDeltaX;
#endif

#ifdef SUBTEXEL
	subPixel = ((f32)xStart) - line.x[0];
#ifdef IPOL_Z
	line.z[0] += slopeZ * subPixel;
#endif
#ifdef IPOL_W
	line.w[0] += slopeW * subPixel;
#endif
#ifdef IPOL_C0
	line.c[0][0] += slopeC[0] * subPixel;
#endif
#ifdef IPOL_C1
	line.c[1][0] += slopeC[1] * subPixel;
#endif
#ifdef IPOL_T0
	line.t[0][0] += slopeT[0] * subPixel;
#endif
#ifdef IPOL_T1
	line.t[1][0] += slopeT[1] * subPixel;
#endif
#endif

	SOFTWARE_DRIVER_2_CLIPCHECK;
	dst = (tVideoSample*)RenderTarget->getData() + (line.y * RenderTarget->getDimension().Width) + xStart;

#ifdef USE_ZBUFFER
	z = (fp24*)DepthBuffer->lock() + (line.y * RenderTarget->getDimension().Width) + xStart;
#endif


	f32 inversew = FIX_POINT_F32_MUL;

	tFixPoint r0, g0, b0;
	tFixPoint r1, g1, b1;

#ifdef IPOL_C0
	tFixPoint a1;
#endif

#ifdef IPOL_C1_FOG
	tFixPoint aFog = FIX_POINT_ONE;
#endif

	switch (MaterialType) {
	default:
	case EMT_REFLECTION_2_LAYER:
		for (s32 i = 0; i <= dx; i += SOFTWARE_DRIVER_2_STEP_X)
		{
#ifdef CMP_Z
			if (line.z[0] < z[i])
#endif
#ifdef CMP_W
				if (line.w[0] >= z[i])
#endif
				{

#ifdef INVERSE_W
					inversew = fix_inverse32(line.w[0]);
#endif

#ifdef IPOL_C1_FOG
					//complete inside fog
					if (TL_Flag & TL_FOG)
					{
						aFog = tofix(line.c[1][0].a, inversew);
						if (aFog <= 0)
						{
							dst[i] = fog_color_sample;
							continue;
						}
					}
#endif

					getSample_texture(r0, g0, b0, &IT[0], tofix(line.t[0][0].x, inversew), tofix(line.t[0][0].y, inversew));
					getSample_texture(r1, g1, b1, &IT[1], tofix(line.t[1][0].x, inversew), tofix(line.t[1][0].y, inversew));

					r0 = imulFix_tex1(r0, r1);
					g0 = imulFix_tex1(g0, g1);
					b0 = imulFix_tex1(b0, b1);

#ifdef IPOL_C0
					vec4_to_fix(r1, g1, b1, line.c[0][0], inversew);
					r0 = imulFix_simple(r1, r0);
					g0 = imulFix_simple(g1, g0);
					b0 = imulFix_simple(b1, b0);
#endif

#ifdef IPOL_C1

					//specular highlight
					if (TL_Flag & TL_SPECULAR)
					{
						vec4_to_fix(r1, g1, b1, line.c[1][0], inversew * COLOR_MAX);
						r0 = clampfix_maxcolor(r1 + r0);
						g0 = clampfix_maxcolor(g1 + g0);
						b0 = clampfix_maxcolor(b1 + b0);
					}
#endif
#ifdef IPOL_C1_FOG
					//mix with distance
					if (aFog < FIX_POINT_ONE) //TL_Flag & TL_FOG)
					{
						r0 = fog_color[1] + imulFix(aFog, r0 - fog_color[1]);
						g0 = fog_color[2] + imulFix(aFog, g0 - fog_color[2]);
						b0 = fog_color[3] + imulFix(aFog, b0 - fog_color[3]);
					}
#endif


					dst[i] = fix_to_sample(r0, g0, b0);

#ifdef WRITE_Z
					z[i] = line.z[0];
#endif
#ifdef WRITE_W
					z[i] = line.w[0];
#endif
				}

#ifdef IPOL_Z
			line.z[0] += slopeZ;
#endif
#ifdef IPOL_W
			line.w[0] += slopeW;
#endif
#ifdef IPOL_C0
			line.c[0][0] += slopeC[0];
#endif
#ifdef IPOL_C1
			line.c[1][0] += slopeC[1];
#endif
#ifdef IPOL_T0
			line.t[0][0] += slopeT[0];
#endif
#ifdef IPOL_T1
			line.t[1][0] += slopeT[1];
#endif
		}
		break;

	case EMT_TRANSPARENT_REFLECTION_2_LAYER:
		for (s32 i = 0; i <= dx; i += SOFTWARE_DRIVER_2_STEP_X)
		{
#ifdef CMP_Z
			if (line.z[0] < z[i])
#endif
#ifdef CMP_W
				if (line.w[0] >= z[i])
#endif
				{

#ifdef INVERSE_W
					inversew = fix_inverse32(line.w[0]);
#endif

					getSample_texture(r0, g0, b0, &IT[0], tofix(line.t[0][0].x, inversew), tofix(line.t[0][0].y, inversew));
					getSample_texture(r1, g1, b1, &IT[1], tofix(line.t[1][0].x, inversew), tofix(line.t[1][0].y, inversew));

					r0 = imulFix_tex1(r0, r1);
					g0 = imulFix_tex1(g0, g1);
					b0 = imulFix_tex1(b0, b1);

#ifdef IPOL_C0
					vec4_to_fix(a1, r1, g1, b1, line.c[0][0], inversew);
					r0 = imulFix_simple(r1, r0);
					g0 = imulFix_simple(g1, g0);
					b0 = imulFix_simple(b1, b0);

					//vertex alpha blend EMT_TRANSPARENT_REFLECTION_2_LAYER
					if (a1 + 2 < FIX_POINT_ONE)
					{
						color_to_fix(r1, g1, b1, dst[i]);
						r0 = r1 + imulFix(a1, r0 - r1);
						g0 = g1 + imulFix(a1, g0 - g1);
						b0 = b1 + imulFix(a1, b0 - b1);
					}
#endif

					dst[i] = fix_to_sample(r0, g0, b0);

#ifdef WRITE_Z
					//z[i] = line.z[0];
#endif
#ifdef WRITE_W
		//z[i] = line.w[0];
#endif
				}

#ifdef IPOL_Z
			line.z[0] += slopeZ;
#endif
#ifdef IPOL_W
			line.w[0] += slopeW;
#endif
#ifdef IPOL_C0
			line.c[0][0] += slopeC[0];
#endif
#ifdef IPOL_C1
			line.c[1][0] += slopeC[1];
#endif
#ifdef IPOL_T0
			line.t[0][0] += slopeT[0];
#endif
#ifdef IPOL_T1
			line.t[1][0] += slopeT[1];
#endif
		}
		break;

	}


}

void CTR_transparent_reflection_2_layer::drawTriangle(const s4DVertex* burning_restrict a, const s4DVertex* burning_restrict b, const s4DVertex* burning_restrict c)
{
	// sort on height, y
	if (F32_A_GREATER_B(a->Pos.y, b->Pos.y)) swapVertexPointer(&a, &b);
	if (F32_A_GREATER_B(b->Pos.y, c->Pos.y)) swapVertexPointer(&b, &c);
	if (F32_A_GREATER_B(a->Pos.y, b->Pos.y)) swapVertexPointer(&a, &b);

	const f32 ca = c->Pos.y - a->Pos.y;
	const f32 ba = b->Pos.y - a->Pos.y;
	const f32 cb = c->Pos.y - b->Pos.y;
	// calculate delta y of the edges
	scan.invDeltaY[0] = fill_step_y(ca);
	scan.invDeltaY[1] = fill_step_y(ba);
	scan.invDeltaY[2] = fill_step_y(cb);

	if (F32_LOWER_EQUAL_0(scan.invDeltaY[0]))
		return;

	// find if the major edge is left or right aligned
	f32 temp[4];

	temp[0] = a->Pos.x - c->Pos.x;
	temp[1] = -ca;
	temp[2] = b->Pos.x - a->Pos.x;
	temp[3] = ba;

	scan.left = (temp[0] * temp[3] - temp[1] * temp[2]) < 0.f ? 1 : 0;
	scan.right = 1 - scan.left;

	// calculate slopes for the major edge
	scan.slopeX[0] = (c->Pos.x - a->Pos.x) * scan.invDeltaY[0];
	scan.x[0] = a->Pos.x;

#ifdef IPOL_Z
	scan.slopeZ[0] = (c->Pos.z - a->Pos.z) * scan.invDeltaY[0];
	scan.z[0] = a->Pos.z;
#endif

#ifdef IPOL_W
	scan.slopeW[0] = (c->Pos.w - a->Pos.w) * scan.invDeltaY[0];
	scan.w[0] = a->Pos.w;
#endif

#ifdef IPOL_C0
	scan.slopeC[0][0] = (c->Color[0] - a->Color[0]) * scan.invDeltaY[0];
	scan.c[0][0] = a->Color[0];
#endif

#ifdef IPOL_C1
	scan.slopeC[1][0] = (c->Color[1] - a->Color[1]) * scan.invDeltaY[0];
	scan.c[1][0] = a->Color[1];
#endif

#ifdef IPOL_T0
	scan.slopeT[0][0] = (c->Tex[0] - a->Tex[0]) * scan.invDeltaY[0];
	scan.t[0][0] = a->Tex[0];
#endif

#ifdef IPOL_T1
	scan.slopeT[1][0] = (c->Tex[1] - a->Tex[1]) * scan.invDeltaY[0];
	scan.t[1][0] = a->Tex[1];
#endif

	// top left fill convention y run
	s32 yStart;
	s32 yEnd;

#ifdef SUBTEXEL
	f32 subPixel;
#endif

	// rasterize upper sub-triangle
	if (F32_GREATER_0(scan.invDeltaY[1]))
	{
		// calculate slopes for top edge
		scan.slopeX[1] = (b->Pos.x - a->Pos.x) * scan.invDeltaY[1];
		scan.x[1] = a->Pos.x;

#ifdef IPOL_Z
		scan.slopeZ[1] = (b->Pos.z - a->Pos.z) * scan.invDeltaY[1];
		scan.z[1] = a->Pos.z;
#endif

#ifdef IPOL_W
		scan.slopeW[1] = (b->Pos.w - a->Pos.w) * scan.invDeltaY[1];
		scan.w[1] = a->Pos.w;
#endif

#ifdef IPOL_C0
		scan.slopeC[0][1] = (b->Color[0] - a->Color[0]) * scan.invDeltaY[1];
		scan.c[0][1] = a->Color[0];
#endif

#ifdef IPOL_C1
		scan.slopeC[1][1] = (b->Color[1] - a->Color[1]) * scan.invDeltaY[1];
		scan.c[1][1] = a->Color[1];
#endif

#ifdef IPOL_T0
		scan.slopeT[0][1] = (b->Tex[0] - a->Tex[0]) * scan.invDeltaY[1];
		scan.t[0][1] = a->Tex[0];
#endif

#ifdef IPOL_T1
		scan.slopeT[1][1] = (b->Tex[1] - a->Tex[1]) * scan.invDeltaY[1];
		scan.t[1][1] = a->Tex[1];
#endif

		// apply top-left fill convention, top part
		yStart = fill_convention_top(a->Pos.y);
		yEnd = fill_convention_down(b->Pos.y);

#ifdef SUBTEXEL
		subPixel = ((f32)yStart) - a->Pos.y;

		// correct to pixel center
		scan.x[0] += scan.slopeX[0] * subPixel;
		scan.x[1] += scan.slopeX[1] * subPixel;

#ifdef IPOL_Z
		scan.z[0] += scan.slopeZ[0] * subPixel;
		scan.z[1] += scan.slopeZ[1] * subPixel;
#endif

#ifdef IPOL_W
		scan.w[0] += scan.slopeW[0] * subPixel;
		scan.w[1] += scan.slopeW[1] * subPixel;
#endif

#ifdef IPOL_C0
		scan.c[0][0] += scan.slopeC[0][0] * subPixel;
		scan.c[0][1] += scan.slopeC[0][1] * subPixel;
#endif

#ifdef IPOL_C1
		scan.c[1][0] += scan.slopeC[1][0] * subPixel;
		scan.c[1][1] += scan.slopeC[1][1] * subPixel;
#endif

#ifdef IPOL_T0
		scan.t[0][0] += scan.slopeT[0][0] * subPixel;
		scan.t[0][1] += scan.slopeT[0][1] * subPixel;
#endif

#ifdef IPOL_T1
		scan.t[1][0] += scan.slopeT[1][0] * subPixel;
		scan.t[1][1] += scan.slopeT[1][1] * subPixel;
#endif

#endif

		// rasterize the edge scanlines
		for (line.y = yStart; line.y <= yEnd; line.y += SOFTWARE_DRIVER_2_STEP_Y)
		{
			line.x[scan.left] = scan.x[0];
			line.x[scan.right] = scan.x[1];

#ifdef IPOL_Z
			line.z[scan.left] = scan.z[0];
			line.z[scan.right] = scan.z[1];
#endif

#ifdef IPOL_W
			line.w[scan.left] = scan.w[0];
			line.w[scan.right] = scan.w[1];
#endif

#ifdef IPOL_C0
			line.c[0][scan.left] = scan.c[0][0];
			line.c[0][scan.right] = scan.c[0][1];
#endif

#ifdef IPOL_C1
			line.c[1][scan.left] = scan.c[1][0];
			line.c[1][scan.right] = scan.c[1][1];
#endif

#ifdef IPOL_T0
			line.t[0][scan.left] = scan.t[0][0];
			line.t[0][scan.right] = scan.t[0][1];
#endif

#ifdef IPOL_T1
			line.t[1][scan.left] = scan.t[1][0];
			line.t[1][scan.right] = scan.t[1][1];
#endif

			// render a scanline
			if_interlace_scanline
				fragmentShader();

			scan.x[0] += scan.slopeX[0];
			scan.x[1] += scan.slopeX[1];

#ifdef IPOL_Z
			scan.z[0] += scan.slopeZ[0];
			scan.z[1] += scan.slopeZ[1];
#endif

#ifdef IPOL_W
			scan.w[0] += scan.slopeW[0];
			scan.w[1] += scan.slopeW[1];
#endif

#ifdef IPOL_C0
			scan.c[0][0] += scan.slopeC[0][0];
			scan.c[0][1] += scan.slopeC[0][1];
#endif

#ifdef IPOL_C1
			scan.c[1][0] += scan.slopeC[1][0];
			scan.c[1][1] += scan.slopeC[1][1];
#endif

#ifdef IPOL_T0
			scan.t[0][0] += scan.slopeT[0][0];
			scan.t[0][1] += scan.slopeT[0][1];
#endif

#ifdef IPOL_T1
			scan.t[1][0] += scan.slopeT[1][0];
			scan.t[1][1] += scan.slopeT[1][1];
#endif

		}
	}

	// rasterize lower sub-triangle
	if (F32_GREATER_0(scan.invDeltaY[2]))
	{
		// advance to middle point
		if (F32_GREATER_0(scan.invDeltaY[1]))
		{
			temp[0] = b->Pos.y - a->Pos.y;	// dy

			scan.x[0] = a->Pos.x + scan.slopeX[0] * temp[0];
#ifdef IPOL_Z
			scan.z[0] = a->Pos.z + scan.slopeZ[0] * temp[0];
#endif
#ifdef IPOL_W
			scan.w[0] = a->Pos.w + scan.slopeW[0] * temp[0];
#endif
#ifdef IPOL_C0
			scan.c[0][0] = a->Color[0] + scan.slopeC[0][0] * temp[0];
#endif
#ifdef IPOL_C1
			scan.c[1][0] = a->Color[1] + scan.slopeC[1][0] * temp[0];
#endif
#ifdef IPOL_T0
			scan.t[0][0] = a->Tex[0] + scan.slopeT[0][0] * temp[0];
#endif
#ifdef IPOL_T1
			scan.t[1][0] = a->Tex[1] + scan.slopeT[1][0] * temp[0];
#endif

		}

		// calculate slopes for bottom edge
		scan.slopeX[1] = (c->Pos.x - b->Pos.x) * scan.invDeltaY[2];
		scan.x[1] = b->Pos.x;

#ifdef IPOL_Z
		scan.slopeZ[1] = (c->Pos.z - b->Pos.z) * scan.invDeltaY[2];
		scan.z[1] = b->Pos.z;
#endif

#ifdef IPOL_W
		scan.slopeW[1] = (c->Pos.w - b->Pos.w) * scan.invDeltaY[2];
		scan.w[1] = b->Pos.w;
#endif

#ifdef IPOL_C0
		scan.slopeC[0][1] = (c->Color[0] - b->Color[0]) * scan.invDeltaY[2];
		scan.c[0][1] = b->Color[0];
#endif

#ifdef IPOL_C1
		scan.slopeC[1][1] = (c->Color[1] - b->Color[1]) * scan.invDeltaY[2];
		scan.c[1][1] = b->Color[1];
#endif

#ifdef IPOL_T0
		scan.slopeT[0][1] = (c->Tex[0] - b->Tex[0]) * scan.invDeltaY[2];
		scan.t[0][1] = b->Tex[0];
#endif

#ifdef IPOL_T1
		scan.slopeT[1][1] = (c->Tex[1] - b->Tex[1]) * scan.invDeltaY[2];
		scan.t[1][1] = b->Tex[1];
#endif

		// apply top-left fill convention, top part
		yStart = fill_convention_top(b->Pos.y);
		yEnd = fill_convention_down(c->Pos.y);

#ifdef SUBTEXEL

		subPixel = ((f32)yStart) - b->Pos.y;

		// correct to pixel center
		scan.x[0] += scan.slopeX[0] * subPixel;
		scan.x[1] += scan.slopeX[1] * subPixel;

#ifdef IPOL_Z
		scan.z[0] += scan.slopeZ[0] * subPixel;
		scan.z[1] += scan.slopeZ[1] * subPixel;
#endif

#ifdef IPOL_W
		scan.w[0] += scan.slopeW[0] * subPixel;
		scan.w[1] += scan.slopeW[1] * subPixel;
#endif

#ifdef IPOL_C0
		scan.c[0][0] += scan.slopeC[0][0] * subPixel;
		scan.c[0][1] += scan.slopeC[0][1] * subPixel;
#endif

#ifdef IPOL_C1
		scan.c[1][0] += scan.slopeC[1][0] * subPixel;
		scan.c[1][1] += scan.slopeC[1][1] * subPixel;
#endif

#ifdef IPOL_T0
		scan.t[0][0] += scan.slopeT[0][0] * subPixel;
		scan.t[0][1] += scan.slopeT[0][1] * subPixel;
#endif

#ifdef IPOL_T1
		scan.t[1][0] += scan.slopeT[1][0] * subPixel;
		scan.t[1][1] += scan.slopeT[1][1] * subPixel;
#endif

#endif

		// rasterize the edge scanlines
		for (line.y = yStart; line.y <= yEnd; line.y += SOFTWARE_DRIVER_2_STEP_Y)
		{
			line.x[scan.left] = scan.x[0];
			line.x[scan.right] = scan.x[1];

#ifdef IPOL_Z
			line.z[scan.left] = scan.z[0];
			line.z[scan.right] = scan.z[1];
#endif

#ifdef IPOL_W
			line.w[scan.left] = scan.w[0];
			line.w[scan.right] = scan.w[1];
#endif

#ifdef IPOL_C0
			line.c[0][scan.left] = scan.c[0][0];
			line.c[0][scan.right] = scan.c[0][1];
#endif

#ifdef IPOL_C1
			line.c[1][scan.left] = scan.c[1][0];
			line.c[1][scan.right] = scan.c[1][1];
#endif

#ifdef IPOL_T0
			line.t[0][scan.left] = scan.t[0][0];
			line.t[0][scan.right] = scan.t[0][1];
#endif

#ifdef IPOL_T1
			line.t[1][scan.left] = scan.t[1][0];
			line.t[1][scan.right] = scan.t[1][1];
#endif

			// render a scanline
			if_interlace_scanline
				fragmentShader();

			scan.x[0] += scan.slopeX[0];
			scan.x[1] += scan.slopeX[1];

#ifdef IPOL_Z
			scan.z[0] += scan.slopeZ[0];
			scan.z[1] += scan.slopeZ[1];
#endif

#ifdef IPOL_W
			scan.w[0] += scan.slopeW[0];
			scan.w[1] += scan.slopeW[1];
#endif

#ifdef IPOL_C0
			scan.c[0][0] += scan.slopeC[0][0];
			scan.c[0][1] += scan.slopeC[0][1];
#endif

#ifdef IPOL_C1
			scan.c[1][0] += scan.slopeC[1][0];
			scan.c[1][1] += scan.slopeC[1][1];
#endif

#ifdef IPOL_T0
			scan.t[0][0] += scan.slopeT[0][0];
			scan.t[0][1] += scan.slopeT[0][1];
#endif

#ifdef IPOL_T1
			scan.t[1][0] += scan.slopeT[1][0];
			scan.t[1][1] += scan.slopeT[1][1];
#endif

		}
	}

}


burning_namespace_end

#endif // _NIRT_COMPILE_WITH_BURNINGSVIDEO_

burning_namespace_start

//! creates a flat triangle renderer
IBurningShader* createTriangleRendererTexture_transparent_reflection_2_layer(CBurningVideoDriver* driver)
{
	/*
	ETR_TRANSPARENT_REFLECTION_2_LAYER
	Nirtcpp EMT_REFLECTION_2_LAYER,EMT_TRANSPARENT_REFLECTION_2_LAYER
	*/
#ifdef _NIRT_COMPILE_WITH_BURNINGSVIDEO_
	return new CTR_transparent_reflection_2_layer(driver);
#else
	return 0;
#endif // _NIRT_COMPILE_WITH_BURNINGSVIDEO_
}


burning_namespace_end


