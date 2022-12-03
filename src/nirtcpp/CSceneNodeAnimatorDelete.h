// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_SCENE_NODE_ANIMATOR_DELETE_H_INCLUDED
#define NIRT_C_SCENE_NODE_ANIMATOR_DELETE_H_INCLUDED

#include "ISceneNodeAnimatorFinishing.h"

namespace nirt
{
namespace scene
{
	class CSceneNodeAnimatorDelete : public ISceneNodeAnimatorFinishing
	{
	public:

		//! constructor
		CSceneNodeAnimatorDelete(ISceneManager* manager, u32 when);

		//! animates a scene node
		virtual void animateNode(ISceneNode* node, u32 timeMs) override;

		//! Returns type of the scene node animator
		virtual ESCENE_NODE_ANIMATOR_TYPE getType() const override
		{
			return ESNAT_DELETION;
		}

		//! Creates a clone of this animator.
		/** Please note that you will have to drop
		(IReferenceCounted::drop()) the returned pointer after calling
		this. */
		virtual ISceneNodeAnimator* createClone(ISceneNode* node, ISceneManager* newManager=0) override;

	private:

		ISceneManager* SceneManager;
	};


} // end namespace scene
} // end namespace nirt

#endif
