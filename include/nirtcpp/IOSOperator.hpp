// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_I_OS_OPERATOR_H_INCLUDED
#define NIRT_I_OS_OPERATOR_H_INCLUDED

#include <nirtcpp/IReferenceCounted.hpp>
#include <nirtcpp/irrString.hpp>

namespace nirt
{

//! The Operating system operator provides operation system specific methods and information.
class IOSOperator : public virtual IReferenceCounted
{
public:
	//! Get the current operation system version as string.
	virtual const core::stringc& getOperatingSystemVersion() const = 0;

	//! Get the current operation system version as string.
	/** \deprecated Use getOperatingSystemVersion instead. This method will be removed in Nirtcpp 1.9. */
	NIRT_DEPRECATED const wchar_t* getOperationSystemVersion() const
	{
		return core::stringw(getOperatingSystemVersion()).data();
	}

	//! Copies text to the clipboard
	virtual void copyToClipboard(const c8* text) const = 0;

	//! Get text from the clipboard
	/** \return Returns 0 if no string is in there. */
	virtual const c8* getTextFromClipboard() const = 0;

	//! Get the processor speed in megahertz
	/** \param MHz The integer variable to store the speed in.
	\return True if successful, false if not */
	virtual bool getProcessorSpeedMHz(u32* MHz) const = 0;

	//! Get the total and available system RAM
	/** \param totalBytes: will contain the total system memory in Kilobytes (1024 B)
	\param availableBytes: will contain the available memory in Kilobytes (1024 B)
	\return True if successful, false if not */
	virtual bool getSystemMemory(u32* totalBytes, u32* availableBytes) const = 0;

};

} // end namespace

#endif
