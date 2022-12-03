// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_I_PARTICLE_SPHERE_EMITTER_H_INCLUDED
#define NIRT_I_PARTICLE_SPHERE_EMITTER_H_INCLUDED

#include "IParticleEmitter.h"

namespace nirt
{
namespace scene
{

//! A particle emitter which emits from a spherical space.
class IParticleSphereEmitter : public IParticleEmitter
{
public:

	//! Set the center of the sphere for particle emissions
	virtual void setCenter( const core::vector3df& center ) = 0;

	//! Set the radius of the sphere for particle emissions
	virtual void setRadius( f32 radius ) = 0;

	//! Get the center of the sphere for particle emissions
	virtual const core::vector3df& getCenter() const = 0;

	//! Get the radius of the sphere for particle emissions
	virtual f32 getRadius() const = 0;

	//! Get emitter type
	virtual E_PARTICLE_EMITTER_TYPE getType() const override { return EPET_SPHERE; }
};

} // end namespace scene
} // end namespace nirt

#endif