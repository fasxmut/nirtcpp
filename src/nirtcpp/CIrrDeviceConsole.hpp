// Copyright (C) 2009-2012 Gaz Davidson
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_NIRT_DEVICE_CONSOLE_H_INCLUDED
#define NIRT_C_NIRT_DEVICE_CONSOLE_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>
#ifdef _NIRT_COMPILE_WITH_CONSOLE_DEVICE_

//#define _NIRT_USE_CONSOLE_FONT_

#include <nirtcpp/SIrrCreationParameters.hpp>
#include "CIrrDeviceStub.hpp"
#include "IImagePresenter.hpp"
// for console font
#include <nirtcpp/IGUIFont.hpp>

#ifdef _NIRT_WINDOWS_API_
#define WIN32_LEAN_AND_MEAN
#if !defined(_NIRT_XBOX_PLATFORM_)
	#include <windows.h>
#endif
#if(_WIN32_WINNT >= 0x0500)
#define _NIRT_WINDOWS_NT_CONSOLE_
#endif
#else
#include <time.h>
#endif

// for now we assume all other terminal types are VT100
#ifndef _NIRT_WINDOWS_NT_CONSOLE_
#define _NIRT_VT100_CONSOLE_
#endif

namespace nirt
{

	class CIrrDeviceConsole : public CIrrDeviceStub, video::IImagePresenter
	{
	public:

		//! constructor
		CIrrDeviceConsole(const SNirtcppCreationParameters& params);

		//! destructor
		virtual ~CIrrDeviceConsole();

		//! runs the device. Returns false if device wants to be deleted
		virtual bool run() override;

		//! Cause the device to temporarily pause execution and let other processes to run
		// This should bring down processor usage without major performance loss for Nirtcpp
		virtual void yield() override;

		//! Pause execution and let other processes to run for a specified amount of time.
		virtual void sleep(u32 timeMs, bool pauseTimer) override;

		//! sets the caption of the window
		virtual void setWindowCaption(const wchar_t* text) override;

		//! returns if window is active. if not, nothing need to be drawn
		virtual bool isWindowActive() const override;

		//! returns if window has focus
		virtual bool isWindowFocused() const override;

		//! returns if window is minimized
		virtual bool isWindowMinimized() const override;

		//! returns current window position (not supported for this device)
		virtual core::position2di getWindowPosition() override
		{
			return core::position2di(-1, -1);
		}

		//! presents a surface in the client area
		virtual bool present(video::IImage* surface, void* windowId=0, core::rect<s32>* src=0) override;

		//! notifies the device that it should close itself
		virtual void closeDevice() override;

		//! Sets if the window should be resizable in windowed mode.
		virtual void setResizable(bool resize=false) override;

		//! Minimizes the window.
		virtual void minimizeWindow() override;

		//! Maximizes the window.
		virtual void maximizeWindow() override;

		//! Restores the window size.
		virtual void restoreWindow() override;

		//! Get the device type
		virtual E_DEVICE_TYPE getType() const override
		{
			return EIDT_CONSOLE;
		}

		void addPostPresentText(s16 X, s16 Y, const wchar_t *text);

		//! Implementation of the win32 console mouse cursor
		class CCursorControl : public gui::ICursorControl
		{
		public:

			CCursorControl(const core::dimension2d<u32>& wsize)
				: WindowSize(wsize), InvWindowSize(0.0f, 0.0f), IsVisible(true), UseReferenceRect(false)
			{
				if (WindowSize.Width!=0)
					InvWindowSize.Width = 1.0f / WindowSize.Width;

				if (WindowSize.Height!=0)
					InvWindowSize.Height = 1.0f / WindowSize.Height;
			}

			//! Changes the visible state of the mouse cursor.
			virtual void setVisible(bool visible) override
			{
				if(visible != IsVisible)
				{
					IsVisible = visible;
					setPosition(CursorPos.X, CursorPos.Y);
				}
			}

			//! Returns if the cursor is currently visible.
			virtual bool isVisible() const override
			{
				return IsVisible;
			}

			//! Sets the new position of the cursor.
			virtual void setPosition(const core::position2d<f32> &pos) override
			{
				setPosition(pos.X, pos.Y);
			}

			//! Sets the new position of the cursor.
			virtual void setPosition(f32 x, f32 y) override
			{
				if (!UseReferenceRect)
					setPosition((s32)(x*WindowSize.Width), (s32)(y*WindowSize.Height));
				else
					setPosition((s32)(x*ReferenceRect.getWidth()), (s32)(y*ReferenceRect.getHeight()));
			}

			//! Sets the new position of the cursor.
			virtual void setPosition(const core::position2d<s32> &pos) override
			{
				setPosition(pos.X, pos.Y);
			}

			//! Sets the new position of the cursor.
			virtual void setPosition(s32 x, s32 y) override
			{
				setInternalCursorPosition(core::position2di(x,y));
			}

			//! Returns the current position of the mouse cursor.
			virtual const core::position2d<s32>& getPosition(bool updateCursor) override
			{
				return CursorPos;
			}

			//! Returns the current position of the mouse cursor.
			virtual core::position2d<f32> getRelativePosition(bool updateCursor) override
			{
				if (!UseReferenceRect)
				{
					return core::position2d<f32>(CursorPos.X * InvWindowSize.Width,
						CursorPos.Y * InvWindowSize.Height);
				}

				return core::position2d<f32>(CursorPos.X / (f32)ReferenceRect.getWidth(),
						CursorPos.Y / (f32)ReferenceRect.getHeight());
			}

			//! Sets an absolute reference rect for calculating the cursor position.
			virtual void setReferenceRect(core::rect<s32>* rect=0) override
			{
				if (rect)
				{
					ReferenceRect = *rect;
					UseReferenceRect = true;

					// prevent division through zero and uneven sizes

					if (!ReferenceRect.getHeight() || ReferenceRect.getHeight()%2)
						ReferenceRect.LowerRightCorner.Y += 1;

					if (!ReferenceRect.getWidth() || ReferenceRect.getWidth()%2)
						ReferenceRect.LowerRightCorner.X += 1;
				}
				else
					UseReferenceRect = false;
			}


			//! Updates the internal cursor position
			void setInternalCursorPosition(const core::position2di &pos)
			{
				CursorPos = pos;

				if (UseReferenceRect)
					CursorPos -= ReferenceRect.UpperLeftCorner;
			}

		private:

			core::position2d<s32>  CursorPos;
			core::dimension2d<u32> WindowSize;
			core::dimension2d<f32> InvWindowSize;
			bool                   IsVisible;
			bool                   UseReferenceRect;
			core::rect<s32>        ReferenceRect;
		};

	private:

		//! Set the position of the text caret
		void setTextCursorPos(s16 x, s16 y);

		// text to be added after drawing the screen
		struct SPostPresentText
		{
			core::position2d<s16> Pos;
			core::stringc         Text;
		};

		bool IsWindowFocused;

		core::array<core::stringc> OutputBuffer;
		gui::IGUIFont  *ConsoleFont;
		core::array<SPostPresentText> Text;

		FILE *OutFile;

#ifdef _NIRT_WINDOWS_NT_CONSOLE_
		HANDLE WindowsSTDIn, WindowsSTDOut;
		u32 MouseButtonStates;
#endif
	};

#ifdef _NIRT_USE_CONSOLE_FONT_

namespace gui
{
	class CGUIConsoleFont : public IGUIFont
	{
	public:

		CGUIConsoleFont(CIrrDeviceConsole* device) : Device(device) { }

		//! Draws some text and clips it to the specified rectangle if wanted.
		virtual void draw(const wchar_t* text, const core::rect<s32>& position,
			video::SColor color, bool hcenter=false, bool vcenter=false,
			const core::rect<s32>* clip=0) override
		{
			core::rect<s32> Area = clip ? *clip : position;

			if (Area.UpperLeftCorner.X < 0)
				Area.UpperLeftCorner.X = 0;

			if (Area.UpperLeftCorner.Y < 0)
				Area.UpperLeftCorner.Y = 0;

			core::position2d<s16> pos;

			// centre vertically
			pos.Y = vcenter ? (position.UpperLeftCorner.Y + position.LowerRightCorner.Y) / 2 : position.UpperLeftCorner.Y;

			// nothing to display?
			if (pos.Y < Area.UpperLeftCorner.Y || pos.Y > Area.LowerRightCorner.Y)
				return;

			tempText = text;

			// centre horizontally
			pos.X = hcenter ? position.getCenter().X - ( tempText.size() / 2) : position.UpperLeftCorner.X;

			// clip
			u32 xlclip = 0,
				xrclip = 0;

			// get right clip
			if (pos.X + (s32)tempText.size() > Area.LowerRightCorner.X)
				xrclip = Area.LowerRightCorner.X - pos.X;

			// get left clip
			if (pos.X < Area.UpperLeftCorner.X)
				xlclip = Area.UpperLeftCorner.X - pos.X;

			// totally clipped?
			if ((s32)tempText.size() - xlclip - xrclip < 0)
				return;

			// null terminate the string
			if (xrclip > 0)
				tempText[xrclip] = L'\0';

			Device->addPostPresentText(pos.X + xlclip, pos.Y, &(tempText.data()[xlclip]));
		}

		//! Calculates the dimension of some text.
		virtual core::dimension2d<u32> getDimension(const wchar_t* text) const override
		{
			return core::dimension2d<u32>(wcslen(text),1);
		}

		//! Calculates the index of the character in the text which is on a specific position.
		virtual s32 getCharacterFromPos(const wchar_t* text, s32 pixel_x) const override { return pixel_x; } override;

		//! No kerning
		virtual void setKerningWidth (s32 kerning) override { }
		virtual void setKerningHeight (s32 kerning) override { }
		virtual s32 getKerningWidth(const wchar_t* thisLetter=0, const wchar_t* previousLetter=0) const override {return 0;}
		virtual s32 getKerningHeight() const  override { return 0;}
		virtual void setInvisibleCharacters( const wchar_t *s ) override { }
		// I guess this is an OS specific font
		virtual EGUI_FONT_TYPE getType() const override { return EGFT_OS; }
	private:
		CIrrDeviceConsole* Device;
		core::stringw tempText;
	};

} // end namespace gui

#endif // _NIRT_USE_CONSOLE_FONT_

} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_CONSOLE_DEVICE_
#endif // NIRT_C_NIRT_DEVICE_CONSOLE_H_INCLUDED
