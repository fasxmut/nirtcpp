// Copyright (C) 2004 Murphy McCauley
// Copyright (C) 2007-2012 Christian Stehno
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h
/*
 Thanks to:
 Max McGuire for his Flipcode article about WAL textures
 Nikolaus Gebhardt for the Nirtcpp 3D engine
*/

#ifndef NIRT_C_IMAGE_LOADER_WAL_H_INCLUDED
#define NIRT_C_IMAGE_LOADER_WAL_H_INCLUDED

#include "IrrCompileConfig.h"
#include "IImageLoader.h"

namespace nirt
{
namespace video
{

#ifdef _NIRT_COMPILE_WITH_LMP_LOADER_

// byte-align structures
#include "irrpack.h"

	struct SLMPHeader {
		u32	width;	// width
		u32	height;	// height
		// variably sized
	} PACK_STRUCT;

// Default alignment
#include "irrunpack.h"

//! An Nirtcpp image loader for Quake1,2 engine lmp textures/palette
class CImageLoaderLMP : public nirt::video::IImageLoader
{
public:
	virtual bool isALoadableFileExtension(const io::path& filename) const override;
	virtual bool isALoadableFileFormat(nirt::io::IReadFile* file) const override;
	virtual nirt::video::IImage* loadImage(nirt::io::IReadFile* file) const override;
};

#endif

#ifdef _NIRT_COMPILE_WITH_WAL_LOADER_

//! An Nirtcpp image loader for quake2 wal engine textures
class CImageLoaderWAL : public nirt::video::IImageLoader
{
public:
	virtual bool isALoadableFileExtension(const io::path& filename) const override;
	virtual bool isALoadableFileFormat(nirt::io::IReadFile* file) const override;
	virtual nirt::video::IImage* loadImage(nirt::io::IReadFile* file) const override;
};

//! An Nirtcpp image loader for Halflife 1 engine textures
class CImageLoaderWAL2 : public nirt::video::IImageLoader
{
public:
	virtual bool isALoadableFileExtension(const io::path& filename) const override;
	virtual bool isALoadableFileFormat(nirt::io::IReadFile* file) const override;
	virtual nirt::video::IImage* loadImage(nirt::io::IReadFile* file) const override;
};

// byte-align structures
#include "irrpack.h"

	// Halfelife wad3 type 67 file
	struct miptex_halflife
	{
		c8  name[16];
		u32 width, height;
		u32 mipmap[4];		// four mip maps stored
	} PACK_STRUCT;

	//quake2 texture
	struct miptex_quake2
	{
		c8 name[32];
		u32 width;
		u32 height;
		u32 mipmap[4];		// four mip maps stored
		c8  animname[32];	// next frame in animation chain
		s32 flags;
		s32 contents;
		s32 value;
	} PACK_STRUCT;

// Default alignment
#include "irrunpack.h"

#endif

}
}

#endif
