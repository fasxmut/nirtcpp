// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#include "CSceneNodeAnimatorDelete.hpp"
#include <nirtcpp/ISceneManager.hpp>

namespace nirt
{
namespace scene
{


//! constructor
CSceneNodeAnimatorDelete::CSceneNodeAnimatorDelete(ISceneManager* manager, u32 time)
: ISceneNodeAnimatorFinishing(time), SceneManager(manager)
{
	#ifdef _DEBUG
	setDebugName("CSceneNodeAnimatorDelete");
	#endif
}


//! animates a scene node
void CSceneNodeAnimatorDelete::animateNode(ISceneNode* node, u32 timeMs)
{
	if (timeMs > FinishTime+PauseTimeSum)
	{
		HasFinished = true;
		if(node && SceneManager)
		{
			// don't delete if scene manager is attached to an editor
			if (!SceneManager->getParameters()->getAttributeAsBool(NIRT_SCENE_MANAGER_IS_EDITOR))
				SceneManager->addToDeletionQueue(node);
		}
	}
}


ISceneNodeAnimator* CSceneNodeAnimatorDelete::createClone(ISceneNode* node, ISceneManager* newManager)
{
	if (!newManager)
		newManager = SceneManager;

	CSceneNodeAnimatorDelete* newAnimator =
		new CSceneNodeAnimatorDelete(newManager, FinishTime);
	newAnimator->cloneMembers(this);

	return newAnimator;
}


} // end namespace scene
} // end namespace nirt

