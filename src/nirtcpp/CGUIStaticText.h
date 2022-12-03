// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_GUI_STATIC_TEXT_H_INCLUDED
#define NIRT_C_GUI_STATIC_TEXT_H_INCLUDED

#include "IrrCompileConfig.h"
#ifdef _NIRT_COMPILE_WITH_GUI_

#include "IGUIStaticText.h"
#include "irrArray.h"

namespace irr
{
namespace gui
{
	class CGUIStaticText : public IGUIStaticText
	{
	public:

		//! constructor
		CGUIStaticText(const wchar_t* text, bool border, IGUIEnvironment* environment,
			IGUIElement* parent, s32 id, const core::rect<s32>& rectangle,
			bool background = false);

		//! destructor
		virtual ~CGUIStaticText();

		//! draws the element and its children
		virtual void draw() override;

		//! Sets another skin independent font.
		virtual void setOverrideFont(IGUIFont* font=0) override;

		//! Gets the override font (if any)
		virtual IGUIFont* getOverrideFont() const override;

		//! Get the font which is used right now for drawing
		virtual IGUIFont* getActiveFont() const override;

		//! Sets another color for the text.
		virtual void setOverrideColor(video::SColor color) override;

		//! Sets another color for the background.
		virtual void setBackgroundColor(video::SColor color) override;

		//! Sets whether to draw the background
		virtual void setDrawBackground(bool draw) override;

		//! Gets the background color
		virtual video::SColor getBackgroundColor() const override;

		//! Checks if background drawing is enabled
		virtual bool isDrawBackgroundEnabled() const override;

		//! Sets whether to draw the border
		virtual void setDrawBorder(bool draw) override;

		//! Checks if border drawing is enabled
		virtual bool isDrawBorderEnabled() const override;

		//! Sets alignment mode for text
		virtual void setTextAlignment(EGUI_ALIGNMENT horizontal, EGUI_ALIGNMENT vertical) override;

		//! Gets the override color
		virtual video::SColor getOverrideColor() const override;

		//! Gets the currently used text color
		virtual video::SColor getActiveColor() const override;

		//! Sets if the static text should use the override color or the
		//! color in the gui skin.
		virtual void enableOverrideColor(bool enable) override;

		//! Checks if an override color is enabled
		virtual bool isOverrideColorEnabled() const override;

		//! Set whether the text in this label should be clipped if it goes outside bounds
		virtual void setTextRestrainedInside(bool restrainedInside) override;

		//! Checks if the text in this label should be clipped if it goes outside bounds
		virtual bool isTextRestrainedInside() const override;

		//! Enables or disables word wrap for using the static text as
		//! multiline text control.
		virtual void setWordWrap(bool enable) override;

		//! Checks if word wrap is enabled
		virtual bool isWordWrapEnabled() const override;

		//! Sets the new caption of this element.
		virtual void setText(const wchar_t* text) override;

		//! Returns the height of the text in pixels when it is drawn.
		virtual s32 getTextHeight() const override;

		//! Returns the width of the current text, in the current font
		virtual s32 getTextWidth() const override;

		//! Updates the absolute position, splits text if word wrap is enabled
		virtual void updateAbsolutePosition() override;

		//! Set whether the string should be interpreted as right-to-left (RTL) text
		/** \note This component does not implement the Unicode bidi standard, the
		text of the component should be already RTL if you call this. The
		main difference when RTL is enabled is that the linebreaks for multiline
		elements are performed starting from the end.
		*/
		virtual void setRightToLeft(bool rtl) override;

		//! Checks if the text should be interpreted as right-to-left text
		virtual bool isRightToLeft() const override;

		//! Writes attributes of the element.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const override;

		//! Reads attributes of the element
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options) override;

	private:

		//! Breaks the single text line.
		void breakText();

		EGUI_ALIGNMENT HAlign, VAlign;
		bool Border;
		bool OverrideColorEnabled;
		bool OverrideBGColorEnabled;
		bool WordWrap;
		bool Background;
		bool RestrainTextInside;
		bool RightToLeft;

		video::SColor OverrideColor, BGColor;
		gui::IGUIFont* OverrideFont;
		gui::IGUIFont* LastBreakFont; // stored because: if skin changes, line break must be recalculated.

		core::array< core::stringw > BrokenText;
	};

} // end namespace gui
} // end namespace irr

#endif // _NIRT_COMPILE_WITH_GUI_

#endif
