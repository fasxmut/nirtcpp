// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_IMAGE_H_INCLUDED
#define NIRT_C_IMAGE_H_INCLUDED

#include <nirtcpp/IImage.hpp>
#include <nirtcpp/rect.hpp>

namespace nirt
{
namespace video
{

//! IImage implementation with a lot of special image operations for
//! 16 bit A1R5G5B5/32 Bit A8R8G8B8 images, which are used by the SoftwareDevice.
class CImage : public IImage
{
public:

	//! constructor from raw image data
	/** \param useForeignMemory: If true, the image will use the data pointer
	directly and own it from now on, which means it will also try to delete [] the
	data when the image will be destructed. If false, the memory will by copied. */
	CImage(ECOLOR_FORMAT format, const core::dimension2d<u32>& size, void* data,
		bool ownForeignMemory = true, bool deleteMemory = true);

	//! constructor for empty image
	CImage(ECOLOR_FORMAT format, const core::dimension2d<u32>& size);

	//! returns a pixel
	virtual SColor getPixel(u32 x, u32 y) const override;

	//! sets a pixel
	virtual void setPixel(u32 x, u32 y, const SColor &color, bool blend = false ) override;

	//! copies this surface into another, scaling it to fit.
	virtual void copyToScaling(void* target, u32 width, u32 height, ECOLOR_FORMAT format, u32 pitch=0) override;

	//! copies this surface into another, scaling it to fit.
	virtual void copyToScaling(IImage* target) override;

	//! copies this surface into another
	virtual void copyTo(IImage* target, const core::position2d<s32>& pos=core::position2d<s32>(0,0)) override;

	//! copies this surface into another
	virtual void copyTo(IImage* target, const core::position2d<s32>& pos, const core::rect<s32>& sourceRect, const core::rect<s32>* clipRect=0) override;

	//! copies this surface into another, using the alpha mask, an cliprect and a color to add with
	virtual void copyToWithAlpha(IImage* target, const core::position2d<s32>& pos,
			const core::rect<s32>& sourceRect, const SColor &color,
			const core::rect<s32>* clipRect = 0, bool combineAlpha=false) override;

	//! copies this surface into another, scaling it to fit, applying a box filter
	virtual void copyToScalingBoxFilter(IImage* target, s32 bias = 0, bool blend = false) override;

	//! Flips (mirrors) the image in one or two directions
	virtual void flip(bool topBottom, bool leftRight) override;

	//! fills the surface with given color
	virtual void fill(const SColor &color) override;

private:
	inline SColor getPixelBox ( const s32 x, const s32 y, const s32 fx, const s32 fy, s32 bias ) const;
};

} // end namespace video
} // end namespace nirt

#endif
