// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_I_META_TRIANGLE_SELECTOR_H_INCLUDED
#define NIRT_I_META_TRIANGLE_SELECTOR_H_INCLUDED

#include <nirtcpp/ITriangleSelector.hpp>

namespace nirt
{
namespace scene
{

//! Interface for making multiple triangle selectors work as one big selector.
/** This is nothing more than a collection of one or more triangle selectors
providing together the interface of one triangle selector. In this way,
collision tests can be done with different triangle soups in one pass.
*/
class IMetaTriangleSelector : public ITriangleSelector
{
public:

	//! Adds a triangle selector to the collection of triangle selectors.
	/** \param toAdd: Pointer to an triangle selector to add to the list. */
	virtual void addTriangleSelector(ITriangleSelector* toAdd) = 0;

	//! Removes a specific triangle selector from the collection.
	/** \param toRemove: Pointer to an triangle selector which is in the
	list but will be removed.
	\return True if successful, false if not. */
	virtual bool removeTriangleSelector(ITriangleSelector* toRemove) = 0;

	//! Removes all triangle selectors from the collection.
	virtual void removeAllTriangleSelectors() = 0;
};

} // end namespace scene
} // end namespace nirt

#endif
