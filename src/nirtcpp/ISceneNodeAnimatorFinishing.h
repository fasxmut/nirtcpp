// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_I_SCENE_NODE_ANIMATOR_FINISHING_H_INCLUDED
#define NIRT_I_SCENE_NODE_ANIMATOR_FINISHING_H_INCLUDED

#include "ISceneNode.h"

namespace nirt
{
namespace scene
{
	//! This is an abstract base class for animators that have a discrete end time.
	class ISceneNodeAnimatorFinishing : public ISceneNodeAnimator
	{
	public:

		//! constructor
		ISceneNodeAnimatorFinishing(u32 finishTime)
			: FinishTime(finishTime), HasFinished(false) { }

		virtual bool hasFinished(void) const override { return HasFinished; }

	protected:

		u32 FinishTime;
		bool HasFinished;
	};


} // end namespace scene
} // end namespace nirt

#endif
