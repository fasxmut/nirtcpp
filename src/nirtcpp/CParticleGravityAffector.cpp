// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#include "CParticleGravityAffector.hpp"

#ifdef _NIRT_COMPILE_WITH_PARTICLES_

#include "os.hpp"
#include <nirtcpp/IAttributes.hpp>

namespace nirt
{
namespace scene
{

//! constructor
CParticleGravityAffector::CParticleGravityAffector(
	const core::vector3df& gravity, u32 timeForceLost)
	: IParticleGravityAffector(), TimeForceLost(static_cast<f32>(timeForceLost)), Gravity(gravity)
{
	#ifdef _DEBUG
	setDebugName("CParticleGravityAffector");
	#endif
}


//! Affects an array of particles.
void CParticleGravityAffector::affect(u32 now, SParticle* particlearray, u32 count)
{
	if (!Enabled)
		return;
	f32 d;

	for (u32 i=0; i<count; ++i)
	{
		d = (now - particlearray[i].startTime) / TimeForceLost;
		if (d > 1.0f)
			d = 1.0f;
		if (d < 0.0f)
			d = 0.0f;
		d = 1.0f - d;

		particlearray[i].vector = particlearray[i].startVector.getInterpolated(Gravity, d);
	}
}

//! Writes attributes of the object.
void CParticleGravityAffector::serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const
{
	out->addVector3d("Gravity", Gravity);
	out->addFloat("TimeForceLost", TimeForceLost);
}


//! Reads attributes of the object.
void CParticleGravityAffector::deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options)
{
	Gravity = in->getAttributeAsVector3d("Gravity");
	TimeForceLost = in->getAttributeAsFloat("TimeForceLost");
}



} // end namespace scene
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_PARTICLES_
