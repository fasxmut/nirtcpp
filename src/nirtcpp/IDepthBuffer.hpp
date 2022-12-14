// Copyright (C) 2002-2012 Nikolaus Gebhardt / Thomas Alten
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_I_Z2_BUFFER_H_INCLUDED
#define NIRT_I_Z2_BUFFER_H_INCLUDED

#include <nirtcpp/IReferenceCounted.hpp>
#include <nirtcpp/dimension2d.hpp>
#include "S4DVertex.hpp"

namespace nirt
{
namespace video
{
	class IDepthBuffer : public virtual IReferenceCounted
	{
	public:

		//! destructor
		virtual ~IDepthBuffer() {};

		//! clears the zbuffer
		virtual void clear(f32 value, const interlaced_control interlaced) = 0;

		//! sets the new size of the zbuffer
		virtual void setSize(const core::dimension2d<u32>& size) = 0;

		//! returns the size of the zbuffer
		virtual const core::dimension2d<u32>& getSize() const = 0;

		//! locks the zbuffer
		virtual void* lock() = 0;

		//! unlocks the zbuffer
		virtual void unlock() = 0;

		//! returns pitch of depthbuffer (in bytes)
		virtual u32 getPitch() const = 0;

	};


	//! creates a ZBuffer
	IDepthBuffer* createDepthBuffer(const core::dimension2d<u32>& size);

	class IStencilBuffer : public virtual IReferenceCounted
	{
	public:

		//! destructor
		virtual ~IStencilBuffer() {};

		//! clears the stencil buffer
		virtual void clear(u32 value, const interlaced_control interlaced) = 0;

		//! sets the new size of the zbuffer
		virtual void setSize(const core::dimension2d<u32>& size) = 0;

		//! returns the size of the stencil buffer
		virtual const core::dimension2d<u32>& getSize() const = 0;

		//! locks the stencil buffer
		virtual void* lock() = 0;

		//! unlocks the stencil buffer
		virtual void unlock() = 0;

		//! returns pitch of stencil buffer (in bytes)
		virtual u32 getPitch() const = 0;

	};


	//! creates a Stencil Buffer
	IStencilBuffer* createStencilBuffer(const core::dimension2d<u32>& size, u32 bit);

} // end namespace video
} // end namespace nirt

#endif
