// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_GUI_IN_OUT_FADER_H_INCLUDED
#define NIRT_C_GUI_IN_OUT_FADER_H_INCLUDED

#include "IrrCompileConfig.h"
#ifdef _NIRT_COMPILE_WITH_GUI_

#include "IGUIInOutFader.h"

namespace nirt
{
namespace gui
{

	class CGUIInOutFader : public IGUIInOutFader
	{
	public:

		//! constructor
		CGUIInOutFader(IGUIEnvironment* environment, IGUIElement* parent,
			s32 id, core::rect<s32> rectangle);

		//! draws the element and its children
		virtual void draw() override;

		//! Gets the color to fade out to or to fade in from.
		virtual video::SColor getColor() const override;

		//! Sets the color to fade out to or to fade in from.
		virtual void setColor(video::SColor color ) override;
		virtual void setColor(video::SColor source, video::SColor dest) override;

		//! Starts the fade in process.
		virtual void fadeIn(u32 time) override;

		//! Starts the fade out process.
		virtual void fadeOut(u32 time) override;

		//! Returns if the fade in or out process is done.
		virtual bool isReady() const override;

		//! Writes attributes of the element.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const override;

		//! Reads attributes of the element
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options) override;

	private:

		enum EFadeAction
		{
			EFA_NOTHING = 0,
			EFA_FADE_IN,
			EFA_FADE_OUT
		};

		u32 StartTime;
		u32 EndTime;
		EFadeAction Action;

		video::SColor Color[2];
		video::SColor FullColor;
		video::SColor TransColor;
	};

} // end namespace gui
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_GUI_

#endif // NIRT_C_GUI_IN_OUT_FADER_H_INCLUDED
