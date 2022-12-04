// Copyright (C) 2013 Michael Zeilfelder
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#include <nirtcpp/leakHunter.hpp>

#ifdef _NIRT_COMPILE_WITH_LEAK_HUNTER_

namespace nirt
{
	 nirt::core::array<const IReferenceCounted*> LeakHunter::ReferenceCountedObjects;
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_LEAK_HUNTER_

