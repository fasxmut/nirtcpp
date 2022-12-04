// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_META_TRIANGLE_SELECTOR_H_INCLUDED
#define NIRT_C_META_TRIANGLE_SELECTOR_H_INCLUDED

#include <nirtcpp/IMetaTriangleSelector.hpp>
#include <nirtcpp/irrArray.hpp>

namespace nirt
{
namespace scene
{

//! Interface for making multiple triangle selectors work as one big selector.
class CMetaTriangleSelector : public IMetaTriangleSelector
{
public:

	//! constructor
	CMetaTriangleSelector();

	//! destructor
	virtual ~CMetaTriangleSelector();

	//! Get amount of all available triangles in this selector
	virtual s32 getTriangleCount() const override;

	//! Gets all triangles.
	virtual void getTriangles(core::triangle3df* triangles, s32 arraySize,
		s32& outTriangleCount, const core::matrix4* transform, bool useNodeTransform, 
		nirt::core::array<SCollisionTriangleRange>* outTriangleInfo) const override;

	//! Gets all triangles which lie within a specific bounding box.
	virtual void getTriangles(core::triangle3df* triangles, s32 arraySize,
		s32& outTriangleCount, const core::aabbox3d<f32>& box,
		const core::matrix4* transform,	bool useNodeTransform, 
		nirt::core::array<SCollisionTriangleRange>* outTriangleInfo) const override;

	//! Gets all triangles which have or may have contact with a 3d line.
	virtual void getTriangles(core::triangle3df* triangles, s32 arraySize,
		s32& outTriangleCount, const core::line3d<f32>& line,
		const core::matrix4* transform,	bool useNodeTransform, 
		nirt::core::array<SCollisionTriangleRange>* outTriangleInfo) const override;

	//! Adds a triangle selector to the collection of triangle selectors
	//! in this metaTriangleSelector.
	virtual void addTriangleSelector(ITriangleSelector* toAdd) override;

	//! Removes a specific triangle selector which was added before	from the collection.
	virtual bool removeTriangleSelector(ITriangleSelector* toRemove) override;

	//! Removes all triangle selectors from the collection.
	virtual void removeAllTriangleSelectors() override;

	//! Get the scene node associated with a given triangle.
	virtual ISceneNode* getSceneNodeForTriangle(u32 triangleIndex) const override;

	// Get the number of TriangleSelectors that are part of this one
	virtual u32 getSelectorCount() const override;

	// Get the TriangleSelector based on index based on getSelectorCount
	virtual ITriangleSelector* getSelector(u32 index) override;

	// Get the TriangleSelector based on index based on getSelectorCount
	virtual const ITriangleSelector* getSelector(u32 index) const override;

private:

	core::array<ITriangleSelector*> TriangleSelectors;
};

} // end namespace scene
} // end namespace nirt


#endif
