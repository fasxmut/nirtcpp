// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_OCTREE_SCENE_NODE_H_INCLUDED
#define NIRT_C_OCTREE_SCENE_NODE_H_INCLUDED

#include <nirtcpp/IOctreeSceneNode.hpp>
#include "Octree.hpp"

namespace nirt
{
namespace scene
{
	class COctreeSceneNode;

	//! implementation of the IOctreeSceneNode
	class COctreeSceneNode : public IOctreeSceneNode
	{
	public:

		//! constructor
		COctreeSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id,
			s32 minimalPolysPerNode=512);

		//! destructor
		virtual ~COctreeSceneNode();

		virtual void OnRegisterSceneNode() override;

		//! renders the node.
		virtual void render() override;

		//! returns the axis aligned bounding box of this node
		virtual const core::aabbox3d<f32>& getBoundingBox() const override;

		//! creates the tree
		bool createTree(IMesh* mesh);

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
		virtual ESCENE_NODE_TYPE getType() const override { return ESNT_OCTREE; }

		//! Sets a new mesh to display
		virtual void setMesh(IMesh* mesh) override;

		//! Get the currently defined mesh for display.
		virtual IMesh* getMesh(void) override;

		//! Sets if the scene node should not copy the materials of the mesh but use them in a read only style.
		virtual void setReadOnlyMaterials(bool readonly) override;

		//! Check if the scene node should not copy the materials of the mesh but use them in a read only style
		virtual bool isReadOnlyMaterials() const override;

		//! Creates shadow volume scene node as child of this node
		//! and returns a pointer to it.
		virtual IShadowVolumeSceneNode* addShadowVolumeSceneNode(const IMesh* shadowMesh,
			s32 id, bool zfailmethod=true, f32 infinity=10000.0f) override;

		//! Removes a child from this scene node.
		//! Implemented here, to be able to remove the shadow properly, if there is one,
		//! or to remove attached child.
		virtual bool removeChild(ISceneNode* child) override;

		// TODO: Currently using VBO's will crash when reloading the model.
		//       The reason is that COctreeSceneNode uses Octree::SMeshChunk 
		//       which does use a an IReferenceCounted object on the stack.
		//       Which breaks VBO's which correctly use reference counting.,
		//! Set if/how vertex buffer object are used for the meshbuffers
		/** NOTE: When there is already a mesh in the node this will rebuild
		the octree. */
		virtual void setUseVBO(EOCTREENODE_VBO useVBO);

		//! Get if/how vertex buffer object are used for the meshbuffers
		virtual EOCTREENODE_VBO getUseVBO() const override;

		//! Set the kind of tests polygons do for visibility against the camera
		virtual void setPolygonChecks(EOCTREE_POLYGON_CHECKS checks) override;

		//! Get the kind of tests polygons do for visibility against the camera
		virtual EOCTREE_POLYGON_CHECKS getPolygonChecks() const override;

	private:

		void deleteTree();

		core::aabbox3d<f32> Box;

		Octree<video::S3DVertex>* StdOctree;
		core::array< Octree<video::S3DVertex>::SMeshChunk > StdMeshes;

		Octree<video::S3DVertex2TCoords>* LightMapOctree;
		core::array< Octree<video::S3DVertex2TCoords>::SMeshChunk > LightMapMeshes;

		Octree<video::S3DVertexTangents>* TangentsOctree;
		core::array< Octree<video::S3DVertexTangents>::SMeshChunk > TangentsMeshes;

		video::E_VERTEX_TYPE VertexType;
		core::array< video::SMaterial > Materials;

		core::stringc MeshName;
		s32 MinimalPolysPerNode;
		s32 PassCount;

		IMesh * Mesh;
		IShadowVolumeSceneNode* Shadow;

		EOCTREENODE_VBO UseVBOs;
		EOCTREE_POLYGON_CHECKS PolygonChecks;
	};

} // end namespace scene
} // end namespace nirt

#endif
