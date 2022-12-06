// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#include "CImageWriterPSD.hpp"

#ifdef _NIRT_COMPILE_WITH_PSD_WRITER_

#include "CImageLoaderPSD.hpp"
#include <nirtcpp/IWriteFile.hpp>
#include "os.hpp" // for logging
#include <nirtcpp/irrString.hpp>

namespace nirt
{
namespace video
{

IImageWriter* createImageWriterPSD()
{
	return new CImageWriterPSD;
}

CImageWriterPSD::CImageWriterPSD()
{
#ifdef _DEBUG
	setDebugName("CImageWriterPSD");
#endif
}

bool CImageWriterPSD::isAWriteableFileExtension(const io::path& filename) const
{
	return core::hasFileExtension ( filename, "psd" );
}

bool CImageWriterPSD::writeImage(io::IWriteFile *file, IImage *image,u32 param) const
{
	os::Printer::log("PSD writer not yet implemented. Image not written.", ELL_WARNING);
	return false;
}

} // namespace video
} // namespace nirt

#endif

