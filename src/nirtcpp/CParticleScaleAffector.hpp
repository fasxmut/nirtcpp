// Copyright (C) 2010-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef C_PARTICLE_SCALE_AFFECTOR_H
#define C_PARTICLE_SCALE_AFFECTOR_H

#include <nirtcpp/IrrCompileConfig.hpp>
#ifdef _NIRT_COMPILE_WITH_PARTICLES_

#include <nirtcpp/IParticleAffector.hpp>

namespace nirt
{
	namespace scene
	{
		class CParticleScaleAffector : public IParticleAffector
		{
		public:
			CParticleScaleAffector(const core::dimension2df& scaleTo = core::dimension2df(1.0f, 1.0f));

			virtual void affect(u32 now, SParticle *particlearray, u32 count) override;

			//! Writes attributes of the object.
			//! Implement this to expose the attributes of your scene node animator for
			//! scripting languages, editors, debuggers or xml serialization purposes.
			virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const override;

			//! Reads attributes of the object.
			//! Implement this to set the attributes of your scene node animator for
			//! scripting languages, editors, debuggers or xml deserialization purposes.
			//! \param startIndex: start index where to start reading attributes.
			//! \return: returns last index of an attribute read by this affector
			virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options) override;

			//! Get emitter type
			virtual E_PARTICLE_AFFECTOR_TYPE getType() const override;

		protected:
			core::dimension2df ScaleTo;
		};
	}
}

#endif // _NIRT_COMPILE_WITH_PARTICLES_

#endif // C_PARTICLE_SCALE_AFFECTOR_H

