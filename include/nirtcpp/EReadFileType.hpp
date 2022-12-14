// Copyright (C) Michael Zeilfelder
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_E_READ_FILE_TYPES_H_INCLUDED
#define NIRT_E_READ_FILE_TYPES_H_INCLUDED

#include <nirtcpp/irrTypes.hpp>

namespace nirt
{
namespace io
{

	//! An enumeration for different class types implementing IReadFile
	enum EREAD_FILE_TYPE
	{
		//! CReadFile
		ERFT_READ_FILE  = MAKE_NIRT_ID('r','e','a','d'),

		//! CMemoryReadFile
		ERFT_MEMORY_READ_FILE = MAKE_NIRT_ID('r','m','e','m'),

		//! CLimitReadFile
		ERFT_LIMIT_READ_FILE = MAKE_NIRT_ID('r','l','i','m'),

		//! Unknown type
		EFIT_UNKNOWN        = MAKE_NIRT_ID('u','n','k','n')
	};
} // end namespace io
} // end namespace nirt

#endif
