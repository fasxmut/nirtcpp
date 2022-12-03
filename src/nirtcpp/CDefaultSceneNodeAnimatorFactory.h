// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_DEFAULT_SCENE_NODE_ANIMATOR_FACTORY_H_INCLUDED
#define NIRT_C_DEFAULT_SCENE_NODE_ANIMATOR_FACTORY_H_INCLUDED

#include "ISceneNodeAnimatorFactory.h"

namespace nirt
{
namespace gui
{
	class ICursorControl;
}
namespace scene
{
	class ISceneNodeAnimator;
	class ISceneManager;

	//! Interface making it possible to dynamicly create scene nodes animators
	class CDefaultSceneNodeAnimatorFactory : public ISceneNodeAnimatorFactory
	{
	public:

		CDefaultSceneNodeAnimatorFactory(ISceneManager* mgr, gui::ICursorControl* crs);

		virtual ~CDefaultSceneNodeAnimatorFactory();

		//! creates a scene node animator based on its type id
		/** \param type: Type of the scene node animator to add.
		\param target: Target scene node of the new animator.
		\return Returns pointer to the new scene node animator or null if not successful. You need to
		drop this pointer after calling this, see IReferenceCounted::drop() for details. */
		virtual ISceneNodeAnimator* createSceneNodeAnimator(ESCENE_NODE_ANIMATOR_TYPE type, ISceneNode* target) override;

		//! creates a scene node animator based on its type name
		/** \param typeName: Type of the scene node animator to add.
		\param target: Target scene node of the new animator.
		\return Returns pointer to the new scene node animator or null if not successful. You need to
		drop this pointer after calling this, see IReferenceCounted::drop() for details. */
		virtual ISceneNodeAnimator* createSceneNodeAnimator(const char* typeName, ISceneNode* target) override;

		//! returns amount of scene node animator types this factory is able to create
		virtual u32 getCreatableSceneNodeAnimatorTypeCount() const override;

		//! returns type of a creatable scene node animator type
		/** \param idx: Index of scene node animator type in this factory. Must be a value between 0 and
		getCreatableSceneNodeTypeCount() */
		virtual ESCENE_NODE_ANIMATOR_TYPE getCreateableSceneNodeAnimatorType(u32 idx) const override;

		//! returns type name of a creatable scene node animator type
		/** \param idx: Index of scene node animator type in this factory. Must be a value between 0 and
		getCreatableSceneNodeAnimatorTypeCount() */
		virtual const c8* getCreateableSceneNodeAnimatorTypeName(u32 idx) const override;

		//! returns type name of a creatable scene node animator type
		/** \param type: Type of scene node animator.
		\return: Returns name of scene node animator type if this factory can create the type, otherwise 0. */
		virtual const c8* getCreateableSceneNodeAnimatorTypeName(ESCENE_NODE_ANIMATOR_TYPE type) const override;

	private:

		ESCENE_NODE_ANIMATOR_TYPE getTypeFromName(const c8* name) const;

		ISceneManager* Manager;
		gui::ICursorControl* CursorControl;
	};


} // end namespace scene
} // end namespace nirt

#endif
