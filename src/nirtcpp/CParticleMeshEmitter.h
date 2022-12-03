// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_PARTICLE_MESH_EMITTER_H_INCLUDED
#define NIRT_C_PARTICLE_MESH_EMITTER_H_INCLUDED

#include "IrrCompileConfig.h"
#ifdef _NIRT_COMPILE_WITH_PARTICLES_

#include "IParticleMeshEmitter.h"
#include "irrArray.h"
#include "aabbox3d.h"
#include "IMeshBuffer.h"

namespace nirt
{
namespace scene
{

//! A default box emitter
class CParticleMeshEmitter : public IParticleMeshEmitter
{
public:

	//! constructor
	CParticleMeshEmitter(
		IMesh* mesh, bool useNormalDirection = true,
		const core::vector3df& direction = core::vector3df(0.0f,0.0f,0.0f),
		f32 normalDirectionModifier = 100.0f,
		s32 mbNumber = -1,
		bool everyMeshVertex = false,
		u32 minParticlesPerSecond = 20,
		u32 maxParticlesPerSecond = 40,
		const video::SColor& minStartColor = video::SColor(255,0,0,0),
		const video::SColor& maxStartColor = video::SColor(255,255,255,255),
		u32 lifeTimeMin = 2000,
		u32 lifeTimeMax = 4000,
		s32 maxAngleDegrees = 0,
		const core::dimension2df& minStartSize = core::dimension2df(5.0f,5.0f),
		const core::dimension2df& maxStartSize = core::dimension2df(5.0f,5.0f)
	);

	//! Prepares an array with new particles to emitt into the system
	//! and returns how much new particles there are.
	virtual s32 emitt(u32 now, u32 timeSinceLastCall, SParticle*& outArray) override;

	//! Set Mesh to emit particles from
	virtual void setMesh( IMesh* mesh ) override;

	//! Set whether to use vertex normal for direction, or direction specified
	virtual void setUseNormalDirection( bool useNormalDirection ) override { UseNormalDirection = useNormalDirection; }

	//! Set direction the emitter emits particles
	virtual void setDirection( const core::vector3df& newDirection ) override { Direction = newDirection; }

	//! Set the amount that the normal is divided by for getting a particles direction
	virtual void setNormalDirectionModifier( f32 normalDirectionModifier ) override { NormalDirectionModifier = normalDirectionModifier; }

	//! Sets whether to emit min<->max particles for every vertex per second, or to pick
	//! min<->max vertices every second
	virtual void setEveryMeshVertex( bool everyMeshVertex ) override { EveryMeshVertex = everyMeshVertex; }

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

	//! Get Mesh we're emitting particles from
	virtual const IMesh* getMesh() const override { return Mesh; }

	//! Get whether to use vertex normal for direciton, or direction specified
	virtual bool isUsingNormalDirection() const override { return UseNormalDirection; }

	//! Get direction the emitter emits particles
	virtual const core::vector3df& getDirection() const override { return Direction; }

	//! Get the amount that the normal is divided by for getting a particles direction
	virtual f32 getNormalDirectionModifier() const override { return NormalDirectionModifier; }

	//! Gets whether to emit min<->max particles for every vertex per second, or to pick
	//! min<->max vertices every second
	virtual bool getEveryMeshVertex() const override { return EveryMeshVertex; }

	//! Get the minimum number of particles the emitter emits per second
	virtual u32 getMinParticlesPerSecond() const override { return MinParticlesPerSecond; }

	//! Get the maximum number of particles the emitter emits per second
	virtual u32 getMaxParticlesPerSecond() const override { return MaxParticlesPerSecond; }

	//! Get the minimum starting color for particles
	virtual const video::SColor& getMinStartColor() const override { return MinStartColor; }

	//! Get the maximum starting color for particles
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

private:

	const IMesh* Mesh;
	core::array<s32>	VertexPerMeshBufferList;
	s32 TotalVertices;
	u32 MBCount;
	s32 MBNumber;

	f32 NormalDirectionModifier;
	core::array<SParticle> Particles;
	core::vector3df Direction;
	core::dimension2df MaxStartSize, MinStartSize;
	u32 MinParticlesPerSecond, MaxParticlesPerSecond;
	video::SColor MinStartColor, MaxStartColor;
	u32 MinLifeTime, MaxLifeTime;

	u32 Time;
	s32 MaxAngleDegrees;

	bool EveryMeshVertex;
	bool UseNormalDirection;
};

} // end namespace scene
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_PARTICLES_

#endif // NIRT_C_PARTICLE_MESH_EMITTER_H_INCLUDED
