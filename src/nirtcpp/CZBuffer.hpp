// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_Z_BUFFER_H_INCLUDED
#define NIRT_C_Z_BUFFER_H_INCLUDED

#include "IZBuffer.hpp"

namespace nirt
{
namespace video
{

	class CZBuffer : public IZBuffer
	{
	public:

		//! constructor
		CZBuffer(const core::dimension2d<u32>& size);

		//! destructor
		virtual ~CZBuffer();

		//! clears the zbuffer
		virtual void clear() override;

		//! sets the new size of the zbuffer
		virtual void setSize(const core::dimension2d<u32>& size) override;

		//! returns the size of the zbuffer
		virtual const core::dimension2d<u32>& getSize() const override;

		//! locks the zbuffer
		virtual TZBufferType* lock() override;

		//! unlocks the zbuffer
		virtual void unlock() override;

	private:

		TZBufferType* Buffer;
		TZBufferType* BufferEnd;
		core::dimension2d<u32> Size;
		s32 TotalSize;
	};

} // end namespace video
} // end namespace nirt

#endif
