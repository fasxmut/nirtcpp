// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

//! As of Nirtcpp 1.6, position2d is a synonym for vector2d.
/** You should consider position2d to be deprecated, and use vector2d by preference. */

#ifndef NIRT_POSITION_H_INCLUDED
#define NIRT_POSITION_H_INCLUDED

#include <nirtcpp/vector2d.hpp>

namespace nirt
{
namespace core
{

// Use using type aliases where possible as they are more explicit...

//! \deprecated position2d is now a synonym for vector2d, but vector2d should be used directly.
using position2df = vector2d<f32>;

//! \deprecated position2d is now a synonym for vector2d, but vector2d should be used directly.
using position2di = vector2d<s32>;
} // namespace core
} // namespace nirt

// ...and use a #define to catch the rest, for (e.g.) position2d<f64>
#define position2d vector2d

#endif // NIRT_POSITION_H_INCLUDED
