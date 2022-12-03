// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_DUMMY_TRANSFORMATION_SCENE_NODE_H_INCLUDED
#define NIRT_C_DUMMY_TRANSFORMATION_SCENE_NODE_H_INCLUDED

#include "IDummyTransformationSceneNode.h"

namespace nirt
{
namespace scene
{

	class CDummyTransformationSceneNode : public IDummyTransformationSceneNode
	{
	public:

		//! constructor
		CDummyTransformationSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id);

		//! returns the axis aligned bounding box of this node
		virtual const core::aabbox3d<f32>& getBoundingBox() const override;

		//! Returns a reference to the current relative transformation matrix.
		//! This is the matrix, this scene node uses instead of scale, translation
		//! and rotation.
		virtual core::matrix4& getRelativeTransformationMatrix() override;

		//! Returns the relative transformation of the scene node.
		virtual core::matrix4 getRelativeTransformation() const override;

		//! does nothing.
		virtual void render() override {}

		//! Returns type of the scene node
		virtual ESCENE_NODE_TYPE getType() const override { return ESNT_DUMMY_TRANSFORMATION; }

		//! Creates a clone of this scene node and its children.
		virtual ISceneNode* clone(ISceneNode* newParent=0, ISceneManager* newManager=0) override;


	private:

		// TODO: We can add least add some warnings to find troubles faster until we have
		// fixed bug id 2318691.
		virtual const core::vector3df& getScale() const override;
		virtual void setScale(const core::vector3df& scale) override;
		virtual const core::vector3df& getRotation() const override;
		virtual void setRotation(const core::vector3df& rotation) override;
		virtual const core::vector3df& getPosition() const override;
		virtual void setPosition(const core::vector3df& newpos) override;

		core::matrix4 RelativeTransformationMatrix;
		core::aabbox3d<f32> Box;
	};

} // end namespace scene
} // end namespace nirt

#endif
