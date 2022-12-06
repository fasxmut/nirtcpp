// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_GUI_CHECKBOX_H_INCLUDED
#define NIRT_C_GUI_CHECKBOX_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>
#ifdef _NIRT_COMPILE_WITH_GUI_

#include <nirtcpp/IGUICheckBox.hpp>

namespace nirt
{
namespace gui
{

	class CGUICheckBox : public IGUICheckBox
	{
	public:

		//! constructor
		CGUICheckBox(bool checked, IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle);

		//! set if box is checked
		virtual void setChecked(bool checked) override;

		//! returns if box is checked
		virtual bool isChecked() const override;

		//! Sets whether to draw the background
		virtual void setDrawBackground(bool draw) override;

		//! Checks if background drawing is enabled
		/** \return true if background drawing is enabled, false otherwise */
		virtual bool isDrawBackgroundEnabled() const override;

		//! Sets whether to draw the border
		virtual void setDrawBorder(bool draw) override;

		//! Checks if border drawing is enabled
		/** \return true if border drawing is enabled, false otherwise */
		virtual bool isDrawBorderEnabled() const override;

		//! called if an event happened.
		virtual bool OnEvent(const SEvent& event) override;

		//! draws the element and its children
		virtual void draw() override;

		//! Writes attributes of the element.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const override;

		//! Reads attributes of the element
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options) override;

	private:

		u32 CheckTime;
		bool Pressed;
		bool Checked;
		bool Border;
		bool Background;
	};

} // end namespace gui
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_GUI_

#endif // NIRT_C_GUI_CHECKBOX_H_INCLUDED
