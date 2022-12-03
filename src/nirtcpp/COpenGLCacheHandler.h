// Copyright (C) 2015 Patryk Nadrowski
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in Nirtcpp.h

#ifndef NIRT_C_OPENGL_CACHE_HANDLER_H_INCLUDED
#define NIRT_C_OPENGL_CACHE_HANDLER_H_INCLUDED

#include "IrrCompileConfig.h"

#ifdef _NIRT_COMPILE_WITH_OPENGL_

#include "COpenGLCommon.h"

#include "COpenGLCoreFeature.h"
#include "COpenGLCoreTexture.h"
#include "COpenGLCoreCacheHandler.h"

namespace irr
{
namespace video
{

	class COpenGLCacheHandler : public COpenGLCoreCacheHandler<COpenGLDriver, COpenGLTexture>
	{
	public:
		COpenGLCacheHandler(COpenGLDriver* driver);
		virtual ~COpenGLCacheHandler();

		// Alpha calls.

		void setAlphaFunc(GLenum mode, GLclampf ref);

		void setAlphaTest(bool enable);

		// Client state calls.

		void setClientState(bool vertex, bool normal, bool color, bool texCoord0);

		// Matrix calls.

		void setMatrixMode(GLenum mode);

		// Texture calls.

		void setClientActiveTexture(GLenum texture);

	protected:
		GLenum AlphaMode;
		GLclampf AlphaRef;
		bool AlphaTest;

		GLenum MatrixMode;

		GLenum ClientActiveTexture;

		bool ClientStateVertex;
		bool ClientStateNormal;
		bool ClientStateColor;
		bool ClientStateTexCoord0;
	};

} // end namespace video
} // end namespace irr

#endif // _NIRT_COMPILE_WITH_OPENGL_
#endif
