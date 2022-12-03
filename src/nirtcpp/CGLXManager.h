// Copyright (C) 2013 Christian Stehno
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in Nirtcpp.h

#ifndef NIRT_C_GLX_MANAGER_H_INCLUDED
#define NIRT_C_GLX_MANAGER_H_INCLUDED

#include "IrrCompileConfig.h"

#ifdef _NIRT_COMPILE_WITH_GLX_MANAGER_

#include "SIrrCreationParameters.h"
#include "SExposedVideoData.h"
#include "IContextManager.h"
#include "SColor.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>

// we can't include glx.h here, because gl.h has incompatible types with ogl es headers and it
// cause redefinition errors, thats why we use ugly trick with void* types and casts.

namespace nirt
{
namespace video
{
    // GLX manager.
    class CGLXManager : public IContextManager
    {
    public:
        //! Constructor.
        CGLXManager(const SNirtcppCreationParameters& params, const SExposedVideoData& videodata, int screennr);

        //! Destructor
        ~CGLXManager();

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

        // Destroy context.
        virtual void destroyContext() override;

        //! Get current context
        virtual const SExposedVideoData& getContext() const override;

        //! Change render context, disable old and activate new defined by videoData
        virtual bool activateContext(const SExposedVideoData& videoData, bool restorePrimaryOnZero) override;

        // Swap buffers.
        virtual bool swapBuffers() override;

        XVisualInfo* getVisual() const {return VisualInfo;} // return XVisualInfo

    private:
        SNirtcppCreationParameters Params;
        SExposedVideoData PrimaryContext;
        SExposedVideoData CurrentContext;
        XVisualInfo* VisualInfo;
        void* glxFBConfig; // GLXFBConfig
        XID GlxWin; // GLXWindow
	};
}
}

#endif

#endif
