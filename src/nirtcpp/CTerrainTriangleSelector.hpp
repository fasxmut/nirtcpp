// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

// The code for the TerrainTriangleSelector is based on the GeoMipMapSelector
// developed by Spintz. He made it available for Nirtcpp and allowed it to be
// distributed under this license. I only modified some parts. A lot of thanks go to him.

#ifndef NIRT_C_TERRAIN_TRIANGLE_SELECTOR_H
#define NIRT_C_TERRAIN_TRIANGLE_SELECTOR_H

#include <nirtcpp/ITriangleSelector.hpp>
#include <nirtcpp/irrArray.hpp>

namespace nirt
{
namespace scene
{

class ITerrainSceneNode;

//! Triangle Selector for the TerrainSceneNode
/** The code for the TerrainTriangleSelector is based on the GeoMipMapSelector
developed by Spintz. He made it available for Nirtcpp and allowed it to be
distributed under this license. I only modified some parts. A lot of thanks go
to him.
*/
class CTerrainTriangleSelector : public ITriangleSelector
{
public:

	//! Constructs a selector based on an ITerrainSceneNode
	CTerrainTriangleSelector(ITerrainSceneNode* node, s32 LOD);

	//! Destructor
	virtual ~CTerrainTriangleSelector();

	//! Clears and sets triangle data
	virtual void setTriangleData(ITerrainSceneNode* node, s32 LOD);

	//! Gets all triangles.
	void getTriangles(core::triangle3df* triangles, s32 arraySize, s32& outTriangleCount,
		const core::matrix4* transform, bool useNodeTransform, 
		nirt::core::array<SCollisionTriangleRange>* outTriangleInfo) const override;

	//! Gets all triangles which lie within a specific bounding box.
	void getTriangles(core::triangle3df* triangles, s32 arraySize, s32& outTriangleCount,
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
	virtual ISceneNode* getSceneNodeForTriangle(u32 triangleIndex) const override;

	// Get the number of TriangleSelectors that are part of this one
	virtual u32 getSelectorCount() const override;

	// Get the TriangleSelector based on index based on getSelectorCount
	virtual ITriangleSelector* getSelector(u32 index) override;

	// Get the TriangleSelector based on index based on getSelectorCount
	virtual const ITriangleSelector* getSelector(u32 index) const override;

private:

	friend class CTerrainSceneNode;

	struct SGeoMipMapTrianglePatch
	{
		core::array<core::triangle3df> Triangles;
		s32 NumTriangles;
		core::aabbox3df Box;
	};

	struct SGeoMipMapTrianglePatches
	{
		SGeoMipMapTrianglePatches() :
			NumPatches(0), TotalTriangles(0)
		{
		}

		core::array<SGeoMipMapTrianglePatch> TrianglePatchArray;
		s32 NumPatches;
		u32 TotalTriangles;
	};

	ITerrainSceneNode* SceneNode;
	SGeoMipMapTrianglePatches TrianglePatches;
};

} // end namespace scene
} // end namespace nirt

#endif // NIRT_C_TERRAIN_TRIANGLE_SELECTOR_H
