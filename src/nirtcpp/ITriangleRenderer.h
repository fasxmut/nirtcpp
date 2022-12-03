// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_I_TRIANGLE_RENDERER_H_INCLUDED
#define NIRT_I_TRIANGLE_RENDERER_H_INCLUDED

#include "IReferenceCounted.h"
#include "S2DVertex.h"
#include "rect.h"
#include "IZBuffer.h"

namespace irr
{
namespace video
{
	class IImage;

	enum ETriangleRenderer
	{
		ETR_FLAT = 0,
		ETR_FLAT_WIRE,
		ETR_GOURAUD,
		ETR_GOURAUD_WIRE,
		ETR_TEXTURE_FLAT,
		ETR_TEXTURE_FLAT_WIRE,
		ETR_TEXTURE_GOURAUD,
		ETR_TEXTURE_GOURAUD_WIRE,
		ETR_TEXTURE_GOURAUD_NOZ,
		ETR_TEXTURE_GOURAUD_ADD,
		ETR_COUNT
	};

	class ITriangleRenderer : public virtual IReferenceCounted
	{
	public:

		//! sets a render target
		virtual void setRenderTarget(video::IImage* surface, const core::rect<s32>& viewPort) = 0;

		//! en or disables the backface culling
		virtual void setBackfaceCulling(bool enabled = true) = 0;

		//! sets the Texture
		virtual void setTexture(video::IImage* texture) = 0;

		//! draws an indexed triangle list
		virtual void drawIndexedTriangleList(S2DVertex* vertices, s32 vertexCount, const u16* indexList, s32 triangleCount) = 0;
	};


	ITriangleRenderer* createTriangleRendererTextureGouraud(IZBuffer* zbuffer);
	ITriangleRenderer* createTriangleRendererTextureGouraudWire(IZBuffer* zbuffer);
	ITriangleRenderer* createTriangleRendererGouraud(IZBuffer* zbuffer);
	ITriangleRenderer* createTriangleRendererGouraudWire(IZBuffer* zbuffer);
	ITriangleRenderer* createTriangleRendererTextureFlat(IZBuffer* zbuffer);
	ITriangleRenderer* createTriangleRendererTextureFlatWire(IZBuffer* zbuffer);
	ITriangleRenderer* createTriangleRendererFlat(IZBuffer* zbuffer);
	ITriangleRenderer* createTriangleRendererFlatWire(IZBuffer* zbuffer);
	ITriangleRenderer* createTriangleRendererTextureGouraudNoZ();
	ITriangleRenderer* createTriangleRendererTextureGouraudAdd(IZBuffer* zbuffer);


} // end namespace video
} // end namespace irr

#endif
