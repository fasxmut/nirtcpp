// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef S_K_2D_VERTEX_H_INCLUDED
#define S_K_2D_VERTEX_H_INCLUDED

#include <nirtcpp/vector2d.hpp>

typedef signed short TZBufferType;

namespace nirt
{
namespace video
{

	struct S2DVertex
	{
		core::vector2d<s32> Pos;	// position
		core::vector2d<s32> TCoords;	// texture coordinates
		TZBufferType ZValue;		// zvalue
		u16 Color;
	};


} // end namespace video
} // end namespace nirt

#endif
