// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_GUI_MENU_H_INCLUDED
#define NIRT_C_GUI_MENU_H_INCLUDED

#include "IrrCompileConfig.h"
#ifdef _NIRT_COMPILE_WITH_GUI_

#include "CGUIContextMenu.h"

namespace irr
{
namespace gui
{

	//! GUI menu interface.
	class CGUIMenu : public CGUIContextMenu
	{
	public:

		//! constructor
		CGUIMenu(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle);

		//! draws the element and its children
		virtual void draw() override;

		//! called if an event happened.
		virtual bool OnEvent(const SEvent& event) override;

		//! Updates the absolute position.
		virtual void updateAbsolutePosition() override;

	protected:

		virtual void recalculateSize() override;

		//! returns the item highlight-area
		virtual core::rect<s32> getHRect(const SItem& i, const core::rect<s32>& absolute) const override;

		//! Gets drawing rect of Item
		virtual core::rect<s32> getRect(const SItem& i, const core::rect<s32>& absolute) const override;
	};

} // end namespace gui
} // end namespace irr

#endif // _NIRT_COMPILE_WITH_GUI_
#endif //  NIRT_C_GUI_MENU_H_INCLUDED
