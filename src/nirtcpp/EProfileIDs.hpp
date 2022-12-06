// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef E_PROFILE_IDS_H_INCLUDED__
#define E_PROFILE_IDS_H_INCLUDED__

#include <nirtcpp/IrrCompileConfig.hpp>
#include "limits.h"

namespace nirt
{
#ifdef _NIRT_COMPILE_WITH_PROFILING_
    enum EPROFILE_ID
    {
		// We use negative ID's to avoid clashing with user application id's.
		EPID_FIRST = -INT_MAX,	// not used

		//! scenemanager.
		EPID_SM_DRAW_ALL,
		EPID_SM_ANIMATE,
		EPID_SM_RENDER_CAMERAS,
		EPID_SM_RENDER_LIGHTS,
		EPID_SM_RENDER_SKYBOXES,
		EPID_SM_RENDER_DEFAULT,
		EPID_SM_RENDER_SHADOWS,
		EPID_SM_RENDER_TRANSPARENT,
		EPID_SM_RENDER_EFFECT,
		EPID_SM_RENDER_GUI_NODES,
		EPID_SM_REGISTER,

		//! octrees
		EPID_OC_RENDER,
		EPID_OC_CALCPOLYS
    };
#endif
} // end namespace nirt

#endif // E_PROFILE_IDS_H_INCLUDED__
