// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h
// Written by Michael Zeilfelder

#ifndef NIRT_C_PROFILER_H_INCLUDED
#define NIRT_C_PROFILER_H_INCLUDED

#include "IrrCompileConfig.h"
#include "IProfiler.h"

namespace irr
{
class CProfiler : public IProfiler
{
public:

	CProfiler();
	virtual ~CProfiler();

	//! Write all profile-data into a string
    virtual void printAll(core::stringw &result, bool includeOverview,bool suppressUncalled) const  override;

	//! Write the profile data of one group into a string
    virtual void printGroup(core::stringw &result, u32 groupIndex, bool suppressUncalled) const  override;

protected:
	core::stringw makeTitleString() const;
	core::stringw getAsString(const SProfileData& data) const;
};
} // namespace irr

#endif // NIRT_C_PROFILER_H_INCLUDED
