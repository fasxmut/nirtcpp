// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_IMAGE_LOADER_PSD_H_INCLUDED
#define NIRT_C_IMAGE_LOADER_PSD_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>

#ifdef _NIRT_COMPILE_WITH_PSD_LOADER_

#include <nirtcpp/IImageLoader.hpp>

namespace nirt
{
namespace video
{


// byte-align structures
#include <nirtcpp/irrpack.hpp>

	struct PsdHeader
	{
		c8 signature [4];	// Always equal to 8BPS.
		u16 version;		// Always equal to 1
		c8 reserved [6];	// Must be zero
		u16 channels;		// Number of any channels inc. alphas
		u32 height;		// Rows Height of image in pixel
		u32 width;		// Colums Width of image in pixel
		u16 depth;		// Bits/channel
		u16 mode;		// Color mode of the file (Bitmap/Grayscale..)
	} PACK_STRUCT;


// Default alignment
#include <nirtcpp/irrunpack.hpp>

/*!
	Surface Loader for psd images
*/
class CImageLoaderPSD : public IImageLoader
{
public:

	//! constructor
	CImageLoaderPSD();

	//! returns true if the file maybe is able to be loaded by this class
	//! based on the file extension (e.g. ".tga")
	virtual bool isALoadableFileExtension(const io::path& filename) const override;

	//! returns true if the file maybe is able to be loaded by this class
	virtual bool isALoadableFileFormat(io::IReadFile* file) const override;

	//! creates a surface from the file
	virtual IImage* loadImage(io::IReadFile* file) const override;

private:

	bool readRawImageData(io::IReadFile* file, const PsdHeader& header, u32* imageData) const;
	bool readRLEImageData(io::IReadFile* file, const PsdHeader& header, u32* imageData) const;
	s16 getShiftFromChannel(c8 channelNr, const PsdHeader& header) const;
};


} // end namespace video
} // end namespace nirt

#endif
#endif
