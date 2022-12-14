// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_VIDEO_MODE_LIST_H_INCLUDED
#define NIRT_C_VIDEO_MODE_LIST_H_INCLUDED

#include <nirtcpp/IVideoModeList.hpp>
#include <nirtcpp/dimension2d.hpp>
#include <nirtcpp/irrArray.hpp>

namespace nirt
{
namespace video
{

	class CVideoModeList : public IVideoModeList
	{
	public:

		//! constructor
		CVideoModeList();

		//! Gets amount of video modes in the list.
		virtual s32 getVideoModeCount() const override;

		//! Returns the screen size of a video mode in pixels.
		virtual core::dimension2d<u32> getVideoModeResolution(s32 modeNumber) const override;

		//! Returns the screen size of an optimal video mode in pixels.
		virtual core::dimension2d<u32> getVideoModeResolution(const core::dimension2d<u32>& minSize, const core::dimension2d<u32>& maxSize) const override;

		//! Returns the pixel depth of a video mode in bits.
		virtual s32 getVideoModeDepth(s32 modeNumber) const override;

		//! Returns current desktop screen resolution.
		virtual const core::dimension2d<u32>& getDesktopResolution() const override;

		//! Returns the pixel depth of a video mode in bits.
		virtual s32 getDesktopDepth() const override;

		//! adds a new mode to the list
		void addMode(const core::dimension2d<u32>& size, s32 depth);

		void setDesktop(s32 desktopDepth, const core::dimension2d<u32>& desktopSize);

	private:

		struct SVideoMode
		{
			core::dimension2d<u32> size;
			s32 depth;

			bool operator==(const SVideoMode& other) const
			{
				return size == other.size && depth == other.depth;
			}

			bool operator <(const SVideoMode& other) const
			{
				return (size.Width < other.size.Width ||
					(size.Width == other.size.Width &&
					size.Height < other.size.Height) ||
					(size.Width == other.size.Width &&
					size.Height == other.size.Height &&
					depth < other.depth));
			}
		};

		core::array<SVideoMode> VideoModes;
		SVideoMode Desktop;
	};

} // end namespace video
} // end namespace nirt

#endif
