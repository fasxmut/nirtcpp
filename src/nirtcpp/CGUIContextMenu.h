// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_GUI_CONTEXT_MENU_H_INCLUDED
#define NIRT_C_GUI_CONTEXT_MENU_H_INCLUDED

#include "IrrCompileConfig.h"
#ifdef _NIRT_COMPILE_WITH_GUI_

#include "IGUIContextMenu.h"
#include "irrString.h"
#include "irrArray.h"
#include "IGUIFont.h"

namespace nirt
{
namespace gui
{

	//! GUI Context menu interface.
	class CGUIContextMenu : public IGUIContextMenu
	{
	public:

		//! constructor
		CGUIContextMenu(IGUIEnvironment* environment,
			IGUIElement* parent, s32 id, core::rect<s32> rectangle,
			bool getFocus = true, bool allowFocus = true);

		//! destructor
		virtual ~CGUIContextMenu();

		//! set behavior when menus are closed
		virtual void setCloseHandling(ECONTEXT_MENU_CLOSE onClose) override;

		//! get current behavior when the menue will be closed
		virtual ECONTEXT_MENU_CLOSE getCloseHandling() const override;

		//! Returns amount of menu items
		virtual u32 getItemCount() const override;

		//! Adds a menu item.
		virtual u32 addItem(const wchar_t* text, s32 commandid,
				bool enabled, bool hasSubMenu, bool checked, bool autoChecking) override;

		//! Insert a menu item at specified position.
		virtual u32 insertItem(u32 idx, const wchar_t* text, s32 commandId, bool enabled,
			bool hasSubMenu, bool checked, bool autoChecking) override;

		//! Find a item which has the given CommandId starting from given index
		virtual s32 findItemWithCommandId(s32 commandId, u32 idxStartSearch) const override;

		//! Adds a separator item to the menu
		virtual void addSeparator() override;

		//! Returns text of the menu item.
		virtual const wchar_t* getItemText(u32 idx) const override;

		//! Sets text of the menu item.
		virtual void setItemText(u32 idx, const wchar_t* text) override;

		//! Returns if a menu item is enabled
		virtual bool isItemEnabled(u32 idx) const override;

		//! Sets if the menu item should be enabled.
		virtual void setItemEnabled(u32 idx, bool enabled) override;

		//! Returns if a menu item is checked
		virtual bool isItemChecked(u32 idx) const override;

		//! Sets if the menu item should be checked.
		virtual void setItemChecked(u32 idx, bool enabled) override;

		//! Removes a menu item
		virtual void removeItem(u32 idx) override;

		//! Removes all menu items
		virtual void removeAllItems() override;

		//! called if an event happened.
		virtual bool OnEvent(const SEvent& event) override;

		//! draws the element and its children
		virtual void draw() override;

		//! Returns the selected item in the menu
		virtual s32 getSelectedItem() const override;

		//! Returns a pointer to the submenu of an item.
		//! \return Pointer to the submenu of an item.
		virtual IGUIContextMenu* getSubMenu(u32 idx) const override;

		//! Sets the visible state of this element.
		virtual void setVisible(bool visible) override;

		//! should the element change the checked status on clicking
		virtual void setItemAutoChecking(u32 idx, bool autoChecking) override;

		//! does the element change the checked status on clicking
		virtual bool getItemAutoChecking(u32 idx) const override;

		//! Returns command id of a menu item
		virtual s32 getItemCommandId(u32 idx) const override;

		//! Sets the command id of a menu item
		virtual void setItemCommandId(u32 idx, s32 id) override;

		//! Adds a sub menu from an element that already exists.
		virtual void setSubMenu(u32 index, CGUIContextMenu* menu);

		//! When an eventparent is set it receives events instead of the usual parent element
		virtual void setEventParent(IGUIElement *parent) override;

		//! Writes attributes of the element.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const override;

		//! Reads attributes of the element
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options) override;

	protected:

		void closeAllSubMenus();
		bool hasOpenSubMenu() const;

		struct SItem
		{
			core::stringw Text;
			bool IsSeparator;
			bool Enabled;
			bool Checked;
			bool AutoChecking;
			core::dimension2d<u32> Dim;
			s32 PosY;
			CGUIContextMenu* SubMenu;
			s32 CommandId;
		};

		virtual void recalculateSize();

		//! returns true, if an element was highlighted
		virtual bool highlight(const core::position2d<s32>& p, bool canOpenSubMenu);

		//! sends a click Returns:
		//! 0 if click went outside of the element,
		//! 1 if a valid button was clicked,
		//! 2 if a nonclickable element was clicked
		virtual u32 sendClick(const core::position2d<s32>& p);

		//! returns the item highlight-area
		virtual core::rect<s32> getHRect(const SItem& i, const core::rect<s32>& absolute) const;

		//! Gets drawing rect of Item
		virtual core::rect<s32> getRect(const SItem& i, const core::rect<s32>& absolute) const;


		core::array<SItem> Items;
		core::position2d<s32> Pos;
		IGUIElement* EventParent;
		IGUIFont *LastFont;
		ECONTEXT_MENU_CLOSE CloseHandling;
		s32 HighLighted;
		u32 ChangeTime;
		bool AllowFocus;
	};


} // end namespace gui
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_GUI_

#endif // NIRT_C_GUI_CONTEXT_MENU_H_INCLUDED
