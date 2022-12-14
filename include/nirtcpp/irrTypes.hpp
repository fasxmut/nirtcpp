// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_TYPES_H_INCLUDED
#define NIRT_TYPES_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>

#if defined(__GNUC__)
	// For __WORDSIZE (which we maybe don't even need anymore with LP64 checks now)
	#include <limits.h>
#endif

namespace nirt
{

//! 8 bit unsigned variable.
/** This is a using type alias for unsigned char, it ensures portability of the engine. */
#if defined(_MSC_VER) || ((__BORLANDC__ >= 0x530) && !defined(__STRICT_ANSI__))
using u8 = unsigned __int8;
#else
using u8 = unsigned char;
#endif

//! 8 bit signed variable.
/** This is a using type alias for signed char, it ensures portability of the engine. */
#if defined(_MSC_VER) || ((__BORLANDC__ >= 0x530) && !defined(__STRICT_ANSI__))
using s8 = __int8;
#else
using s8 = signed char;
#endif

//! 8 bit character variable.
/** This is a using type alias for char, it ensures portability of the engine. */
using c8 = char;



//! 16 bit unsigned variable.
/** This is a using type alias for unsigned short, it ensures portability of the engine. */
#if defined(_MSC_VER) || ((__BORLANDC__ >= 0x530) && !defined(__STRICT_ANSI__))
using u16 = unsigned __int16;
#else
using u16 = unsigned short;
#endif

//! 16 bit signed variable.
/** This is a using type alias for signed short, it ensures portability of the engine. */
#if defined(_MSC_VER) || ((__BORLANDC__ >= 0x530) && !defined(__STRICT_ANSI__))
using s16 = __int16;
#else
using s16 = signed short;
#endif



//! 32 bit unsigned variable.
/** This is a using type alias for unsigned int, it ensures portability of the engine. */
#if defined(_MSC_VER) || ((__BORLANDC__ >= 0x530) && !defined(__STRICT_ANSI__))
using u32 = unsigned __int32;
#else
using u32 = unsigned int;
#endif

//! 32 bit signed variable.
/** This is a using type alias for signed int, it ensures portability of the engine. */
#if defined(_MSC_VER) || ((__BORLANDC__ >= 0x530) && !defined(__STRICT_ANSI__))
using s32 = __int32;
#else
using s32 = signed int;
#endif


#ifdef __NIRT_HAS_S64
//! 64 bit unsigned variable.
/** This is a using type alias for 64bit uint, it ensures portability of the engine. */
#if defined(_MSC_VER) || ((__BORLANDC__ >= 0x530) && !defined(__STRICT_ANSI__))
using u64 = unsigned __int64;
#elif defined(__GNUC__)
#if (defined(__LP64__) && __LP64__ == 1) || (defined(_LP64) && _LP64 == 1)  || (defined(__WORDSIZE) && __WORDSIZE == 64)
using u64 = unsigned long int;
#else
__extension__ using u64 = unsigned long long;
#endif
#else
using u64 = unsigned long long;
#endif

//! 64 bit signed variable.
/** This is a using type alias for 64bit int, it ensures portability of the engine. */
#if defined(_MSC_VER) || ((__BORLANDC__ >= 0x530) && !defined(__STRICT_ANSI__))
using s64 = __int64;
#elif defined(__GNUC__)
#if (defined(__LP64__) && __LP64__ == 1) || (defined(_LP64) && _LP64 == 1)  || (defined(__WORDSIZE) && __WORDSIZE == 64)
using s64 = long int;
#else
__extension__ using s64 = long long;
#endif
#else
using s64 = long long;
#endif
#endif	// __NIRT_HAS_S64



//! 32 bit floating point variable.
/** This is a using type alias for float, it ensures portability of the engine. */
using f32 = float;

//! 64 bit floating point variable.
/** This is a using type alias for double, it ensures portability of the engine. */
using f64 = double;


} // end namespace nirt


#include <wchar.h>
#ifdef _NIRT_WINDOWS_API_
//! Defines for s{w,n}printf_nirt because s{w,n}printf methods do not match the ISO C
//! standard on Windows platforms.
//! We want int snprintf_nirt(char *str, size_t size, const char *format, ...);
//! and int swprintf_nirt(wchar_t *wcs, size_t maxlen, const wchar_t *format, ...);
#if defined(_MSC_VER) && _MSC_VER > 1310 && !defined (_WIN32_WCE)
#define swprintf_nirt swprintf_s
#define snprintf_nirt sprintf_s
#elif !defined(__CYGWIN__)
#define swprintf_nirt _snwprintf
#define snprintf_nirt _snprintf
#endif

// define the wchar_t type if not already built in.
// It's usually set when VS compiler sets /Zc:wchar_t
#ifdef _MSC_VER
#ifndef _WCHAR_T_DEFINED
//! A 16 bit wide character type.
/**
	Defines the wchar_t-type.
	In VS6, its not possible to tell
	the standard compiler to treat wchar_t as a built-in type, and
	sometimes we just don't want to include the huge stdlib.h or wchar.h,
	so we'll use this.
*/
using wchar_t = unsigned short;
#define _WCHAR_T_DEFINED
#endif // wchar is not defined
#endif // microsoft compiler
#else
#define swprintf_nirt swprintf
#define snprintf_nirt snprintf
#endif // _NIRT_WINDOWS_API_

namespace nirt
{

//! Type name for character type used by the filesystem.
/** Should the wide character version of the filesystem be used it is a
16 bit character variable. Used for Unicode filesystem and Unicode strings.
Else it is a 8 bit character variable. Used for ansi filesystem and non-unicode
strings
*/
#if defined(_NIRT_WCHAR_FILESYSTEM)
	using fschar_t = wchar_t;
	#define NIRT_TEXT(X) L##X
#else
	using fschar_t = char;
	#define NIRT_TEXT(X) X
#endif

} // end namespace nirt

//! define a break macro for debugging.
#if defined(_DEBUG)
#if defined(_NIRT_WINDOWS_API_) && defined(_MSC_VER) && !defined (_WIN32_WCE)
#if defined(WIN64) || defined(_WIN64) // using portable common solution for x64 configuration
	#include <crtdbg.h>
	#define NIRT_DEBUG_BREAK_IF( _CONDITION_ ) if (_CONDITION_) {_CrtDbgBreak();}
#else
	#define NIRT_DEBUG_BREAK_IF( _CONDITION_ ) if (_CONDITION_) {_asm int 3}
#endif
#else
	#include "assert.h"
	#define NIRT_DEBUG_BREAK_IF( _CONDITION_ ) assert( !(_CONDITION_) );
#endif
#else
	#define NIRT_DEBUG_BREAK_IF( _CONDITION_ )
#endif

//! Defines a deprecated macro which generates a warning at compile time
/** The usage is simple
For using type alias:		using test1 = NIRT_DEPRECATED int;
For classes/structs:	class NIRT_DEPRECATED test2 { ... };
For methods:		class test3 { NIRT_DEPRECATED virtual void foo() {} };
For functions:		template<class T> NIRT_DEPRECATED void test4(void) {}
**/
#if defined(IGNORE_DEPRECATED_WARNING)
#define NIRT_DEPRECATED
#elif _MSC_VER >= 1310 //vs 2003 or higher
#define NIRT_DEPRECATED __declspec(deprecated)
#elif (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1)) // all versions above 3.0 should support this feature
#define NIRT_DEPRECATED  __attribute__ ((deprecated))
#else
#define NIRT_DEPRECATED
#endif

// memory debugging
#if defined(_DEBUG) && defined(NIRTCPP_EXPORTS) && defined(_MSC_VER) && \
	(_MSC_VER > 1299) && !defined(NIRT_DONT_DO_MEMORY_DEBUGGING_HERE) && !defined(_WIN32_WCE)

	#define CRTDBG_MAP_ALLOC
	#define _CRTDBG_MAP_ALLOC
	#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
	#include <stdlib.h>
	#include <crtdbg.h>
	#define new DEBUG_CLIENTBLOCK
#endif

//! ignore VC8 warning deprecated
/** The Microsoft compiler */
#if defined(_NIRT_WINDOWS_API_) && defined(_MSC_VER) && (_MSC_VER >= 1400)
	//#pragma warning( disable: 4996)
	//#define _CRT_SECURE_NO_DEPRECATE 1
	//#define _CRT_NONSTDC_NO_DEPRECATE 1
#endif


//! creates four CC codes used in Nirtcpp for simple ids
/** some compilers can create those by directly writing the
code like 'code', but some generate warnings so we use this macro here */
#define MAKE_NIRT_ID(c0, c1, c2, c3) \
		((nirt::u32)(nirt::u8)(c0) | ((nirt::u32)(nirt::u8)(c1) << 8) | \
		((nirt::u32)(nirt::u8)(c2) << 16) | ((nirt::u32)(nirt::u8)(c3) << 24 ))

#endif // NIRT_TYPES_H_INCLUDED
