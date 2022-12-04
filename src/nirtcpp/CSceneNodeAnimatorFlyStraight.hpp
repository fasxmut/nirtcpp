// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_SCENE_NODE_ANIMATOR_FLY_STRAIGHT_H_INCLUDED
#define NIRT_C_SCENE_NODE_ANIMATOR_FLY_STRAIGHT_H_INCLUDED

#include "ISceneNodeAnimatorFinishing.hpp"

namespace nirt
{
namespace scene
{
	class CSceneNodeAnimatorFlyStraight : public ISceneNodeAnimatorFinishing
	{
	public:

		//! constructor
		CSceneNodeAnimatorFlyStraight(const core::vector3df& startPoint,
						const core::vector3df& endPoint,
						u32 timeForWay,
						bool loop, u32 now, bool pingpong);

		//! animates a scene node
		virtual void animateNode(ISceneNode* node, u32 timeMs) override;

		//! Writes attributes of the scene node animator.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) const override;

		//! Reads attributes of the scene node animator.
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0) override;

		//! Returns type of the scene node animator
		virtual ESCENE_NODE_ANIMATOR_TYPE getType() const override { return ESNAT_FLY_STRAIGHT; }

		//! Creates a clone of this animator.
		/** Please note that you will have to drop
		(IReferenceCounted::drop()) the returned pointer after calling this. */
		virtual ISceneNodeAnimator* createClone(ISceneNode* node, ISceneManager* newManager=0) override;

	private:

		void recalculateIntermediateValues();

		core::vector3df Start;
		core::vector3df End;
		core::vector3df Vector;
		f32 TimeFactor;
		u32 TimeForWay;
		bool Loop;
		bool PingPong;
	};


} // end namespace scene
} // end namespace nirt

#endif
