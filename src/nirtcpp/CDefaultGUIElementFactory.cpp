// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#include "CDefaultGUIElementFactory.hpp"

#ifdef _NIRT_COMPILE_WITH_GUI_

#include <nirtcpp/IGUIEnvironment.hpp>

#include <nirtcpp/IGUIButton.hpp>
#include <nirtcpp/IGUICheckBox.hpp>
#include <nirtcpp/IGUIColorSelectDialog.hpp>
#include <nirtcpp/IGUIComboBox.hpp>
#include <nirtcpp/IGUIContextMenu.hpp>
#include <nirtcpp/IGUIEditBox.hpp>
#include <nirtcpp/IGUIFileOpenDialog.hpp>
#include <nirtcpp/IGUIInOutFader.hpp>
#include <nirtcpp/IGUIImage.hpp>
#include <nirtcpp/IGUIListBox.hpp>
#include <nirtcpp/IGUIMeshViewer.hpp>
#include <nirtcpp/IGUIScrollBar.hpp>
#include <nirtcpp/IGUISpinBox.hpp>
#include <nirtcpp/IGUIStaticText.hpp>
#include <nirtcpp/IGUITabControl.hpp>
#include <nirtcpp/IGUITable.hpp>
#include <nirtcpp/IGUIToolbar.hpp>
#include <nirtcpp/IGUIWindow.hpp>
#include <nirtcpp/IGUITreeView.hpp>
#include <nirtcpp/IGUIProfiler.hpp>

namespace nirt
{
namespace gui
{

CDefaultGUIElementFactory::CDefaultGUIElementFactory(IGUIEnvironment* env)
: Environment(env)
{

	#ifdef _DEBUG
	setDebugName("CDefaultGUIElementFactory");
	#endif

	// don't grab the gui environment here to prevent cyclic references
}


//! adds an element to the env based on its type id
IGUIElement* CDefaultGUIElementFactory::addGUIElement(EGUI_ELEMENT_TYPE type, IGUIElement* parent)
{
	switch(type)
	{
		case EGUIET_BUTTON:
			return Environment->addButton(core::rect<s32>(0,0,100,100),parent);
		case EGUIET_CHECK_BOX:
			return Environment->addCheckBox(false, core::rect<s32>(0,0,100,100), parent);
		case EGUIET_COLOR_SELECT_DIALOG:
			return Environment->addColorSelectDialog(0,true,parent);
		case EGUIET_COMBO_BOX:
			return Environment->addComboBox(core::rect<s32>(0,0,100,100),parent);
		case EGUIET_CONTEXT_MENU:
			return Environment->addContextMenu(core::rect<s32>(0,0,100,100),parent);
		case EGUIET_MENU:
			return Environment->addMenu(parent);
		case EGUIET_EDIT_BOX:
			return Environment->addEditBox(0,core::rect<s32>(0,0,100,100),true, parent);
		case EGUIET_FILE_OPEN_DIALOG:
			return Environment->addFileOpenDialog(0,true,parent);
		case EGUIET_IMAGE:
			return Environment->addImage(0,core::position2di(0,0), true, parent);
		case EGUIET_IN_OUT_FADER:
			return Environment->addInOutFader(0,parent);
		case EGUIET_LIST_BOX:
			return Environment->addListBox(core::rect<s32>(0,0,100,100),parent);
		case EGUIET_MESH_VIEWER:
			return Environment->addMeshViewer(core::rect<s32>(0,0,100,100),parent);
		case EGUIET_MODAL_SCREEN:
			return Environment->addModalScreen(parent);
		case EGUIET_MESSAGE_BOX:
			return Environment->addMessageBox(0,0,false,0,parent);
		case EGUIET_SCROLL_BAR:
			return Environment->addScrollBar(false,core::rect<s32>(0,0,100,100),parent);
		case EGUIET_STATIC_TEXT:
			return Environment->addStaticText(0,core::rect<s32>(0,0,100,100),false,true,parent);
		case EGUIET_TAB:
			return Environment->addTab(core::rect<s32>(0,0,100,100),parent);
		case EGUIET_TAB_CONTROL:
			return Environment->addTabControl(core::rect<s32>(0,0,100,100),parent);
		case EGUIET_TABLE:
			return Environment->addTable(core::rect<s32>(0,0,100,100), parent);
		case EGUIET_TOOL_BAR:
			return Environment->addToolBar(parent);
		case EGUIET_WINDOW:
			return Environment->addWindow(core::rect<s32>(0,0,100,100),false,0,parent);
		case EGUIET_SPIN_BOX:
			return Environment->addSpinBox(L"0.0", core::rect<s32>(0,0,100,100), true, parent);
		case EGUIET_TREE_VIEW:
			return Environment->addTreeView(core::rect<s32>(0,0,100,100),parent);
		case EGUIET_PROFILER:
			return Environment->addProfilerDisplay(core::rect<s32>(0,0,100,100), parent);
		default:
 			return 0;
	}
}


//! adds an element to the environment based on its type name
IGUIElement* CDefaultGUIElementFactory::addGUIElement(const c8* typeName, IGUIElement* parent)
{
	return addGUIElement( getTypeFromName(typeName), parent );
}


//! Returns the amount of element types this factory is able to create.
s32 CDefaultGUIElementFactory::getCreatableGUIElementTypeCount() const
{
	return EGUIET_COUNT;
}


//! Returns the type of a creatable element type.
EGUI_ELEMENT_TYPE CDefaultGUIElementFactory::getCreateableGUIElementType(s32 idx) const
{
	if (idx>=0 && idx<EGUIET_COUNT)
		return (EGUI_ELEMENT_TYPE)idx;

	return EGUIET_ELEMENT;
}


//! Returns the type name of a creatable element type.
const c8* CDefaultGUIElementFactory::getCreateableGUIElementTypeName(s32 idx) const
{
	if (idx>=0 && idx<EGUIET_COUNT)
		return GUIElementTypeNames[idx];

	return 0;
}


//! Returns the type name of a creatable element type.
const c8* CDefaultGUIElementFactory::getCreateableGUIElementTypeName(EGUI_ELEMENT_TYPE type) const
{
	// for this factory, type == index

	if (type>=0 && type<EGUIET_COUNT)
		return GUIElementTypeNames[type];

	return 0;
}

EGUI_ELEMENT_TYPE CDefaultGUIElementFactory::getTypeFromName(const c8* name) const
{
	for ( u32 i=0; GUIElementTypeNames[i]; ++i)
		if (!strcmp(name, GUIElementTypeNames[i]) )
			return (EGUI_ELEMENT_TYPE)i;

	return EGUIET_ELEMENT;
}


} // end namespace gui
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_GUI_

