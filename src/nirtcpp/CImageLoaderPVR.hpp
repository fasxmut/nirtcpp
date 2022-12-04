// Copyright (C) 2013-2016 Patryk Nadrowski
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_IMAGE_LOADER_PVR_H_INCLUDED
#define NIRT_C_IMAGE_LOADER_PVR_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>

#ifdef _NIRT_COMPILE_WITH_PVR_LOADER_

#include <nirtcpp/IImageLoader.hpp>

namespace nirt
{
namespace video
{

#include <nirtcpp/irrpack.hpp>

struct SPVRHeader
{
    u32 Version;
    u32 Flags;
    u64 PixelFormat;
    u32 ColourSpace;
    u32 ChannelType;
    u32 Height;
    u32 Width;
    u32 Depth;
    u32 NumSurfaces;
    u32 NumFaces;
    u32 MipMapCount;
    u32 MetDataSize;
} PACK_STRUCT;

#include <nirtcpp/irrunpack.hpp>

class CImageLoaderPVR : public IImageLoader
{
public:
	virtual bool isALoadableFileExtension(const io::path& filename) const override;

	virtual bool isALoadableFileFormat(io::IReadFile* file) const override;

	virtual IImage* loadImage(io::IReadFile* file) const override;

	virtual core::array<IImage*> loadImages(io::IReadFile* file, E_TEXTURE_TYPE* type) const override;
};

}
}

#endif
#endif
