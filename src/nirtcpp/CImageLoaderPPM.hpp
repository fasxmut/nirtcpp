// Copyright (C) 2007-2012 Christian Stehno
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_IMAGE_LOADER_PPM_H_INCLUDED
#define NIRT_C_IMAGE_LOADER_PPM_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>

#ifdef _NIRT_COMPILE_WITH_PPM_LOADER_

#include <nirtcpp/IImageLoader.hpp>
#include <nirtcpp/irrString.hpp>


namespace nirt
{
namespace video
{


/*!
	Surface Loader for SUN Pixmaps
*/
class CImageLoaderPPM : public IImageLoader
{
public:

	//! constructor
	CImageLoaderPPM();

	//! returns true if the file maybe is able to be loaded by this class
	//! based on the file extension (e.g. ".tga")
	virtual bool isALoadableFileExtension(const io::path& filename) const override;

	//! returns true if the file maybe is able to be loaded by this class
	virtual bool isALoadableFileFormat(io::IReadFile* file) const override;

	//! creates a surface from the file
	virtual IImage* loadImage(io::IReadFile* file) const override;

private:
	//! read the next token from file
	void getNextToken(io::IReadFile* file, core::stringc& token) const;
	//! skip to next token (skip whitespace)
	void skipToNextToken(io::IReadFile* file) const;
};

} // end namespace video
} // end namespace nirt

#endif
#endif
