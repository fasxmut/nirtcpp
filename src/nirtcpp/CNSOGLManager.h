// Copyright (C) 2014 Patryk Nadrowski
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in Nirtcpp.h

#ifndef __C_NSOGL_MANAGER_H_INCLUDED__
#define __C_NSOGL_MANAGER_H_INCLUDED__

#include "IrrCompileConfig.h"

#ifdef _NIRT_COMPILE_WITH_NSOGL_MANAGER_

#include "SIrrCreationParameters.h"
#include "SExposedVideoData.h"
#include "IContextManager.h"
#include "SColor.h"

#import <AppKit/NSOpenGL.h>

namespace nirt
{
namespace video
{
    // NSOpenGL manager.
    class CNSOGLManager : public IContextManager
    {
    public:
        //! Constructor.
        CNSOGLManager();

		//! Destructor
		~CNSOGLManager();

        // Initialize
        bool initialize(const SNirtcppCreationParameters& params, const SExposedVideoData& data) override;

        // Terminate
        void terminate() override;

        // Create surface.
        bool generateSurface() override;

        // Destroy surface.
        void destroySurface() override;

        // Create context.
        bool generateContext() override;

        // Destroy EGL context.
        void destroyContext() override;

		//! Get current context
		const SExposedVideoData& getContext() const override;

		//! Change render context, disable old and activate new defined by videoData
		bool activateContext(const SExposedVideoData& videoData, bool restorePrimaryOnZero) override;

        // Swap buffers.
        bool swapBuffers() override;

    private:
        SNirtcppCreationParameters Params;
		SExposedVideoData PrimaryContext;
        SExposedVideoData CurrentContext;

        NSOpenGLPixelFormat* PixelFormat;
	};
}
}

#endif

#endif
