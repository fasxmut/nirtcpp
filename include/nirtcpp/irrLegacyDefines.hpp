// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_LEGACY_DEFINES_H_INCLUDED
#define NIRT_LEGACY_DEFINES_H_INCLUDED

//! Include this file _after_ nirtcpp/nirtcpp.hpp
//! It contains old defines which got replaced in Nirtcpp.
//! So including this header is a quick fix to allow users compiling old code 
//! without having to rewrite it all. Thought in the long run you should 
//! switch to the new defines as well.

// Defines replaced in Nirtcpp 1.9 as they were reserved identifiers in c++
#define _NIRT_DEPRECATED_ NIRT_DEPRECATED
#define _NIRT_DEBUG_BREAK_IF NIRT_DEBUG_BREAK_IF
#define _NIRT_TEXT NIRT_TEXT

// Defines which are used in Nirtcpp 1.9 and changed their name as they were reserved identifiers in c++
// Those can't be set here as it's defines _users_ can set.
// If you have any of those in your code, you will have to change them there.
// _NIRT_DONT_DO_MEMORY_DEBUGGING_HERE -> NIRT_DONT_DO_MEMORY_DEBUGGING_HERE

#endif
