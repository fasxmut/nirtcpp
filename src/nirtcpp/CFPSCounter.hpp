// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_FPSCOUNTER_H_INCLUDED
#define NIRT_C_FPSCOUNTER_H_INCLUDED

#include <nirtcpp/irrTypes.hpp>

namespace nirt
{
namespace video
{


class CFPSCounter
{
public:
	CFPSCounter();

	//! returns current fps
	s32 getFPS() const;

	//! returns primitive count
	u32 getPrimitive() const;

	//! returns average primitive count of last period
	u32 getPrimitiveAverage() const;

	//! returns accumulated primitive count since start
	u32 getPrimitiveTotal() const;

	//! to be called every frame
	void registerFrame(u32 now, u32 primitive);

private:

	s32 FPS;
	u32 Primitive;
	u32 StartTime;

	u32 FramesCounted;
	u32 PrimitivesCounted;
	u32 PrimitiveAverage;
	u32 PrimitiveTotal;
};


} // end namespace video
} // end namespace nirt

#endif
