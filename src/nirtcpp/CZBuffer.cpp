// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#include <nirtcpp/IrrCompileConfig.hpp>
#include "CZBuffer.hpp"
#include <nirtcpp/irrString.hpp>
#include <algorithm>
#include <string>

#ifdef _NIRT_COMPILE_WITH_SOFTWARE_

namespace nirt
{
namespace video
{


//! constructor
CZBuffer::CZBuffer(const core::dimension2d<u32>& size)
: Buffer(0), BufferEnd(0), Size(0,0), TotalSize(0)
{
	#ifdef _DEBUG
	setDebugName("CZBuffer");
	#endif

	setSize(size);
}



//! destructor
CZBuffer::~CZBuffer()
{
	delete [] Buffer;
}



//! clears the zbuffer
void CZBuffer::clear()
{
	std::fill_n(reinterpret_cast<std::uint8_t *>(Buffer), (BufferEnd-Buffer)*sizeof(TZBufferType), 0);
}



//! sets the new size of the zbuffer
void CZBuffer::setSize(const core::dimension2d<u32>& size)
{
	if (size == Size)
		return;

	Size = size;

	delete [] Buffer;

	TotalSize = size.Width * size.Height;
	Buffer = new TZBufferType[TotalSize];
	BufferEnd = Buffer + TotalSize;
}



//! returns the size of the zbuffer
const core::dimension2d<u32>& CZBuffer::getSize() const
{
	return Size;
}



//! locks the zbuffer
TZBufferType* CZBuffer::lock()
{
	return Buffer;
}



//! unlocks the zbuffer
void CZBuffer::unlock()
{
}

} // end namespace video
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_SOFTWARE_

namespace nirt
{
namespace video
{

//! creates a ZBuffer
IZBuffer* createZBuffer(const core::dimension2d<u32>& size)
{
	#ifdef _NIRT_COMPILE_WITH_SOFTWARE_
	return new CZBuffer(size);
	#else
	return 0;
	#endif // _NIRT_COMPILE_WITH_SOFTWARE_
}


} // end namespace video
} // end namespace nirt



