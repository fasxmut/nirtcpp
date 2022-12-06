// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_OS_H_INCLUDED
#define NIRT_OS_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp> // for endian check
#include <nirtcpp/irrTypes.hpp>
#include <nirtcpp/irrString.hpp>
#include <nirtcpp/path.hpp>
#include <nirtcpp/ILogger.hpp>
#include <nirtcpp/ITimer.hpp>

namespace nirt
{

namespace os
{
	class Byteswap
	{
	public:
		static u16 byteswap(u16 num);
		static s16 byteswap(s16 num);
		static u32 byteswap(u32 num);
		static s32 byteswap(s32 num);
		static f32 byteswap(f32 num);
		// prevent accidental swapping of chars
		static u8  byteswap(u8  num);
		static c8  byteswap(c8  num);
	};

	class Printer
	{
	public:
		// prints out a string to the console out stdout or debug log or whatever
		static void print(const c8* message);
		static void log(const c8* message, ELOG_LEVEL ll = ELL_INFORMATION);
		static void log(const wchar_t* message, ELOG_LEVEL ll = ELL_INFORMATION);

		// The string ": " is added between message and hint
		static void log(const c8* message, const c8* hint, ELOG_LEVEL ll = ELL_INFORMATION);
		static void log(const c8* message, const io::path& hint, ELOG_LEVEL ll = ELL_INFORMATION);
		static ILogger* Logger;
	};


	// congruential pseudo-random generator
	// numbers identical to std::minstd_rand0
	// period is somewhere around m-1
	class Randomizer
	{
	public:

		//! resets the randomizer
		static void reset(s32 value=0x0f0f0f0f);

		//! generates a pseudo random number in the range 0..randMax()
		static s32 rand();

		//! generates a pseudo random number in the range 0..1
		static f32 frand();

		//! get maximum number generated by rand()
		static s32 randMax();

	private:

		static s32 seed;

		static const s32 m = 2147483647;	// a Mersenne prime (2^31-1)
		static const s32 a = 16807;			// another spectral success story
		static const s32 q = m/a;
		static const s32 r = m%a;			// again less than q
		static const s32 rMax = m-2;
	};




	class Timer
	{
	public:

		//! returns the current time in milliseconds
		static u32 getTime();

		//! get current time and date in calendar form
		static ITimer::RealTimeDate getRealTimeAndDate();

		//! initializes the real timer
		static void initTimer(bool usePerformanceTimer=true);

		//! sets the current virtual (game) time
		static void setTime(u32 time);

		//! stops the virtual (game) timer
		static void stopTimer();

		//! starts the game timer
		static void startTimer();

		//! sets the speed of the virtual timer
		static void setSpeed(f32 speed);

		//! gets the speed of the virtual timer
		static f32 getSpeed();

		//! returns if the timer currently is stopped
		static bool isStopped();

		//! makes the virtual timer update the time value based on the real time
		static void tick();

		//! returns the current real time in milliseconds
		static u32 getRealTime();

	private:

		static void initVirtualTimer();

		static f32 VirtualTimerSpeed;
		static s32 VirtualTimerStopCounter;
		static u32 StartRealTime;
		static u32 LastVirtualTime;
		static u32 StaticTime;
	};

} // end namespace os
} // end namespace nirt

#endif
