// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_IMAGE_LOADER_PCX_H_INCLUDED
#define NIRT_C_IMAGE_LOADER_PCX_H_INCLUDED

#include "IrrCompileConfig.h"

#include "IImageLoader.h"

namespace nirt
{
namespace video
{

#if defined(_NIRT_COMPILE_WITH_PCX_LOADER_) || defined(_NIRT_COMPILE_WITH_PCX_WRITER_)

// byte-align structures
#include "irrpack.h"

	struct SPCXHeader
	{
		u8	Manufacturer;
		u8	Version;
		u8	Encoding;
		u8	BitsPerPixel;
		u16	XMin;
		u16	YMin;
		u16	XMax;
		u16	YMax;
		u16	HorizDPI;
		u16	VertDPI;
		u8	Palette[48];
		u8	Reserved;
		u8	Planes;
		u16	BytesPerLine;
		u16	PaletteType;
		u16	HScrSize;
		u16	VScrSize;
		u8	Filler[54];
	} PACK_STRUCT;


// Default alignment
#include "irrunpack.h"

#endif // compile with loader or writer

#ifdef _NIRT_COMPILE_WITH_PCX_LOADER_

/*!
	Image Loader for Windows PCX bitmaps.
	This loader was written and sent in by Dean P. Macri. I modified
	only some small bits of it.
*/
class CImageLoaderPCX : public IImageLoader
{
public:

	//! constructor
	CImageLoaderPCX();

	//! returns true if the file maybe is able to be loaded by this class
	//! based on the file extension (e.g. ".tga")
	virtual bool isALoadableFileExtension(const io::path& filename) const override;

	//! returns true if the file maybe is able to be loaded by this class
	virtual bool isALoadableFileFormat(io::IReadFile* file) const override;

	//! creates a surface from the file
	virtual IImage* loadImage(io::IReadFile* file) const override;

};

#endif // compile with loader

} // end namespace video
} // end namespace nirt

#endif
