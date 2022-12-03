// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

//! As of Nirtcpp 1.6, position2d is a synonym for vector2d.
/** You should consider position2d to be deprecated, and use vector2d by preference. */

#ifndef NIRT_POSITION_H_INCLUDED
#define NIRT_POSITION_H_INCLUDED

#include "vector2d.h"

namespace nirt
{
namespace core
{

// Use typedefs where possible as they are more explicit...

//! \deprecated position2d is now a synonym for vector2d, but vector2d should be used directly.
typedef vector2d<f32> position2df;

//! \deprecated position2d is now a synonym for vector2d, but vector2d should be used directly.
typedef vector2d<s32> position2di;
} // namespace core
} // namespace nirt

// ...and use a #define to catch the rest, for (e.g.) position2d<f64>
#define position2d vector2d

#endif // NIRT_POSITION_H_INCLUDED
