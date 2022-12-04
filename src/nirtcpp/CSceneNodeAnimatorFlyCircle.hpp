// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_SCENE_NODE_ANIMATOR_FLY_CIRCLE_H_INCLUDED
#define NIRT_C_SCENE_NODE_ANIMATOR_FLY_CIRCLE_H_INCLUDED

#include <nirtcpp/ISceneNode.hpp>

namespace nirt
{
namespace scene
{
	class CSceneNodeAnimatorFlyCircle : public ISceneNodeAnimator
	{
	public:

		//! constructor
		CSceneNodeAnimatorFlyCircle(u32 time,
				const core::vector3df& center, f32 radius,
				f32 speed, const core::vector3df& direction,
				f32 radiusEllipsoid);

		//! animates a scene node
		virtual void animateNode(ISceneNode* node, u32 timeMs) override;

		//! Writes attributes of the scene node animator.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) const override;

		//! Reads attributes of the scene node animator.
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0) override;

		//! Returns type of the scene node animator
		virtual ESCENE_NODE_ANIMATOR_TYPE getType() const override { return ESNAT_FLY_CIRCLE; }

		//! Creates a clone of this animator.
		/** Please note that you will have to drop
		(IReferenceCounted::drop()) the returned pointer after calling
		this. */
		virtual ISceneNodeAnimator* createClone(ISceneNode* node, ISceneManager* newManager=0) override;

	private:
		// do some initial calculations
		void init();

		// circle center
		core::vector3df Center;
		// up-vector, normal to the circle's plane
		core::vector3df Direction;
		// Two helper vectors
		core::vector3df VecU;
		core::vector3df VecV;
		f32 Radius;
		f32 RadiusEllipsoid;
		f32 Speed;
	};


} // end namespace scene
} // end namespace nirt

#endif
