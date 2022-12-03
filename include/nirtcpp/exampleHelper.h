// Copyright (C) 2015 Patryk Nadrowski
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_EXAMPLE_HELPER_H_INCLUDED
#define NIRT_EXAMPLE_HELPER_H_INCLUDED

#include "IrrCompileConfig.h"
#include "path.h"

namespace nirt
{

static io::path getExampleMediaPath()
{
#if defined (_NIRT_IPHONE_PLATFORM_) || defined (_NIRT_ANDROID_PLATFORM_) || defined (_NIRT_OSX_PLATFORM_)
	return io::path("media/");
#else
	return io::path("../../media/");
#endif
}

} // end namespace nirt

#endif
