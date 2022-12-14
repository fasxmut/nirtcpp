// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#include "CTRTextureGouraud.hpp"

#ifdef _NIRT_COMPILE_WITH_SOFTWARE_

namespace nirt
{
namespace video
{

//! constructor
CTRTextureGouraud::CTRTextureGouraud(IZBuffer* zbuffer)
	: RenderTarget(0), ZBuffer(zbuffer), SurfaceWidth(0), SurfaceHeight(0),
		BackFaceCullingEnabled(true), lockedZBuffer(0),
		lockedSurface(0), lockedTexture(0), lockedTextureWidth(0),
		textureXMask(0), textureYMask(0), Texture(0)
{
	#ifdef _DEBUG
	setDebugName("CTRTextureGouraud");
	#endif

	if (ZBuffer)
		zbuffer->grab();
}



//! destructor
CTRTextureGouraud::~CTRTextureGouraud()
{
	if (RenderTarget)
		RenderTarget->drop();

	if (ZBuffer)
		ZBuffer->drop();

	if (Texture)
		Texture->drop();
}



//! sets the Texture
void CTRTextureGouraud::setTexture(video::IImage* texture)
{
	if (Texture)
		Texture->drop();

	Texture = texture;

	if (Texture)
	{
		Texture->grab();
		lockedTextureWidth = Texture->getDimension().Width;

		textureXMask = lockedTextureWidth-1;
		textureYMask = Texture->getDimension().Height-1;
	}
}




//! en or disables the backface culling
void CTRTextureGouraud::setBackfaceCulling(bool enabled)
{
	BackFaceCullingEnabled = enabled;
}



//! sets a render target
void CTRTextureGouraud::setRenderTarget(video::IImage* surface, const core::rect<s32>& viewPort)
{
	if (RenderTarget)
		RenderTarget->drop();

	RenderTarget = surface;

	if (RenderTarget)
	{
		SurfaceWidth = RenderTarget->getDimension().Width;
		SurfaceHeight = RenderTarget->getDimension().Height;
		RenderTarget->grab();
		ViewPortRect = viewPort;
	}
}



//! draws an indexed triangle list
void CTRTextureGouraud::drawIndexedTriangleList(S2DVertex* vertices, s32 vertexCount, const u16* indexList, s32 triangleCount)
{
	const S2DVertex *v1, *v2, *v3;

	f32 tmpDiv; // temporary division factor
	f32 longest; // saves the longest span
	s32 height; // saves height of triangle
	u16* targetSurface; // target pointer where to plot pixels
	s32 spanEnd; // saves end of spans
	f32 leftdeltaxf; // amount of pixels to increase on left side of triangle
	f32 rightdeltaxf; // amount of pixels to increase on right side of triangle
	s32 leftx, rightx; // position where we are
	f32 leftxf, rightxf; // same as above, but as f32 values
	s32 span; // current span
	u16 *hSpanBegin, *hSpanEnd; // pointer used when plotting pixels
	s32 leftR, leftG, leftB, rightR, rightG, rightB; // color values
	s32 leftStepR, leftStepG, leftStepB,
		rightStepR, rightStepG, rightStepB; // color steps
	s32 spanR, spanG, spanB, spanStepR, spanStepG, spanStepB; // color interpolating values while drawing a span.
	s32 leftTx, rightTx, leftTy, rightTy; // texture interpolating values
	s32 leftTxStep, rightTxStep, leftTyStep, rightTyStep; // texture interpolating values
	s32 spanTx, spanTy, spanTxStep, spanTyStep; // values of Texturecoords when drawing a span
	core::rect<s32> TriangleRect;

	s32 leftZValue, rightZValue;
	s32 leftZStep, rightZStep;
	s32 spanZValue, spanZStep; // ZValues when drawing a span
	TZBufferType* zTarget, *spanZTarget; // target of ZBuffer;

	lockedSurface = (u16*)RenderTarget->getData();
	lockedZBuffer = ZBuffer->lock();
	lockedTexture = (u16*)Texture->getData();

	for (s32 i=0; i<triangleCount; ++i)
	{
		v1 = &vertices[*indexList];
		++indexList;
		v2 = &vertices[*indexList];
		++indexList;
		v3 = &vertices[*indexList];
		++indexList;

		// back face culling

		if (BackFaceCullingEnabled)
		{
			s32 z = ((v3->Pos.X - v1->Pos.X) * (v3->Pos.Y - v2->Pos.Y)) -
				((v3->Pos.Y - v1->Pos.Y) * (v3->Pos.X - v2->Pos.X));

			if (z < 0)
				continue;
		}

		//near plane clipping

		if (v1->ZValue<0 && v2->ZValue<0 && v3->ZValue<0)
			continue;

		// sort for width for inscreen clipping

		if (v1->Pos.X > v2->Pos.X)	swapVertices(&v1, &v2);
		if (v1->Pos.X > v3->Pos.X)	swapVertices(&v1, &v3);
		if (v2->Pos.X > v3->Pos.X)	swapVertices(&v2, &v3);

		if ((v1->Pos.X - v3->Pos.X) == 0)
			continue;

		TriangleRect.UpperLeftCorner.X = v1->Pos.X;
		TriangleRect.LowerRightCorner.X = v3->Pos.X;

		// sort for height for faster drawing.

		if (v1->Pos.Y > v2->Pos.Y)	swapVertices(&v1, &v2);
		if (v1->Pos.Y > v3->Pos.Y)	swapVertices(&v1, &v3);
		if (v2->Pos.Y > v3->Pos.Y)	swapVertices(&v2, &v3);

		TriangleRect.UpperLeftCorner.Y = v1->Pos.Y;
		TriangleRect.LowerRightCorner.Y = v3->Pos.Y;

		if (!TriangleRect.isRectCollided(ViewPortRect))
			continue;

		// calculate height of triangle
		height = v3->Pos.Y - v1->Pos.Y;
		if (!height)
			continue;

		// calculate longest span

		longest = (v2->Pos.Y - v1->Pos.Y) / (f32)height * (v3->Pos.X - v1->Pos.X) + (v1->Pos.X - v2->Pos.X);

		spanEnd = v2->Pos.Y;
		span = v1->Pos.Y;
		leftxf = (f32)v1->Pos.X;
		rightxf = (f32)v1->Pos.X;

		leftZValue = v1->ZValue;
		rightZValue = v1->ZValue;

		leftR = rightR = video::getRed(v1->Color)<<8;
		leftG = rightG = video::getGreen(v1->Color)<<8;
		leftB = rightB = video::getBlue(v1->Color)<<8;
		leftTx = rightTx = v1->TCoords.X;
		leftTy = rightTy = v1->TCoords.Y;

		targetSurface = lockedSurface + span * SurfaceWidth;
		zTarget = lockedZBuffer + span * SurfaceWidth;

		if (longest < 0.0f)
		{
			tmpDiv = 1.0f / (f32)(v2->Pos.Y - v1->Pos.Y);
			rightdeltaxf = (v2->Pos.X - v1->Pos.X) * tmpDiv;
			rightZStep = (s32)((v2->ZValue - v1->ZValue) * tmpDiv);
			rightStepR = (s32)(((s32)(video::getRed(v2->Color)<<8) - rightR) * tmpDiv);
			rightStepG = (s32)(((s32)(video::getGreen(v2->Color)<<8) - rightG) * tmpDiv);
			rightStepB = (s32)(((s32)(video::getBlue(v2->Color)<<8) - rightB) * tmpDiv);
			rightTxStep = (s32)((v2->TCoords.X - rightTx) * tmpDiv);
			rightTyStep = (s32)((v2->TCoords.Y - rightTy) * tmpDiv);

			tmpDiv = 1.0f / (f32)height;
			leftdeltaxf = (v3->Pos.X - v1->Pos.X) * tmpDiv;
			leftZStep = (s32)((v3->ZValue - v1->ZValue) * tmpDiv);
			leftStepR = (s32)(((s32)(video::getRed(v3->Color)<<8) - leftR) * tmpDiv);
			leftStepG = (s32)(((s32)(video::getGreen(v3->Color)<<8) - leftG) * tmpDiv);
			leftStepB = (s32)(((s32)(video::getBlue(v3->Color)<<8) - leftB) * tmpDiv);
			leftTxStep = (s32)((v3->TCoords.X - leftTx) * tmpDiv);
			leftTyStep = (s32)((v3->TCoords.Y - leftTy) * tmpDiv);
		}
		else
		{
			tmpDiv = 1.0f / (f32)height;
			rightdeltaxf = (v3->Pos.X - v1->Pos.X) * tmpDiv;
			rightZStep = (s32)((v3->ZValue - v1->ZValue) * tmpDiv);
			rightStepR = (s32)(((s32)(video::getRed(v3->Color)<<8) - rightR) * tmpDiv);
			rightStepG = (s32)(((s32)(video::getGreen(v3->Color)<<8) - rightG) * tmpDiv);
			rightStepB = (s32)(((s32)(video::getBlue(v3->Color)<<8) - rightB) * tmpDiv);
			rightTxStep = (s32)((v3->TCoords.X - rightTx) * tmpDiv);
			rightTyStep = (s32)((v3->TCoords.Y - rightTy) * tmpDiv);

			tmpDiv = 1.0f / (f32)(v2->Pos.Y - v1->Pos.Y);
			leftdeltaxf = (v2->Pos.X - v1->Pos.X) * tmpDiv;
			leftZStep = (s32)((v2->ZValue - v1->ZValue) * tmpDiv);
			leftStepR = (s32)(((s32)(video::getRed(v2->Color)<<8) - leftR) * tmpDiv);
			leftStepG = (s32)(((s32)(video::getGreen(v2->Color)<<8) - leftG) * tmpDiv);
			leftStepB = (s32)(((s32)(video::getBlue(v2->Color)<<8) - leftB) * tmpDiv);
			leftTxStep = (s32)((v2->TCoords.X - leftTx) * tmpDiv);
			leftTyStep = (s32)((v2->TCoords.Y - leftTy) * tmpDiv);
		}


		// do it twice, once for the first half of the triangle,
		// end then for the second half.

		for (s32 triangleHalf=0; triangleHalf<2; ++triangleHalf)
		{
			if (spanEnd > ViewPortRect.LowerRightCorner.Y)
				spanEnd = ViewPortRect.LowerRightCorner.Y;

			// if the span <0, than we can skip these spans,
			// and proceed to the next spans which are really on the screen.
			if (span < ViewPortRect.UpperLeftCorner.Y)
			{
				// we'll use leftx as temp variable
				if (spanEnd < ViewPortRect.UpperLeftCorner.Y)
				{
					leftx = spanEnd - span;
					span = spanEnd;
				}
				else
				{
					leftx = ViewPortRect.UpperLeftCorner.Y - span;
					span = ViewPortRect.UpperLeftCorner.Y;
				}

				leftxf += leftdeltaxf*leftx;
				rightxf += rightdeltaxf*leftx;
				targetSurface += SurfaceWidth*leftx;
				zTarget += SurfaceWidth*leftx;
				leftZValue += leftZStep*leftx;
				rightZValue += rightZStep*leftx;

				leftR += leftStepR*leftx;
				leftG += leftStepG*leftx;
				leftB += leftStepB*leftx;
				rightR += rightStepR*leftx;
				rightG += rightStepG*leftx;
				rightB += rightStepB*leftx;

				leftTx += leftTxStep*leftx;
				leftTy += leftTyStep*leftx;
				rightTx += rightTxStep*leftx;
				rightTy += rightTyStep*leftx;
			}


			// the main loop. Go through every span and draw it.

			while (span < spanEnd)
			{
				leftx = (s32)(leftxf);
				rightx = (s32)(rightxf + 0.5f);

				// perform some clipping
				// thanks to a correction by hybrid
                // calculations delayed to correctly propagate to textures etc.
				s32 tDiffLeft=0, tDiffRight=0;
				if (leftx<ViewPortRect.UpperLeftCorner.X)
					tDiffLeft=ViewPortRect.UpperLeftCorner.X-leftx;
				else
				if (leftx>ViewPortRect.LowerRightCorner.X)
					tDiffLeft=ViewPortRect.LowerRightCorner.X-leftx;

				if (rightx<ViewPortRect.UpperLeftCorner.X)
					tDiffRight=ViewPortRect.UpperLeftCorner.X-rightx;
				else
				if (rightx>ViewPortRect.LowerRightCorner.X)
					tDiffRight=ViewPortRect.LowerRightCorner.X-rightx;

				// draw the span
				if (rightx + tDiffRight - leftx - tDiffLeft)
				{
					tmpDiv = 1.0f / (f32)(rightx - leftx);
					spanZStep = (s32)((rightZValue - leftZValue) * tmpDiv);
					spanZValue = leftZValue+tDiffLeft*spanZStep;

					spanStepR = (s32)((rightR - leftR) * tmpDiv);
					spanR = leftR+tDiffLeft*spanStepR;
					spanStepG = (s32)((rightG - leftG) * tmpDiv);
					spanG = leftG+tDiffLeft*spanStepG;
					spanStepB = (s32)((rightB - leftB) * tmpDiv);
					spanB = leftB+tDiffLeft*spanStepB;

					spanTxStep = (s32)((rightTx - leftTx) * tmpDiv);
					spanTx = leftTx + tDiffLeft*spanTxStep;
					spanTyStep = (s32)((rightTy - leftTy) * tmpDiv);
					spanTy = leftTy+tDiffLeft*spanTyStep;

					hSpanBegin = targetSurface + leftx+tDiffLeft;
					spanZTarget = zTarget + leftx+tDiffLeft;
					hSpanEnd = targetSurface + rightx+tDiffRight;

					while (hSpanBegin < hSpanEnd)
					{
						if (spanZValue > *spanZTarget)
						{
							*spanZTarget = spanZValue;
							u16 color = lockedTexture[((spanTy>>8)&textureYMask) * lockedTextureWidth + ((spanTx>>8)&textureXMask)];
							*hSpanBegin = video::RGB16(video::getRed(color) * (spanR>>8) >>2,
									video::getGreen(color) * (spanG>>8) >>2,
									video::getBlue(color) * (spanB>>8) >>2);
						}

						spanR += spanStepR;
						spanG += spanStepG;
						spanB += spanStepB;

						spanTx += spanTxStep;
						spanTy += spanTyStep;

						spanZValue += spanZStep;
						++hSpanBegin;
						++spanZTarget;
					}
				}

				leftxf += leftdeltaxf;
				rightxf += rightdeltaxf;
				++span;
				targetSurface += SurfaceWidth;
				zTarget += SurfaceWidth;
				leftZValue += leftZStep;
				rightZValue += rightZStep;

				leftR += leftStepR;
				leftG += leftStepG;
				leftB += leftStepB;
				rightR += rightStepR;
				rightG += rightStepG;
				rightB += rightStepB;

				leftTx += leftTxStep;
				leftTy += leftTyStep;
				rightTx += rightTxStep;
				rightTy += rightTyStep;
			}

			if (triangleHalf>0) // break, we've gout only two halves
				break;


			// setup variables for second half of the triangle.

			if (longest < 0.0f)
			{
				tmpDiv = 1.0f / (v3->Pos.Y - v2->Pos.Y);

				rightdeltaxf = (v3->Pos.X - v2->Pos.X) * tmpDiv;
				rightxf = (f32)v2->Pos.X;

				rightZValue = v2->ZValue;
				rightZStep = (s32)((v3->ZValue - v2->ZValue) * tmpDiv);

				rightR = video::getRed(v2->Color)<<8;
				rightG = video::getGreen(v2->Color)<<8;
				rightB = video::getBlue(v2->Color)<<8;
				rightStepR = (s32)(((s32)(video::getRed(v3->Color)<<8) - rightR) * tmpDiv);
				rightStepG = (s32)(((s32)(video::getGreen(v3->Color)<<8) - rightG) * tmpDiv);
				rightStepB = (s32)(((s32)(video::getBlue(v3->Color)<<8) - rightB) * tmpDiv);

				rightTx = v2->TCoords.X;
				rightTy = v2->TCoords.Y;
				rightTxStep = (s32)((v3->TCoords.X - rightTx) * tmpDiv);
				rightTyStep = (s32)((v3->TCoords.Y - rightTy) * tmpDiv);
			}
			else
			{
				tmpDiv = 1.0f / (v3->Pos.Y - v2->Pos.Y);

				leftdeltaxf = (v3->Pos.X - v2->Pos.X) * tmpDiv;
				leftxf = (f32)v2->Pos.X;

				leftZValue = v2->ZValue;
				leftZStep = (s32)((v3->ZValue - v2->ZValue) * tmpDiv);

				leftR = video::getRed(v2->Color)<<8;
				leftG = video::getGreen(v2->Color)<<8;
				leftB = video::getBlue(v2->Color)<<8;
				leftStepR = (s32)(((s32)(video::getRed(v3->Color)<<8) - leftR) * tmpDiv);
				leftStepG = (s32)(((s32)(video::getGreen(v3->Color)<<8) - leftG) * tmpDiv);
				leftStepB = (s32)(((s32)(video::getBlue(v3->Color)<<8) - leftB) * tmpDiv);

				leftTx = v2->TCoords.X;
				leftTy = v2->TCoords.Y;
				leftTxStep = (s32)((v3->TCoords.X - leftTx) * tmpDiv);
				leftTyStep = (s32)((v3->TCoords.Y - leftTy) * tmpDiv);
			}


			spanEnd = v3->Pos.Y;
		}

	}

	ZBuffer->unlock();
}


} // end namespace video
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_SOFTWARE_

namespace nirt
{
namespace video
{

//! creates a flat triangle renderer
ITriangleRenderer* createTriangleRendererTextureGouraud(IZBuffer* zbuffer)
{
	#ifdef _NIRT_COMPILE_WITH_SOFTWARE_
	return new CTRTextureGouraud(zbuffer);
	#else
	return 0;
	#endif // _NIRT_COMPILE_WITH_SOFTWARE_
}


} // end namespace video
} // end namespace nirt


