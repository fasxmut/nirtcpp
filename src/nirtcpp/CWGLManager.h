// Copyright (C) 2013 Christian Stehno
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in Nirtcpp.h

#ifndef NIRT_C_WGL_MANAGER_H_INCLUDED
#define NIRT_C_WGL_MANAGER_H_INCLUDED

#include "IrrCompileConfig.h"

#ifdef _NIRT_COMPILE_WITH_WGL_MANAGER_

#include "SIrrCreationParameters.h"
#include "SExposedVideoData.h"
#include "IContextManager.h"
#include "SColor.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace nirt
{
namespace video
{
    // WGL manager.
    class CWGLManager : public IContextManager
    {
    public:
        //! Constructor.
        CWGLManager();

		//! Destructor
		~CWGLManager();

        // Initialize
        virtual bool initialize(const SNirtcppCreationParameters& params, const SExposedVideoData& data) override;

        // Terminate
        virtual void terminate() override;

        // Create surface.
        virtual bool generateSurface() override;

        // Destroy surface.
        virtual void destroySurface() override;

        // Create context.
        virtual bool generateContext() override;

        // Destroy EGL context.
        virtual void destroyContext() override;

		//! Get current context
		virtual const SExposedVideoData& getContext() const override;

		//! Change render context, disable old and activate new defined by videoData
		virtual bool activateContext(const SExposedVideoData& videoData, bool restorePrimaryOnZero) override;

        // Swap buffers.
        virtual bool swapBuffers() override;

    private:
        SNirtcppCreationParameters Params;
		SExposedVideoData PrimaryContext;
        SExposedVideoData CurrentContext;
		s32 PixelFormat;
		PIXELFORMATDESCRIPTOR pfd;
		ECOLOR_FORMAT ColorFormat;
	};
}
}

#endif

#endif
