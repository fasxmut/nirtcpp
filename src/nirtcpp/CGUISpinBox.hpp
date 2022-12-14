// Copyright (C) 2006-2012 Michael Zeilfelder
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_GUI_SPIN_BOX_H_INCLUDED
#define NIRT_C_GUI_SPIN_BOX_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>
#ifdef _NIRT_COMPILE_WITH_GUI_

#include <nirtcpp/IGUISpinBox.hpp>

namespace nirt
{
namespace gui
{
	class IGUIEditBox;
	class IGUIButton;

	class CGUISpinBox : public IGUISpinBox
	{
	public:

		//! constructor
		CGUISpinBox(const wchar_t* text, bool border, IGUIEnvironment* environment,
			IGUIElement* parent, s32 id, const core::rect<s32>& rectangle);

		//! destructor
		virtual ~CGUISpinBox();

		//! Access the edit box used in the spin control
		/** \param enable: If set to true, the override color, which can be set
		with IGUIEditBox::setOverrideColor is used, otherwise the
		EGDC_BUTTON_TEXT color of the skin. */
		virtual IGUIEditBox* getEditBox() const override;

		//! set the current value of the spinbox
		/** \param val: value to be set in the spinbox */
		virtual void setValue(f32 val) override;

		//! Get the current value of the spinbox
		virtual f32 getValue() const override;

		//! Get the value the spinbox would have for the given text
		virtual f32 getValueFor(const wchar_t* text) const override;

		//! set the range of values which can be used in the spinbox
		/** \param min: minimum value
		\param max: maximum value */
		virtual void setRange(f32 min, f32 max) override;

		//! get the minimum value which can be used in the spinbox
		virtual f32 getMin() const override;

		//! get the maximum value which can be used in the spinbox
		virtual f32 getMax() const override;

		//! step size by which values are changed when pressing the spin buttons
		/** \param step: stepsize used for value changes when pressing spin buttons */
		virtual void setStepSize(f32 step=1.f) override;

		//! returns the step size
		virtual f32 getStepSize() const override;

		//! called if an event happened.
		virtual bool OnEvent(const SEvent& event) override;

		//! Draws the element and its children.
		virtual void draw() override;

		//! Sets the new caption of the element
		virtual void setText(const wchar_t* text) override;

		//! Returns caption of this element.
		virtual const wchar_t* getText() const override;

		//! Sets the number of decimal places to display.
		//! Note that this also rounds the range to the same number of decimal places.
		/** \param places: The number of decimal places to display, use -1 to reset */
		virtual void setDecimalPlaces(s32 places) override;

		//! Sets when the spinbox has to validate entered text.
		/** \param validateOn Can be any combination of EGUI_SPINBOX_VALIDATION bit flags */
		virtual void setValidateOn(u32 validateOn) override;

		//! Gets when the spinbox has to validate entered text.
		virtual u32 getValidateOn() const override;

		//! Gets previous value in EGET_SPINBOX_CHANGED events
		virtual f32 getOldValue() const override
		{
			return OldValue;
		}

		//! Writes attributes of the element.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const override;

		//! Reads attributes of the element
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options) override;

	protected:
		void verifyValueRange(f32 val);
		void refreshSprites();

		IGUIEditBox * EditBox;
		IGUIButton * ButtonSpinUp;
		IGUIButton * ButtonSpinDown;
		video::SColor CurrentIconColor;
		f32 StepSize;
		f32 RangeMin;
		f32 RangeMax;

		core::stringw FormatString;
		s32 DecimalPlaces;
		u32 ValidateOn;	// combination of EGUI_SPINBOX_VALIDATION bit-flags
		f32 OldValue;
	};


} // end namespace gui
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_GUI_

#endif // NIRT_C_GUI_SPIN_BOX_H_INCLUDED
