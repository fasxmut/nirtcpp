// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_GUI_COLOR_SELECT_DIALOG_H_INCLUDED
#define NIRT_C_GUI_COLOR_SELECT_DIALOG_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>
#ifdef _NIRT_COMPILE_WITH_GUI_

#include <nirtcpp/IGUIColorSelectDialog.hpp>
#include <nirtcpp/IGUIButton.hpp>
#include <nirtcpp/IGUISpinBox.hpp>
#include <nirtcpp/IGUIImage.hpp>
#include <nirtcpp/irrArray.hpp>


namespace nirt
{
namespace gui
{

	class CGUIColorSelectDialog : public IGUIColorSelectDialog
	{
	public:

		//! constructor
		CGUIColorSelectDialog(const wchar_t* title, IGUIEnvironment* environment, IGUIElement* parent, s32 id);

		//! destructor
		virtual ~CGUIColorSelectDialog();

		//! called if an event happened.
		virtual bool OnEvent(const SEvent& event) override;

		//! draws the element and its children
		virtual void draw() override;

		virtual video::SColor getColor() override;
		virtual video::SColorHSL getColorHSL() override;

	private:

		//! sends the event that the file has been selected.
		void sendSelectedEvent();

		//! sends the event that the file choose process has been canceld
		void sendCancelEvent();

		core::position2d<s32> DragStart;
		bool Dragging;
		IGUIButton* CloseButton;
		IGUIButton* OKButton;
		IGUIButton* CancelButton;

		core::array<IGUISpinBox*> Battery;

		struct SColorCircle
		{
			IGUIImage * Control;
			video::ITexture * Texture;
		};
		SColorCircle ColorRing;

		void buildColorRing( const core::dimension2d<u32> & dim, s32 supersample, const video::SColor& borderColor );
	};


} // end namespace gui
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_GUI_

#endif // NIRT_C_GUI_COLOR_SELECT_DIALOG_H_INCLUDED
