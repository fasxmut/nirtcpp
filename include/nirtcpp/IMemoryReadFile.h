// Copyright Michael Zeilfelder
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_I_MEMORY_READ_FILE_H_INCLUDED
#define NIRT_I_MEMORY_READ_FILE_H_INCLUDED

#include "IReadFile.h"

namespace nirt
{
namespace io
{

	//! Interface providing read access to a memory read file.
	class IMemoryReadFile : public IReadFile
	{
	public:
		//! Get direct access to internal buffer of memory block used as file.
		/** It's usually better to use the IReadFile functions to access
		the file content. But as that buffer exist over the full life-time
		of a CMemoryReadFile, it's sometimes nice to avoid the additional
		data-copy which read() needs.
		*/
		virtual const void *getBuffer() const = 0;
	};
} // end namespace io
} // end namespace nirt

#endif
