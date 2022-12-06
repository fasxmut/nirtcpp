// Copyright (C) 2015 Patryk Nadrowski
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_OGLCORE_FEATURE_H_INCLUDED
#define NIRT_C_OGLCORE_FEATURE_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>

#if defined(_NIRT_COMPILE_WITH_OPENGL_) || defined(_NIRT_COMPILE_WITH_OGLES1_) || defined(_NIRT_COMPILE_WITH_OGLES2_)

#include <nirtcpp/irrTypes.hpp>

namespace nirt
{
namespace video
{

class COpenGLCoreFeature
{
public:
	COpenGLCoreFeature() : BlendOperation(false), ColorAttachment(0), MultipleRenderTarget(0), MaxTextureUnits(1)
	{
	}

	virtual ~COpenGLCoreFeature()
	{
	}

	bool BlendOperation;
	
	u8 ColorAttachment;
	u8 MultipleRenderTarget;
	u8 MaxTextureUnits;
};

}
}

#endif
#endif
