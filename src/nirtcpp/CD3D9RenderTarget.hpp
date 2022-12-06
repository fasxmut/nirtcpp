// Copyright (C) 2015 Patryk Nadrowski
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_OPEN_GL_RENDER_TARGET_H_INCLUDED
#define NIRT_C_OPEN_GL_RENDER_TARGET_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>

#ifdef _NIRT_COMPILE_WITH_DIRECT3D_9_

#include <nirtcpp/IRenderTarget.hpp>

#include <nirtcpp/dimension2d.hpp>
#include "os.hpp"

#include <d3d9.h>

namespace nirt
{
	namespace video
	{

		class CD3D9Driver;

		class CD3D9RenderTarget : public IRenderTarget
		{
		public:
			CD3D9RenderTarget(CD3D9Driver* driver);
			virtual ~CD3D9RenderTarget();

			virtual void setTextures(ITexture* const * textures, u32 numTextures, ITexture* depthStencil, const E_CUBE_SURFACE* cubeSurfaces, u32 numCubeSurfaces) override;

			const core::dimension2d<u32>& getSize() const;

			IDirect3DSurface9* getSurface(u32 id) const;

			u32 getSurfaceCount() const;

			IDirect3DSurface9* getDepthStencilSurface() const;

			void releaseSurfaces();

			void generateSurfaces();

		protected:
			core::dimension2d<u32> Size;

			core::array<IDirect3DSurface9*> Surfaces;

			IDirect3DSurface9* DepthStencilSurface;

			CD3D9Driver* Driver;
		};

	}
}

#endif
#endif
