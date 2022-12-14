// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_I_IMAGE_PRESENTER_H_INCLUDED
#define NIRT_I_IMAGE_PRESENTER_H_INCLUDED

#include <nirtcpp/IImage.hpp>

namespace nirt
{
namespace video
{

/*!
	Interface for a class which is able to present an IImage
	an the Screen. Usually only implemented by an IrrDevice for
	presenting Software Device Rendered images.

	This class should be used only internally.
*/

	class IImagePresenter
	{
	public:

		virtual ~IImagePresenter() {};
		//! presents a surface in the client area
		virtual bool present(video::IImage* surface, void* windowId=0, core::rect<s32>* src=0 ) = 0;
	};

} // end namespace video
} // end namespace nirt

#endif
