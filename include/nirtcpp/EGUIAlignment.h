// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_E_GUI_ALIGNMENT_H_INCLUDED
#define NIRT_E_GUI_ALIGNMENT_H_INCLUDED

#include "irrTypes.h"

namespace irr
{
namespace gui
{
enum EGUI_ALIGNMENT
{
	//! Aligned to parent's top or left side (default)
	EGUIA_UPPERLEFT=0,
	//! Aligned to parent's bottom or right side
	EGUIA_LOWERRIGHT,
	//! Aligned to the center of parent
	EGUIA_CENTER,
	//! Stretched to fit parent
	EGUIA_SCALE
};

//! Names for alignments
const c8* const GUIAlignmentNames[] =
{
	"upperLeft",
	"lowerRight",
	"center",
	"scale",
	0
};

} // namespace gui
} // namespace irr

#endif // NIRT_E_GUI_ALIGNMENT_H_INCLUDED
