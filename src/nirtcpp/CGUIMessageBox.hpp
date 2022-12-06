// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_GUI_MESSAGE_BOX_H_INCLUDED
#define NIRT_C_GUI_MESSAGE_BOX_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>
#ifdef _NIRT_COMPILE_WITH_GUI_

#include "CGUIWindow.hpp"
#include <nirtcpp/IGUIStaticText.hpp>
#include <nirtcpp/IGUIImage.hpp>
#include <nirtcpp/irrArray.hpp>

namespace nirt
{
namespace gui
{
	class CGUIMessageBox : public CGUIWindow
	{
	public:

		//! constructor
		CGUIMessageBox(IGUIEnvironment* environment, const wchar_t* caption,
			const wchar_t* text, s32 flag,
			IGUIElement* parent, s32 id, core::rect<s32> rectangle, video::ITexture* image=0);

		//! destructor
		virtual ~CGUIMessageBox();

		//! called if an event happened.
		virtual bool OnEvent(const SEvent& event) override;

		//! Writes attributes of the element.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const override;

		//! Reads attributes of the element
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options) override;

	private:

		void refreshControls();
		void setButton(IGUIButton*& button, bool isAvailable, const core::rect<s32> & btnRect, const wchar_t * text, IGUIElement*& focusMe);

		IGUIButton* OkButton;
		IGUIButton* CancelButton;
		IGUIButton* YesButton;
		IGUIButton* NoButton;
		IGUIStaticText* StaticText;
		IGUIImage * Icon;
		video::ITexture * IconTexture;

		s32 Flags;
		core::stringw MessageText;
		bool Pressed;
	};

} // end namespace gui
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_GUI_

#endif
