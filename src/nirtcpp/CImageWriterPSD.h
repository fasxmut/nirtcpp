// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef _C_IMAGE_WRITER_PSD_H_INCLUDED__
#define _C_IMAGE_WRITER_PSD_H_INCLUDED__

#include "IrrCompileConfig.h"

#ifdef _NIRT_COMPILE_WITH_PSD_WRITER_

#include "IImageWriter.h"

namespace nirt
{
namespace video
{

class CImageWriterPSD : public IImageWriter
{
public:
	//! constructor
	CImageWriterPSD();

	//! return true if this writer can write a file with the given extension
	virtual bool isAWriteableFileExtension(const io::path& filename) const override;

	//! write image to file
	virtual bool writeImage(io::IWriteFile *file, IImage *image,u32 param) const override;
};

} // namespace video
} // namespace nirt

#endif // _I_IMAGE_WRITER_PSD_H_INCLUDED__
#endif
