// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_D3D9_HLSL_MATERIAL_RENDERER_H_INCLUDED
#define NIRT_C_D3D9_HLSL_MATERIAL_RENDERER_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>
#ifdef _NIRT_WINDOWS_

#ifdef _NIRT_COMPILE_WITH_DIRECT3D_9_

#include "CD3D9ShaderMaterialRenderer.hpp"
#include <nirtcpp/IGPUProgrammingServices.hpp>

namespace nirt
{
namespace video
{

class IVideoDriver;
class IShaderConstantSetCallBack;
class IMaterialRenderer;

//! Class for using vertex and pixel shaders via HLSL with D3D9
class CD3D9HLSLMaterialRenderer : public CD3D9ShaderMaterialRenderer
{
public:

	//! Public constructor
	CD3D9HLSLMaterialRenderer(IDirect3DDevice9* d3ddev, video::IVideoDriver* driver,
		s32& outMaterialTypeNr,
		const c8* vertexShaderProgram,
		const c8* vertexShaderEntryPointName,
		E_VERTEX_SHADER_TYPE vsCompileTarget,
		const c8* pixelShaderProgram,
		const c8* pixelShaderEntryPointName,
		E_PIXEL_SHADER_TYPE psCompileTarget,
		IShaderConstantSetCallBack* callback,
		IMaterialRenderer* baseMaterial,
		s32 userData);

	//! Destructor
	~CD3D9HLSLMaterialRenderer();

	virtual s32 getVariableID(bool vertexShader, const c8* name);

	//! sets a variable in the shader.
	//! \param vertexShader: True if this should be set in the vertex shader, false if
	//! in the pixel shader.
	//! \param index: Index of the variable
	//! \param floats: Pointer to array of floats
	//! \param count: Amount of floats in array.
	virtual bool setVariable(bool vertexShader, s32 index, const f32* floats, int count);

	//! Int interface for the above.
	virtual bool setVariable(bool vertexShader, s32 index, const s32* ints, int count);

	//! Uint interface for the above.
	virtual bool setVariable(bool vertexShader, s32 index, const u32* ints, int count);

	bool OnRender(IMaterialRendererServices* service, E_VERTEX_TYPE vtxtype) override;

protected:

	bool createHLSLVertexShader(const char* vertexShaderProgram,
		const char* shaderEntryPointName,
		const char* shaderTargetName);

	bool createHLSLPixelShader(const char* pixelShaderProgram,
		const char* shaderEntryPointName,
		const char* shaderTargetName);

	void printHLSLVariables(LPD3DXCONSTANTTABLE table);

	LPD3DXCONSTANTTABLE VSConstantsTable;
	LPD3DXCONSTANTTABLE PSConstantsTable;
};


} // end namespace video
} // end namespace nirt

#endif
#endif
#endif
