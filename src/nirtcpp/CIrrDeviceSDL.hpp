// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp
// This device code is based on the original SDL device implementation
// contributed by Shane Parker (sirshane).

#ifndef NIRT_C_NIRT_DEVICE_SDL_H_INCLUDED
#define NIRT_C_NIRT_DEVICE_SDL_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>

#ifdef _NIRT_COMPILE_WITH_SDL_DEVICE_

#include <nirtcpp/NirtcppDevice.hpp>
#include "CIrrDeviceStub.hpp"
#include "IImagePresenter.hpp"
#include <nirtcpp/ICursorControl.hpp>

#include <SDL/SDL.h>
#include <SDL/SDL_syswm.h>

namespace nirt
{

	class CIrrDeviceSDL : public CIrrDeviceStub, video::IImagePresenter
	{
	public:

		//! constructor
		CIrrDeviceSDL(const SNirtcppCreationParameters& param);

		//! destructor
		virtual ~CIrrDeviceSDL();

		//! runs the device. Returns false if device wants to be deleted
		virtual bool run() override;

		//! pause execution temporarily
		virtual void yield() override;

		//! pause execution for a specified time
		virtual void sleep(u32 timeMs, bool pauseTimer) override;

		//! sets the caption of the window
		virtual void setWindowCaption(const wchar_t* text) override;

		//! returns if window is active. if not, nothing need to be drawn
		virtual bool isWindowActive() const override;

		//! returns if window has focus.
		bool isWindowFocused() const override;

		//! returns if window is minimized.
		bool isWindowMinimized() const override;

		//! returns color format of the window.
		video::ECOLOR_FORMAT getColorFormat() const override;

		//! presents a surface in the client area
		virtual bool present(video::IImage* surface, void* windowId=0, core::rect<s32>* src=0) override;

		//! notifies the device that it should close itself
		virtual void closeDevice() override;

		//! \return Returns a pointer to a list with all video modes supported
		virtual video::IVideoModeList* getVideoModeList() override;

		//! Sets if the window should be resizable in windowed mode.
		virtual void setResizable(bool resize=false) override;

		//! Minimizes the window.
		virtual void minimizeWindow() override;

		//! Maximizes the window.
		virtual void maximizeWindow() override;

		//! Restores the window size.
		virtual void restoreWindow() override;

		//! Get the position of this window on screen
		virtual core::position2di getWindowPosition() override;

		//! Activate any joysticks, and generate events for them.
		virtual bool activateJoysticks(core::array<SJoystickInfo> & joystickInfo) override;

		//! Set the current Gamma Value for the Display
		virtual bool setGammaRamp( f32 red, f32 green, f32 blue, f32 brightness, f32 contrast ) override;

		//! Get the current Gamma Value for the Display
		virtual bool getGammaRamp( f32 &red, f32 &green, f32 &blue, f32 &brightness, f32 &contrast ) override;

		//! Get the device type
		virtual E_DEVICE_TYPE getType() const override
		{
			return EIDT_SDL;
		}

		//! Implementation of the linux cursor control
		class CCursorControl : public gui::ICursorControl
		{
		public:

			CCursorControl(CIrrDeviceSDL* dev)
				: Device(dev), IsVisible(true)
			{
			}

			//! Changes the visible state of the mouse cursor.
			virtual void setVisible(bool visible) override
			{
				IsVisible = visible;
				if ( visible )
					SDL_ShowCursor( SDL_ENABLE );
				else
					SDL_ShowCursor( SDL_DISABLE );
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
				setPosition((s32)(x*Device->Width), (s32)(y*Device->Height));
			}

			//! Sets the new position of the cursor.
			virtual void setPosition(const core::position2d<s32> &pos) override
			{
				setPosition(pos.X, pos.Y);
			}

			//! Sets the new position of the cursor.
			virtual void setPosition(s32 x, s32 y) override
			{
				SDL_WarpMouse( x, y );
				CursorPos.X = x;
				CursorPos.Y = y;
			}

			//! Returns the current position of the mouse cursor.
			virtual const core::position2d<s32>& getPosition(bool updateCursor) override
			{
				if ( updateCursor )
					updateCursorPos();
				return CursorPos;
			}

			//! Returns the current position of the mouse cursor.
			virtual core::position2d<f32> getRelativePosition(bool updateCursor) override
			{
				if ( updateCursor )
					updateCursorPos();
				return core::position2d<f32>(CursorPos.X / (f32)Device->Width,
					CursorPos.Y / (f32)Device->Height);
			}

			virtual void setReferenceRect(core::rect<s32>* rect=0) override
			{
			}

		private:

			void updateCursorPos()
			{
				CursorPos.X = Device->MouseX;
				CursorPos.Y = Device->MouseY;
			}

			CIrrDeviceSDL* Device;
			core::position2d<s32> CursorPos;
			bool IsVisible;
		};

	private:

		//! create the driver
		void createDriver();

		bool createWindow();

		void createKeyMap();

		SDL_Surface* Screen;
		int SDL_Flags;
#if defined(_NIRT_COMPILE_WITH_JOYSTICK_EVENTS_)
		core::array<SDL_Joystick*> Joysticks;
#endif

		s32 MouseX, MouseY;
		u32 MouseButtonStates;

		u32 Width, Height;

		bool Resizable;
		bool WindowMinimized;

		struct SKeyMap
		{
			SKeyMap() {}
			SKeyMap(s32 x11, s32 win32)
				: SDLKey(x11), Win32Key(win32)
			{
			}

			s32 SDLKey;
			s32 Win32Key;

			bool operator<(const SKeyMap& o) const
			{
				return SDLKey<o.SDLKey;
			}
		};

		core::array<SKeyMap> KeyMap;
		SDL_SysWMinfo Info;
	};

} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_SDL_DEVICE_
#endif // NIRT_C_NIRT_DEVICE_SDL_H_INCLUDED
