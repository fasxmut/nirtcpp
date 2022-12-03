// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_E_DEVICE_TYPES_H_INCLUDED
#define NIRT_E_DEVICE_TYPES_H_INCLUDED

namespace nirt
{

	//! An enum for the different device types supported by the Nirtcpp Engine.
	enum E_DEVICE_TYPE
	{

		//! A device native to Microsoft Windows
		/** This device uses the Win32 API and works in all versions of Windows. */
		EIDT_WIN32,

		//! A device native to Windows CE devices
		/** This device works on Windows Mobile, Pocket PC and Microsoft SmartPhone devices */
		EIDT_WINCE,

		//! A device native to Unix style operating systems.
		/** This device uses the X11 windowing system and works in Linux, Solaris, FreeBSD, OSX and
		other operating systems which support X11. */
		EIDT_X11,

		//! A device native to Mac OSX
		/** This device uses Apple's Cocoa API and works in Mac OSX 10.2 and above. */
		EIDT_OSX,

		//! A device which uses Simple DirectMedia Layer
		/** The SDL device works under all platforms supported by SDL but first must be compiled
		in by defining the _NIRT_COMPILE_WITH_SDL_DEVICE_ macro in IrrCompileConfig.h */
		EIDT_SDL,

		//! A device for raw framebuffer access
		/** Best used with embedded devices and mobile systems.
		Does not need X11 or other graphical subsystems.
		May support hw-acceleration via OpenGL-ES for FBDirect */
		EIDT_FRAMEBUFFER,

		//! A simple text only device supported by all platforms.
		/** This device allows applications to run from the command line without opening a window.
		It can render the output of the software drivers to the console as ASCII. It only supports
		mouse and keyboard in Windows operating systems. */
		EIDT_CONSOLE,

		//! This selection allows Nirtcpp to choose the best device from the ones available.
		/** If this selection is chosen then Nirtcpp will try to use the NirtcppDevice native
		to your operating system. If this is unavailable then the X11, SDL and then console device
		will be tried. This ensures that Nirtcpp will run even if your platform is unsupported,
		although it may not be able to render anything. */
		EIDT_BEST
	};

} // end namespace nirt

#endif // NIRT_E_DEVICE_TYPES_H_INCLUDED
