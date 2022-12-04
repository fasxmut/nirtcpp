// Copyright (C) 2014 Patryk Nadrowski
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in Nirtcpp.h

#ifndef __C_NSOGL_MANAGER_H_INCLUDED__
#define __C_NSOGL_MANAGER_H_INCLUDED__

#include <nirtcpp/IrrCompileConfig.hpp>

#ifdef _NIRT_COMPILE_WITH_NSOGL_MANAGER_

#include <nirtcpp/SIrrCreationParameters.hpp>
#include <nirtcpp/SExposedVideoData.hpp>
#include <nirtcpp/IContextManager.hpp>
#include <nirtcpp/SColor.hpp>

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
