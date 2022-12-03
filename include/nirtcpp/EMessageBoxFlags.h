// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_E_MESSAGE_BOX_FLAGS_H_INCLUDED
#define NIRT_E_MESSAGE_BOX_FLAGS_H_INCLUDED

namespace nirt
{
namespace gui
{

//! enumeration for message box layout flags
enum EMESSAGE_BOX_FLAG
{
	//! Flag for the OK button
	EMBF_OK = 0x1,

	//! Flag for the cancel button
	EMBF_CANCEL = 0x2,

	//! Flag for the yes button
	EMBF_YES = 0x4,

	//! Flag for the no button
	EMBF_NO = 0x8,

	//! This value is not used. It only forces this enumeration to compile in 32 bit.
	EMBF_FORCE_32BIT = 0x7fffffff
};

} // namespace gui
} // namespace nirt

#endif
