// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef _C_IMAGE_WRITER_PNG_H_INCLUDED__
#define _C_IMAGE_WRITER_PNG_H_INCLUDED__

#include "IrrCompileConfig.h"

#ifdef _NIRT_COMPILE_WITH_PNG_WRITER_

#include "IImageWriter.h"

namespace nirt
{
namespace video
{

class CImageWriterPNG : public IImageWriter
{
public:
	//! constructor
	CImageWriterPNG();

	//! return true if this writer can write a file with the given extension
	virtual bool isAWriteableFileExtension(const io::path& filename) const override;

	//! write image to file
	virtual bool writeImage(io::IWriteFile *file, IImage *image, u32 param) const override;
};

} // namespace video
} // namespace nirt

#endif // _C_IMAGE_WRITER_PNG_H_INCLUDED__
#endif

