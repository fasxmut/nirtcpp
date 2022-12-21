// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_I_GUI_CHECKBOX_H_INCLUDED
#define NIRT_I_GUI_CHECKBOX_H_INCLUDED

#include <nirtcpp/IGUIElement.hpp>

namespace nirt
{
namespace gui
{

	//! GUI Check box interface.
	/** \par This element can create the following events of type EGUI_EVENT_TYPE:
	\li EGET_CHECKBOX_CHANGED
	*/
	class IGUICheckBox : public IGUIElement
	{
	public:

		//! constructor
		IGUICheckBox(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_CHECK_BOX, environment, parent, id, rectangle) {}

		//! Set if box is checked.
		virtual void setChecked(bool checked) = 0;

		//! Returns true if box is checked.
		virtual bool isChecked() const = 0;

		//! Sets whether to draw the background
		virtual void setDrawBackground(bool draw) = 0;

		//! Checks if background drawing is enabled
		/** \return true if background drawing is enabled, false otherwise */
		virtual bool isDrawBackgroundEnabled() const = 0;

		//! Sets whether to draw the border
		virtual void setDrawBorder(bool draw) = 0;

		//! Checks if border drawing is enabled
		/** \return true if border drawing is enabled, false otherwise */
		virtual bool isDrawBorderEnabled() const = 0;

	};

} // end namespace gui
} // end namespace nirt

#endif