// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef _C_IMAGE_WRITER_PPM_H_INCLUDED__
#define _C_IMAGE_WRITER_PPM_H_INCLUDED__

#include <nirtcpp/IrrCompileConfig.hpp>

#ifdef _NIRT_COMPILE_WITH_PPM_WRITER_

#include <nirtcpp/IImageWriter.hpp>

namespace nirt
{
namespace video
{

class CImageWriterPPM : public IImageWriter
{
public:
	//! constructor
	CImageWriterPPM();

	//! return true if this writer can write a file with the given extension
	virtual bool isAWriteableFileExtension(const io::path& filename) const override;

	//! write image to file
	virtual bool writeImage(io::IWriteFile *file, IImage *image, u32 param) const override;
};

} // namespace video
} // namespace nirt

#endif // _C_IMAGE_WRITER_PPM_H_INCLUDED__
#endif

