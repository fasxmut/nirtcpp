// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_PARTICLE_SYSTEM_SCENE_NODE_H_INCLUDED
#define NIRT_C_PARTICLE_SYSTEM_SCENE_NODE_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>
#ifdef _NIRT_COMPILE_WITH_PARTICLES_

#include <nirtcpp/IParticleSystemSceneNode.hpp>
#include <nirtcpp/irrArray.hpp>
#include <nirtcpp/irrList.hpp>
#include <nirtcpp/SMeshBuffer.hpp>

namespace nirt
{
namespace scene
{

//! A particle system scene node.
/** A scene node controlling a particle system. The behavior of the particles
can be controlled by setting the right particle emitters and affectors.
*/
class CParticleSystemSceneNode : public IParticleSystemSceneNode
{
public:

	//! constructor
	CParticleSystemSceneNode(bool createDefaultEmitter,
		ISceneNode* parent, ISceneManager* mgr, s32 id,
		const core::vector3df& position,
		const core::vector3df& rotation,
		const core::vector3df& scale);

	//! destructor
	virtual ~CParticleSystemSceneNode();

	//! Gets the particle emitter, which creates the particles.
	virtual IParticleEmitter* getEmitter() override;

	//! Sets the particle emitter, which creates the particles.
	virtual void setEmitter(IParticleEmitter* emitter) override;

	//! Adds new particle affector to the particle system.
	virtual void addAffector(IParticleAffector* affector) override;

	//! Get a list of all particle affectors.
	virtual const core::list<IParticleAffector*>& getAffectors() const override;

	//! Removes all particle affectors in the particle system.
	virtual void removeAllAffectors() override;

	//! Returns the material based on the zero based index i.
	virtual video::SMaterial& getMaterial(u32 i) override;

	//! Returns amount of materials used by this scene node.
	virtual u32 getMaterialCount() const override;

	//! pre render event
	virtual void OnRegisterSceneNode() override;

	//! render
	virtual void render() override;

	//! returns the axis aligned bounding box of this node
	virtual const core::aabbox3d<f32>& getBoundingBox() const override;

	//! Creates a particle emitter for an animated mesh scene node
	virtual IParticleAnimatedMeshSceneNodeEmitter* createAnimatedMeshSceneNodeEmitter(
		scene::IAnimatedMeshSceneNode* node, bool useNormalDirection = true,
		const core::vector3df& direction = core::vector3df(0.0f,0.03f,0.0f),
		f32 normalDirectionModifier = 100.0f, s32 mbNumber = -1,
		bool everyMeshVertex = false, u32 minParticlesPerSecond = 5,
		u32 maxParticlesPerSecond = 10,
		const video::SColor& minStartColor = video::SColor(255,0,0,0),
		const video::SColor& maxStartColor = video::SColor(255,255,255,255),
		u32 lifeTimeMin = 2000, u32 lifeTimeMax = 4000,
		s32 maxAngleDegrees = 0,
		const core::dimension2df& minStartSize = core::dimension2df(5.0f,5.0f),
		const core::dimension2df& maxStartSize = core::dimension2df(5.0f,5.0f) ) override;

	//! Creates a box particle emitter.
	virtual IParticleBoxEmitter* createBoxEmitter(
		const core::aabbox3df& box = core::aabbox3d<f32>(-10,0,-10,5,30,10),
		const core::vector3df& direction = core::vector3df(0.0f,0.03f,0.0f),
		u32 minParticlesPerSecond = 5,
		u32 maxParticlesPerSecond = 10,
		const video::SColor& minStartColor = video::SColor(255,0,0,0),
		const video::SColor& maxStartColor = video::SColor(255,255,255,255),
		u32 lifeTimeMin=2000, u32 lifeTimeMax=4000,
		s32 maxAngleDegrees=0,
		const core::dimension2df& minStartSize = core::dimension2df(5.0f,5.0f),
		const core::dimension2df& maxStartSize = core::dimension2df(5.0f,5.0f) ) override;

	//! Creates a particle emitter for emitting from a cylinder
	virtual IParticleCylinderEmitter* createCylinderEmitter(
		const core::vector3df& center, f32 radius,
		const core::vector3df& normal, f32 length,
		bool outlineOnly = false, const core::vector3df& direction = core::vector3df(0.0f,0.5f,0.0f),
		u32 minParticlesPerSecond = 5, u32 maxParticlesPersSecond = 10,
		const video::SColor& minStartColor = video::SColor(255,0,0,0),
		const video::SColor& maxStartColor = video::SColor(255,255,255,255),
		u32 lifeTimeMin = 2000, u32 lifeTimeMax = 4000,
		s32 maxAngleDegrees = 0,
		const core::dimension2df& minStartSize = core::dimension2df(5.0f,5.0f),
		const core::dimension2df& maxStartSize = core::dimension2df(5.0f,5.0f) ) override;

	//! Creates a mesh particle emitter.
	virtual IParticleMeshEmitter* createMeshEmitter(
		scene::IMesh* mesh, bool useNormalDirection = true,
		const core::vector3df& direction = core::vector3df(0.0f,0.03f,0.0f),
		f32 normalDirectionModifier = 100.0f, s32 mbNumber = -1,
		bool everyMeshVertex = false,
		u32 minParticlesPerSecond = 5,
		u32 maxParticlesPerSecond = 10,
		const video::SColor& minStartColor = video::SColor(255,0,0,0),
		const video::SColor& maxStartColor = video::SColor(255,255,255,255),
		u32 lifeTimeMin = 2000, u32 lifeTimeMax = 4000,
		s32 maxAngleDegrees = 0,
		const core::dimension2df& minStartSize = core::dimension2df(5.0f,5.0f),
		const core::dimension2df& maxStartSize = core::dimension2df(5.0f,5.0f) ) override;

	//! Creates a point particle emitter.
	virtual IParticlePointEmitter* createPointEmitter(
		const core::vector3df& direction = core::vector3df(0.0f,0.03f,0.0f),
		u32 minParticlesPerSecond = 5,
		u32 maxParticlesPerSecond = 10,
		const video::SColor& minStartColor = video::SColor(255,0,0,0),
		const video::SColor& maxStartColor = video::SColor(255,255,255,255),
		u32 lifeTimeMin=2000, u32 lifeTimeMax=4000,
		s32 maxAngleDegrees=0,
		const core::dimension2df& minStartSize = core::dimension2df(5.0f,5.0f),
		const core::dimension2df& maxStartSize = core::dimension2df(5.0f,5.0f) ) override;

	//! Creates a ring particle emitter.
	virtual IParticleRingEmitter* createRingEmitter(
		const core::vector3df& center, f32 radius, f32 ringThickness,
		const core::vector3df& direction = core::vector3df(0.0f,0.03f,0.0f),
		u32 minParticlesPerSecond = 5,
		u32 maxParticlesPerSecond = 10,
		const video::SColor& minStartColor = video::SColor(255,0,0,0),
		const video::SColor& maxStartColor = video::SColor(255,255,255,255),
		u32 lifeTimeMin=2000, u32 lifeTimeMax=4000,
		s32 maxAngleDegrees=0,
		const core::dimension2df& minStartSize = core::dimension2df(5.0f,5.0f),
		const core::dimension2df& maxStartSize = core::dimension2df(5.0f,5.0f) ) override;

	//! Creates a sphere particle emitter.
	virtual IParticleSphereEmitter* createSphereEmitter(
		const core::vector3df& center, f32 radius,
		const core::vector3df& direction = core::vector3df(0.0f,0.03f,0.0f),
		u32 minParticlesPerSecond = 5,
		u32 maxParticlesPerSecond = 10,
		const video::SColor& minStartColor = video::SColor(255,0,0,0),
		const video::SColor& maxStartColor = video::SColor(255,255,255,255),
		u32 lifeTimeMin=2000, u32 lifeTimeMax=4000,
		s32 maxAngleDegrees=0,
		const core::dimension2df& minStartSize = core::dimension2df(5.0f,5.0f),
		const core::dimension2df& maxStartSize = core::dimension2df(5.0f,5.0f) ) override;

	//! Creates a point attraction affector. This affector modifies the positions of the
	//! particles and attracts them to a specified point at a specified speed per second.
	virtual IParticleAttractionAffector* createAttractionAffector(
		const core::vector3df& point, f32 speed = 1.0f, bool attract = true,
		bool affectX = true, bool affectY = true, bool affectZ = true) override;

	//! Creates a scale particle affector.
	virtual IParticleAffector* createScaleParticleAffector(
		const core::dimension2df& scaleTo = core::dimension2df(1.0f, 1.0f)) override;

	//! Creates a fade out particle affector.
	virtual IParticleFadeOutAffector* createFadeOutParticleAffector(
		const video::SColor& targetColor = video::SColor(0,0,0,0),
		u32 timeNeededToFadeOut = 1000) override;

	//! Creates a gravity affector.
	virtual IParticleGravityAffector* createGravityAffector(
		const core::vector3df& gravity = core::vector3df(0.0f,-0.03f,0.0f),
		u32 timeForceLost = 1000) override;

	//! Creates a rotation affector. This affector rotates the particles
	//! around a specified pivot point. The speed is in Degrees per second.
	virtual IParticleRotationAffector* createRotationAffector(
		const core::vector3df& speed = core::vector3df(5.0f,5.0f,5.0f),
		const core::vector3df& pivotPoint = core::vector3df(0.0f,0.0f,0.0f) ) override;

	//! Sets the size of all particles.
	virtual void setParticleSize(
		const core::dimension2d<f32> &size = core::dimension2d<f32>(5.0f, 5.0f)) override;

	//! Sets if the particles should be global. If they are, the particles are affected by
	//! the movement of the particle system scene node too, otherwise they completely
	//! ignore it. Default is true.
	virtual void setParticlesAreGlobal(bool global=true) override;

	//! Remove all currently visible particles
	virtual void clearParticles() override;

	//! Sets if the node should be visible or not.
	virtual void setVisible(bool isVisible) override;

	//! Do manually update the particles.
	//! This should only be called when you want to render the node outside the scenegraph,
	//! as the node will care about this otherwise automatically.
	virtual void doParticleSystem(u32 time) override;

	//! Writes attributes of the scene node.
	virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) const override;

	//! Reads attributes of the scene node.
	virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0) override;

	//! Returns type of the scene node
	virtual ESCENE_NODE_TYPE getType() const override { return ESNT_PARTICLE_SYSTEM; }

private:

	void reallocateBuffers();

	core::list<IParticleAffector*> AffectorList;
	IParticleEmitter* Emitter;
	core::array<SParticle> Particles;
	core::dimension2d<f32> ParticleSize;
	u32 LastEmitTime;
	core::matrix4 LastAbsoluteTransformation;

	SMeshBuffer* Buffer;

// TODO: That was obviously planned by someone at some point and sounds like a good idea.
// But seems it was never implemented.
//	enum E_PARTICLES_PRIMITIVE
//	{
//		EPP_POINT=0,
//		EPP_BILLBOARD,
//		EPP_POINTSPRITE
//	};
//	E_PARTICLES_PRIMITIVE ParticlePrimitive;

	bool ParticlesAreGlobal;
};

} // end namespace scene
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_PARTICLES_

#endif
