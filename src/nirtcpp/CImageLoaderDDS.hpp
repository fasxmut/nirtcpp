// Copyright (C) 2002-2012 Thomas Alten
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_IMAGE_LOADER_DDS_H_INCLUDED
#define NIRT_C_IMAGE_LOADER_DDS_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>

#if defined(_NIRT_COMPILE_WITH_DDS_LOADER_) || defined(_NIRT_COMPILE_WITH_DDS_DECODER_LOADER_)

#include <nirtcpp/IImageLoader.hpp>

namespace nirt
{
namespace video
{

/* dds pixel format types */
enum eDDSPixelFormat
{
	DDS_PF_ARGB8888,
	DDS_PF_DXT1,
	DDS_PF_DXT2,
	DDS_PF_DXT3,
	DDS_PF_DXT4,
	DDS_PF_DXT5,
	DDS_PF_UNKNOWN
};

// byte-align structures
#include <nirtcpp/irrpack.hpp>

/* structures */

struct ddsPixelFormat
{
	u32	Size;
	u32 Flags;
	u32 FourCC;
	u32 RGBBitCount;
	u32	RBitMask;
	u32 GBitMask;
	u32 BBitMask;
	u32	ABitMask;
} PACK_STRUCT;


struct ddsCaps
{
	u32		caps1;
	u32		caps2;
	u32		caps3;
	u32		caps4;
} PACK_STRUCT;


struct ddsHeader
{
	c8 Magic[4];
	u32 Size;
	u32 Flags;
	u32 Height;
	u32 Width;
	u32 PitchOrLinearSize;
	u32 Depth;
	u32 MipMapCount;
	u32 Reserved1[11];
	ddsPixelFormat PixelFormat;
	ddsCaps Caps;
	u32 Reserved2;
} PACK_STRUCT;


#ifdef _NIRT_COMPILE_WITH_DDS_DECODER_LOADER_

struct ddsColorBlock
{
	u16		colors[ 2 ];
	u8		row[ 4 ];
} PACK_STRUCT;


struct ddsAlphaBlockExplicit
{
	u16		row[ 4 ];
} PACK_STRUCT;


struct ddsAlphaBlock3BitLinear
{
	u8		alpha0;
	u8		alpha1;
	u8		stuff[ 6 ];
} PACK_STRUCT;


struct ddsColor
{
	u8		r, g, b, a;
} PACK_STRUCT;

#endif


// Default alignment
#include <nirtcpp/irrunpack.hpp>


/* endian tomfoolery */
using floatSwapUnion = union
{
	f32	f;
	c8	c[ 4 ];
};


#ifndef __BIG_ENDIAN__
#ifdef _SGI_SOURCE
#define	__BIG_ENDIAN__
#endif
#endif


#ifdef __BIG_ENDIAN__

	s32   DDSBigLong( s32 src ) { return src; }
	s16 DDSBigShort( s16 src ) { return src; }
	f32 DDSBigFloat( f32 src ) { return src; }

	s32 DDSLittleLong( s32 src )
	{
		return ((src & 0xFF000000) >> 24) |
			((src & 0x00FF0000) >> 8) |
			((src & 0x0000FF00) << 8) |
			((src & 0x000000FF) << 24);
	}

	s16 DDSLittleShort( s16 src )
	{
		return ((src & 0xFF00) >> 8) |
			((src & 0x00FF) << 8);
	}

	f32 DDSLittleFloat( f32 src )
	{
		floatSwapUnion in,out;
		in.f = src;
		out.c[ 0 ] = in.c[ 3 ];
		out.c[ 1 ] = in.c[ 2 ];
		out.c[ 2 ] = in.c[ 1 ];
		out.c[ 3 ] = in.c[ 0 ];
		return out.f;
	}

#else /*__BIG_ENDIAN__*/

	s32   DDSLittleLong( s32 src ) { return src; }
	s16 DDSLittleShort( s16 src ) { return src; }
	f32 DDSLittleFloat( f32 src ) { return src; }

	s32 DDSBigLong( s32 src )
	{
		return ((src & 0xFF000000) >> 24) |
			((src & 0x00FF0000) >> 8) |
			((src & 0x0000FF00) << 8) |
			((src & 0x000000FF) << 24);
	}

	s16 DDSBigShort( s16 src )
	{
		return ((src & 0xFF00) >> 8) |
			((src & 0x00FF) << 8);
	}

	f32 DDSBigFloat( f32 src )
	{
		floatSwapUnion in,out;
		in.f = src;
		out.c[ 0 ] = in.c[ 3 ];
		out.c[ 1 ] = in.c[ 2 ];
		out.c[ 2 ] = in.c[ 1 ];
		out.c[ 3 ] = in.c[ 0 ];
		return out.f;
	}

#endif /*__BIG_ENDIAN__*/


/*!
	Surface Loader for DDS images
*/
class CImageLoaderDDS : public IImageLoader
{
public:

	//! returns true if the file maybe is able to be loaded by this class
	//! based on the file extension (e.g. ".tga")
	virtual bool isALoadableFileExtension(const io::path& filename) const override;

	//! returns true if the file maybe is able to be loaded by this class
	virtual bool isALoadableFileFormat(io::IReadFile* file) const override;

	//! creates a surface from the file
	virtual IImage* loadImage(io::IReadFile* file) const override;
};


} // end namespace video
} // end namespace nirt

#endif // compiled with DDS loader
#endif
