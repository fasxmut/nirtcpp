// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_BONE_SCENE_NODE_H_INCLUDED
#define NIRT_C_BONE_SCENE_NODE_H_INCLUDED

// Used with SkinnedMesh and IAnimatedMeshSceneNode, for boned meshes

#include "IBoneSceneNode.h"

namespace nirt
{
namespace scene
{

	class CBoneSceneNode : public IBoneSceneNode
	{
	public:

		//! constructor
		CBoneSceneNode(ISceneNode* parent, ISceneManager* mgr,
			s32 id=-1, u32 boneIndex=0, const c8* boneName=0);

		//! Returns the index of the bone
		virtual u32 getBoneIndex() const override;

		//! Sets the animation mode of the bone. Returns true if successful.
		virtual bool setAnimationMode(E_BONE_ANIMATION_MODE mode) override;

		//! Gets the current animation mode of the bone
		virtual E_BONE_ANIMATION_MODE getAnimationMode() const override;

		//! returns the axis aligned bounding box of this node
		virtual const core::aabbox3d<f32>& getBoundingBox() const override;

		/*
		//! Returns the relative transformation of the scene node.
		//virtual core::matrix4 getRelativeTransformation() const override;
		*/

		virtual void OnAnimate(u32 timeMs) override;

		virtual void updateAbsolutePositionOfAllChildren() override;

		//! Writes attributes of the scene node.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) const override;

		//! Reads attributes of the scene node.
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0) override;

		//! How the relative transformation of the bone is used
		virtual void setSkinningSpace(E_BONE_SKINNING_SPACE space) override
		{
			SkinningSpace=space;
		}

		virtual E_BONE_SKINNING_SPACE getSkinningSpace() const override
		{
			return SkinningSpace;
		}

	private:
		void helper_updateAbsolutePositionOfAllChildren(ISceneNode *Node);

		u32 BoneIndex;

		core::aabbox3d<f32> Box;

		E_BONE_ANIMATION_MODE AnimationMode;
		E_BONE_SKINNING_SPACE SkinningSpace;
	};


} // end namespace scene
} // end namespace nirt

#endif
