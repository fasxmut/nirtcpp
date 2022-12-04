// Copyright (C) 2008-2012 Colin MacDonald and Christian Stehno
// No rights reserved: this software is in the public domain.

#include "testUtils.hpp"

bool irrCoreEquals(void)
{
	// float tests
	if(!nirt::core::equals(99.f, 99.f))
	{
		logTestString("nirt::core::equals(f32, f32 (, default)) failed.\n");
		return false;
	}

	if(!nirt::core::equals(99.f, 98.f, 1.f))
	{
		logTestString("nirt::core::equals(f32, f32, f32) failed.\n");
		return false;
	}

	// double tests
	if(!nirt::core::equals(99.0, 99.0))
	{
		logTestString("nirt::core::equals(f64, f64 (,default)) failed.\n");
		return false;
	}

	if(!nirt::core::equals(99.0, 98.0, 1.0))
	{
		logTestString("nirt::core::equals(f64, f64, f64) failed.\n");
		return false;
	}

	// int tests
	if(!nirt::core::equals(99, 99))
	{
		logTestString("nirt::core::equals(s32, s32 (,default)) failed.\n");
		return false;
	}

	if(!nirt::core::equals(99, 98, 1))
	{
		logTestString("nirt::core::equals(s32, s32, s32) failed.\n");
		return false;
	}

	if(nirt::core::equals(99, 98, 0))
	{
		logTestString("nirt::core::equals(s32, s32, 0) failed.\n");
		return false;
	}

	if(!nirt::core::equals(-99, -99))
	{
		logTestString("nirt::core::equals(s32, s32 (,default)) failed.\n");
		return false;
	}

	if(!nirt::core::equals(-99, -98, 1))
	{
		logTestString("nirt::core::equals(s32, s32, s32) failed.\n");
		return false;
	}

	if(nirt::core::equals(-99, -98, 0))
	{
		logTestString("nirt::core::equals(s32, s32, 0) failed.\n");
		return false;
	}

	// iszero is a specialized equals method
	// float tests
	if(!nirt::core::iszero(.0f))
	{
		logTestString("nirt::core::iszero(f32 (,default)) failed.\n");
		return false;
	}

	if(nirt::core::iszero(-1.0f))
	{
		logTestString("nirt::core::iszero(f32 (,default)) failed.\n");
		return false;
	}

	if(!nirt::core::iszero(1.0f, 1.0f))
	{
		logTestString("nirt::core::iszero(f32, f32) failed.\n");
		return false;
	}

	// double tests
	if(!nirt::core::iszero(0.0))
	{
		logTestString("nirt::core::iszero(f64 (,default)) failed.\n");
		return false;
	}

	if(nirt::core::iszero(-1.0))
	{
		logTestString("nirt::core::iszero(f64 (,default)) failed.\n");
		return false;
	}

	if(!nirt::core::iszero(-2.0, 2.0))
	{
		logTestString("nirt::core::iszero(f64, f64) failed.\n");
		return false;
	}

	// int tests
	if(!nirt::core::iszero(0))
	{
		logTestString("nirt::core::iszero(s32 (,default)) failed.\n");
		return false;
	}

	if(nirt::core::iszero(-1))
	{
		logTestString("nirt::core::iszero(s32 (,default)) failed.\n");
		return false;
	}

	if(!nirt::core::iszero(1, 1))
	{
		logTestString("nirt::core::iszero(s32, s32) failed.\n");
		return false;
	}


	return true;
}

