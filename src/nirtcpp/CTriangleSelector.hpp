// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_TRIANGLE_SELECTOR_H_INCLUDED
#define NIRT_C_TRIANGLE_SELECTOR_H_INCLUDED

#include <nirtcpp/ITriangleSelector.hpp>
#include <nirtcpp/IMesh.hpp>
#include <nirtcpp/irrArray.hpp>
#include <nirtcpp/aabbox3d.hpp>

namespace nirt
{
namespace scene
{

class ISceneNode;
class IAnimatedMeshSceneNode;

//! Stupid triangle selector without optimization
class CTriangleSelector : public ITriangleSelector
{
public:

	//! Constructs a selector based on a mesh
	CTriangleSelector(ISceneNode* node);

	//! Constructs a selector based on a mesh
	CTriangleSelector(const IMesh* mesh, ISceneNode* node, bool separateMeshbuffers);

	//! Constructs a selector based on a meshbuffer
	CTriangleSelector(const IMeshBuffer* meshBuffer, nirt::u32 materialIndex, ISceneNode* node);

	//! Constructs a selector based on an animated mesh scene node
	//!\param node An animated mesh scene node, which must have a valid mesh
	CTriangleSelector(IAnimatedMeshSceneNode* node, bool separateMeshbuffers);

	//! Constructs a selector based on a bounding box
	CTriangleSelector(const core::aabbox3d<f32>& box, ISceneNode* node);

	//! Gets all triangles.
	virtual void getTriangles(core::triangle3df* triangles, s32 arraySize, s32& outTriangleCount,
		const core::matrix4* transform, bool useNodeTransform, 
		nirt::core::array<SCollisionTriangleRange>* outTriangleInfo) const override;

	//! Gets all triangles which lie within a specific bounding box.
	virtual void getTriangles(core::triangle3df* triangles, s32 arraySize, s32& outTriangleCount,
		const core::aabbox3d<f32>& box, const core::matrix4* transform, bool useNodeTransform, 
		nirt::core::array<SCollisionTriangleRange>* outTriangleInfo) const override;

	//! Gets all triangles which have or may have contact with a 3d line.
	virtual void getTriangles(core::triangle3df* triangles, s32 arraySize,
		s32& outTriangleCount, const core::line3d<f32>& line,
		const core::matrix4* transform, bool useNodeTransform, 
		nirt::core::array<SCollisionTriangleRange>* outTriangleInfo) const override;

	//! Returns amount of all available triangles in this selector
	virtual s32 getTriangleCount() const override;

	//! Return the scene node associated with a given triangle.
	virtual ISceneNode* getSceneNodeForTriangle(u32 triangleIndex) const override { return SceneNode; }

	// Get the number of TriangleSelectors that are part of this one
	virtual u32 getSelectorCount() const override;

	// Get the TriangleSelector based on index based on getSelectorCount
	virtual ITriangleSelector* getSelector(u32 index) override;

	// Get the TriangleSelector based on index based on getSelectorCount
	virtual const ITriangleSelector* getSelector(u32 index) const override;

protected:
	//! Create from a mesh
	virtual void createFromMesh(const IMesh* mesh, bool createBufferRanges);

	//! Create from a meshbuffer
	virtual void createFromMeshBuffer(const IMeshBuffer* meshBuffer);

	//! Update when the mesh has changed
	virtual void updateFromMesh(const IMesh* mesh) const;

	//! Update when the meshbuffer has changed
	virtual void updateFromMeshBuffer(const IMeshBuffer* meshBuffer) const;

	//! Update bounding box from triangles
	void updateBoundingBox() const;

	//! Update the triangle selector, which will only have an effect if it
	//! was built from an animated mesh and that mesh's frame has changed
	//! since the last time it was updated.
	virtual void update(void) const;

	nirt::core::array<SCollisionTriangleRange> BufferRanges;

	ISceneNode* SceneNode;
	mutable core::array<core::triangle3df> Triangles; // (mutable for CTriangleBBSelector)
	mutable core::aabbox3df BoundingBox; // Allows for trivial rejection

	const IMeshBuffer* MeshBuffer;	// non-zero when the selector is for a single meshbuffer
	nirt::u32 MaterialIndex;		// Only set when MeshBuffer is non-zero
	IAnimatedMeshSceneNode* AnimatedNode;
	mutable u32 LastMeshFrame;
};

} // end namespace scene
} // end namespace nirt

#endif
