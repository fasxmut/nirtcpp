// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_E_MESH_WRITER_ENUMS_H_INCLUDED
#define NIRT_E_MESH_WRITER_ENUMS_H_INCLUDED

#include <nirtcpp/irrTypes.hpp>

namespace nirt
{
namespace scene
{

	//! An enumeration for all supported types of built-in mesh writers
	/** A scene mesh writers is represented by a four character code
	such as 'irrm' or 'coll' instead of simple numbers, to avoid
	name clashes with external mesh writers.*/
	enum EMESH_WRITER_TYPE
	{
		//! Irrlicht native mesh writer, for static .irrmesh files.
		EMWT_NIRT_MESH     = MAKE_NIRT_ID('i','r','r','m'),

		//! COLLADA mesh writer for .dae and .xml files
		EMWT_COLLADA      = MAKE_NIRT_ID('c','o','l','l'),

		//! STL mesh writer for .stl files
		EMWT_STL          = MAKE_NIRT_ID('s','t','l',0),

		//! OBJ mesh writer for .obj files
		EMWT_OBJ          = MAKE_NIRT_ID('o','b','j',0),

		//! PLY mesh writer for .ply files
		EMWT_PLY          = MAKE_NIRT_ID('p','l','y',0),
		
		//! B3D mesh writer, for static .b3d files
		EMWT_B3D          = MAKE_NIRT_ID('b', '3', 'd', 0)
	};


	//! flags configuring mesh writing
	enum E_MESH_WRITER_FLAGS
	{
		//! no writer flags
		EMWF_NONE = 0,

		//! write lightmap textures out if possible
		//! Currently not used by any Nirtcpp mesh-writer
		// (Note: User meshwriters can still use it)
		EMWF_WRITE_LIGHTMAPS = 0x1,

		//! write in a way that consumes less disk space
		// (Note: Mainly there for user meshwriters)
		EMWF_WRITE_COMPRESSED = 0x2,

		//! write in binary format rather than text
		EMWF_WRITE_BINARY = 0x4
	};

} // end namespace scene
} // end namespace nirt

#endif // NIRT_E_MESH_WRITER_ENUMS_H_INCLUDED
