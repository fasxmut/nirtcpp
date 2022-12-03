// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_I_PARTICLE_FADE_OUT_AFFECTOR_H_INCLUDED
#define NIRT_I_PARTICLE_FADE_OUT_AFFECTOR_H_INCLUDED

#include "IParticleAffector.h"

namespace nirt
{
namespace scene
{

//! A particle affector which fades out the particles.
class IParticleFadeOutAffector : public IParticleAffector
{
public:

	//! Sets the targetColor, i.e. the color the particles will interpolate to over time.
	virtual void setTargetColor( const video::SColor& targetColor ) = 0;

	//! Sets the time in milliseconds it takes for each particle to fade out (minimal 1 ms)
	virtual void setFadeOutTime( u32 fadeOutTime ) = 0;

	//! Gets the targetColor, i.e. the color the particles will interpolate to over time.
	virtual const video::SColor& getTargetColor() const = 0;

	//! Gets the time in milliseconds it takes for each particle to fade out.
	virtual u32 getFadeOutTime() const = 0;

	//! Get emitter type
	virtual E_PARTICLE_AFFECTOR_TYPE getType() const override { return EPAT_FADE_OUT; }
};

} // end namespace scene
} // end namespace nirt

#endif // __I_PARTICLE_FADE_OUT_AFFECTOR_H_INCLUDED__
