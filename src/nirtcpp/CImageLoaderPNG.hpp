// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

// this file was created by rt (www.tomkorp.com), based on ttk's png-reader
// i wanted to be able to read in PNG images with nirtcpp :)
// why?  lossless compression with 8-bit alpha channel!

#ifndef NIRT_C_IMAGE_LOADER_PNG_H_INCLUDED
#define NIRT_C_IMAGE_LOADER_PNG_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>

#ifdef _NIRT_COMPILE_WITH_PNG_LOADER_

#include <nirtcpp/IImageLoader.hpp>

namespace nirt
{
namespace video
{

//!  Surface Loader for PNG files
class CImageLoaderPng : public IImageLoader
{
public:

	//! returns true if the file maybe is able to be loaded by this class
	//! based on the file extension (e.g. ".png")
	virtual bool isALoadableFileExtension(const io::path& filename) const override;

	//! returns true if the file maybe is able to be loaded by this class
	virtual bool isALoadableFileFormat(io::IReadFile* file) const override;

	//! creates a surface from the file
	virtual IImage* loadImage(io::IReadFile* file) const override;
};


} // end namespace video
} // end namespace nirt

#endif
#endif
