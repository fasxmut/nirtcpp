// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_D3D9_PARALLAX_MAPMATERIAL_RENDERER_H_INCLUDED
#define NIRT_C_D3D9_PARALLAX_MAPMATERIAL_RENDERER_H_INCLUDED

#include "IrrCompileConfig.h"
#ifdef _NIRT_WINDOWS_

#ifdef _NIRT_COMPILE_WITH_DIRECT3D_9_
#if defined(__BORLANDC__) || defined (__BCPLUSPLUS__)
#include "irrMath.h"    // needed by borland for sqrtf define
#endif
#include <d3d9.h>

#include "CD3D9ShaderMaterialRenderer.h"
#include "IShaderConstantSetCallBack.h"

namespace irr
{
namespace video
{

//! Renderer for normal maps using parallax mapping
class CD3D9ParallaxMapRenderer :
	public CD3D9ShaderMaterialRenderer, IShaderConstantSetCallBack
{
public:

	CD3D9ParallaxMapRenderer(
		IDirect3DDevice9* d3ddev, video::IVideoDriver* driver,
		s32& outMaterialTypeNr, IMaterialRenderer* baseMaterial);

	~CD3D9ParallaxMapRenderer();

	//! Called by the engine when the vertex and/or pixel shader constants for an
	//! material renderer should be set.
	virtual void OnSetConstants(IMaterialRendererServices* services, s32 userData) override;

	virtual bool OnRender(IMaterialRendererServices* service, E_VERTEX_TYPE vtxtype) override;

	//! Returns the render capability of the material.
	virtual s32 getRenderCapability() const override;

	virtual void OnSetMaterial(const SMaterial& material) override { }
	virtual void OnSetMaterial(const video::SMaterial& material,
		const video::SMaterial& lastMaterial,
		bool resetAllRenderstates, video::IMaterialRendererServices* services) override;

private:

	f32 CurrentScale;

};

} // end namespace video
} // end namespace irr

#endif
#endif
#endif
