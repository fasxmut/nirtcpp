// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_PARTICLE_RING_EMITTER_H_INCLUDED
#define NIRT_C_PARTICLE_RING_EMITTER_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>
#ifdef _NIRT_COMPILE_WITH_PARTICLES_

#include <nirtcpp/IParticleRingEmitter.hpp>
#include <nirtcpp/irrArray.hpp>

namespace nirt
{
namespace scene
{

//! A ring emitter
class CParticleRingEmitter : public IParticleRingEmitter
{
public:

	//! constructor
	CParticleRingEmitter(
		const core::vector3df& center, f32 radius, f32 ringThickness,
		const core::vector3df& direction = core::vector3df(0.0f,0.03f,0.0f),
		u32 minParticlesPerSecond = 20,
		u32 maxParticlesPerSecond = 40,
		const video::SColor& minStartColor = video::SColor(255,0,0,0),
		const video::SColor& maxStartColor = video::SColor(255,255,255,255),
		u32 lifeTimeMin=2000,
		u32 lifeTimeMax=4000,
		s32 maxAngleDegrees=0,
		const core::dimension2df& minStartSize = core::dimension2df(5.0f,5.0f),
		const core::dimension2df& maxStartSize = core::dimension2df(5.0f,5.0f)
		);

	//! Prepares an array with new particles to emitt into the system
	//! and returns how much new particles there are.
	virtual s32 emitt(u32 now, u32 timeSinceLastCall, SParticle*& outArray) override;

	//! Set direction the emitter emits particles
	virtual void setDirection( const core::vector3df& newDirection ) override { Direction = newDirection; }

	//! Set minimum number of particles the emitter emits per second
	virtual void setMinParticlesPerSecond( u32 minPPS ) override { MinParticlesPerSecond = minPPS; }

	//! Set maximum number of particles the emitter emits per second
	virtual void setMaxParticlesPerSecond( u32 maxPPS ) override { MaxParticlesPerSecond = maxPPS; }

	//! Set minimum starting color for particles
	virtual void setMinStartColor( const video::SColor& color ) override { MinStartColor = color; }

	//! Set maximum starting color for particles
	virtual void setMaxStartColor( const video::SColor& color ) override { MaxStartColor = color; }

	//! Set the maximum starting size for particles
	virtual void setMaxStartSize( const core::dimension2df& size ) override { MaxStartSize = size; }

	//! Set the minimum starting size for particles
	virtual void setMinStartSize( const core::dimension2df& size ) override { MinStartSize = size; }

	//! Set the minimum particle life-time in milliseconds
	virtual void setMinLifeTime( u32 lifeTimeMin ) override { MinLifeTime = lifeTimeMin; }

	//! Set the maximum particle life-time in milliseconds
	virtual void setMaxLifeTime( u32 lifeTimeMax ) override { MaxLifeTime = lifeTimeMax; }

	//!	Set maximal random derivation from the direction
	virtual void setMaxAngleDegrees( s32 maxAngleDegrees ) override { MaxAngleDegrees = maxAngleDegrees; }

	//! Set the center of the ring
	virtual void setCenter( const core::vector3df& center ) override { Center = center; }

	//! Set the radius of the ring
	virtual void setRadius( f32 radius ) override { Radius = radius; }

	//! Set the thickness of the ring
	virtual void setRingThickness( f32 ringThickness ) override { RingThickness = ringThickness; }

	//! Gets direction the emitter emits particles
	virtual const core::vector3df& getDirection() const override { return Direction; }

	//! Gets the minimum number of particles the emitter emits per second
	virtual u32 getMinParticlesPerSecond() const override { return MinParticlesPerSecond; }

	//! Gets the maximum number of particles the emitter emits per second
	virtual u32 getMaxParticlesPerSecond() const override { return MaxParticlesPerSecond; }

	//! Gets the minimum starting color for particles
	virtual const video::SColor& getMinStartColor() const override { return MinStartColor; }

	//! Gets the maximum starting color for particles
	virtual const video::SColor& getMaxStartColor() const override { return MaxStartColor; }

	//! Gets the maximum starting size for particles
	virtual const core::dimension2df& getMaxStartSize() const override { return MaxStartSize; }

	//! Gets the minimum starting size for particles
	virtual const core::dimension2df& getMinStartSize() const override { return MinStartSize; }

	//! Get the minimum particle life-time in milliseconds
	virtual u32 getMinLifeTime() const override { return MinLifeTime; }

	//! Get the maximum particle life-time in milliseconds
	virtual u32 getMaxLifeTime() const override { return MaxLifeTime; }

	//!	Get maximal random derivation from the direction
	virtual s32 getMaxAngleDegrees() const override { return MaxAngleDegrees; }

	//! Get the center of the ring
	virtual const core::vector3df& getCenter() const override { return Center; }

	//! Get the radius of the ring
	virtual f32 getRadius() const override { return Radius; }

	//! Get the thickness of the ring
	virtual f32 getRingThickness() const override { return RingThickness; }

	//! Writes attributes of the object.
	virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const override;

	//! Reads attributes of the object.
	virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options) override;

private:

	core::array<SParticle> Particles;

	core::vector3df	Center;
	f32 Radius;
	f32 RingThickness;

	core::vector3df Direction;
	core::dimension2df MaxStartSize, MinStartSize;
	u32 MinParticlesPerSecond, MaxParticlesPerSecond;
	video::SColor MinStartColor, MaxStartColor;
	u32 MinLifeTime, MaxLifeTime;

	u32 Time;
	s32 MaxAngleDegrees;
};

} // end namespace scene
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_PARTICLES_

#endif
