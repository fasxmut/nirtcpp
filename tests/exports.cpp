// Copyright (C) 2008-2012 Colin MacDonald
// No rights reserved: this software is in the public domain.

#include "testUtils.h"

//! Tests that symbols exported from Nirtcpp can be used by the user app.
bool exports(void)
{
	logTestString("Checking whether IdentityMatrix is exported.\n");
	nirt::core::matrix4 identity = nirt::core::IdentityMatrix;
	(void)identity; // Satisfy the compiler that it's used.

	nirt::video::SMaterial id = nirt::video::IdentityMaterial;
	(void)id; // Satisfy the compiler that it's used.
	// If it built, we're done.
	return true;
}
