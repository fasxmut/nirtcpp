// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_MESH_SCENE_NODE_H_INCLUDED
#define NIRT_C_MESH_SCENE_NODE_H_INCLUDED

#include <nirtcpp/IMeshSceneNode.hpp>
#include <nirtcpp/IMesh.hpp>

namespace nirt
{
namespace scene
{

	class CMeshSceneNode : public IMeshSceneNode
	{
	public:

		//! constructor
		CMeshSceneNode(IMesh* mesh, ISceneNode* parent, ISceneManager* mgr,	s32 id,
			const core::vector3df& position = core::vector3df(0,0,0),
			const core::vector3df& rotation = core::vector3df(0,0,0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f));

		//! destructor
		virtual ~CMeshSceneNode();

		//! frame
		virtual void OnRegisterSceneNode() override;

		//! renders the node.
		virtual void render() override;

		//! returns the axis aligned bounding box of this node
		virtual const core::aabbox3d<f32>& getBoundingBox() const override;

		//! returns the material based on the zero based index i. To get the amount
		//! of materials used by this scene node, use getMaterialCount().
		//! This function is needed for inserting the node into the scene hierarchy on a
		//! optimal position for minimizing renderstate changes, but can also be used
		//! to directly modify the material of a scene node.
		virtual video::SMaterial& getMaterial(u32 i) override;

		//! returns amount of materials used by this scene node.
		virtual u32 getMaterialCount() const override;

		//! Writes attributes of the scene node.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) const override;

		//! Reads attributes of the scene node.
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0) override;

		//! Returns type of the scene node
		virtual ESCENE_NODE_TYPE getType() const override { return ESNT_MESH; }

		//! Sets a new mesh
		virtual void setMesh(IMesh* mesh) override;

		//! Returns the current mesh
		virtual IMesh* getMesh(void) override { return Mesh; }

		//! Creates shadow volume scene node as child of this node
		//! and returns a pointer to it.
		virtual IShadowVolumeSceneNode* addShadowVolumeSceneNode(const IMesh* shadowMesh,
			s32 id, bool zfailmethod=true, f32 infinity=10000.0f) override;

		//! Sets if the scene node should not copy the materials of the mesh but use them in a read only style.
		/* In this way it is possible to change the materials a mesh causing all mesh scene nodes
		referencing this mesh to change too. */
		virtual void setReadOnlyMaterials(bool readonly) override;

		//! Returns if the scene node should not copy the materials of the mesh but use them in a read only style
		virtual bool isReadOnlyMaterials() const override;

		//! Creates a clone of this scene node and its children.
		virtual ISceneNode* clone(ISceneNode* newParent=0, ISceneManager* newManager=0) override;

		//! Removes a child from this scene node.
		//! Implemented here, to be able to remove the shadow properly, if there is one,
		//! or to remove attached child.
		virtual bool removeChild(ISceneNode* child) override;

	protected:

		void copyMaterials();

		core::array<video::SMaterial> Materials;
		core::aabbox3d<f32> Box;
		video::SMaterial ReadOnlyMaterial;

		IMesh* Mesh;
		IShadowVolumeSceneNode* Shadow;

		s32 PassCount;
		bool ReadOnlyMaterials;
	};

} // end namespace scene
} // end namespace nirt

#endif
