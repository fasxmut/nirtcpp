// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#include "COpenGLExtensionHandler.h"

#ifdef _NIRT_COMPILE_WITH_OPENGL_

#include "irrString.h"
#include "SMaterial.h"
#include "fast_atof.h"

namespace nirt
{
namespace video
{

bool COpenGLExtensionHandler::needsDSAFramebufferHack = true;

COpenGLExtensionHandler::COpenGLExtensionHandler() :
		StencilBuffer(false), TextureCompressionExtension(false), MaxLights(1),
		MaxAnisotropy(1), MaxUserClipPlanes(0), MaxAuxBuffers(0), MaxIndices(65535),
		MaxTextureSize(1), MaxGeometryVerticesOut(0),
		MaxTextureLODBias(0.f), Version(0), ShaderLanguageVersion(0),
		OcclusionQuerySupport(false), IsAtiRadeonX(false)
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	,pGlActiveTexture(0)
	,pGlActiveTextureARB(0), pGlClientActiveTextureARB(0),
	pGlGenProgramsARB(0), pGlGenProgramsNV(0),
	pGlBindProgramARB(0), pGlBindProgramNV(0),
	pGlDeleteProgramsARB(0), pGlDeleteProgramsNV(0),
	pGlProgramStringARB(0), pGlLoadProgramNV(0),
	pGlProgramLocalParameter4fvARB(0),
	pGlCreateShaderObjectARB(0), pGlShaderSourceARB(0),
	pGlCompileShaderARB(0), pGlCreateProgramObjectARB(0), pGlAttachObjectARB(0),
	pGlLinkProgramARB(0), pGlUseProgramObjectARB(0), pGlDeleteObjectARB(0),
	pGlCreateProgram(0), pGlUseProgram(0),
	pGlDeleteProgram(0), pGlDeleteShader(0),
	pGlGetAttachedObjectsARB(0), pGlGetAttachedShaders(0),
	pGlCreateShader(0), pGlShaderSource(0), pGlCompileShader(0),
	pGlAttachShader(0), pGlLinkProgram(0),
	pGlGetInfoLogARB(0), pGlGetShaderInfoLog(0), pGlGetProgramInfoLog(0),
	pGlGetObjectParameterivARB(0), pGlGetShaderiv(0), pGlGetProgramiv(0),
	pGlGetUniformLocationARB(0), pGlGetUniformLocation(0),
	pGlUniform1fvARB(0), pGlUniform2fvARB(0), pGlUniform3fvARB(0), pGlUniform4fvARB(0),
	pGlUniform1ivARB(0), pGlUniform2ivARB(0), pGlUniform3ivARB(0), pGlUniform4ivARB(0),
	pGlUniform1uiv(0), pGlUniform2uiv(0), pGlUniform3uiv(0), pGlUniform4uiv(0),
	pGlUniformMatrix2fvARB(0), pGlUniformMatrix2x3fv(0), pGlUniformMatrix2x4fv(0),
	pGlUniformMatrix3x2fv(0), pGlUniformMatrix3fvARB(0), pGlUniformMatrix3x4fv(0),
	pGlUniformMatrix4x2fv(0), pGlUniformMatrix4x3fv(0), pGlUniformMatrix4fvARB(0),
	pGlGetActiveUniformARB(0), pGlGetActiveUniform(0),
	pGlPointParameterfARB(0), pGlPointParameterfvARB(0),
	pGlStencilFuncSeparate(0), pGlStencilOpSeparate(0),
	pGlStencilFuncSeparateATI(0), pGlStencilOpSeparateATI(0),
	pGlCompressedTexImage2D(0), pGlCompressedTexSubImage2D(0),
	// ARB framebuffer object
	pGlBindFramebuffer(0), pGlDeleteFramebuffers(0), pGlGenFramebuffers(0),
	pGlCheckFramebufferStatus(0), pGlFramebufferTexture2D(0),
	pGlBindRenderbuffer(0), pGlDeleteRenderbuffers(0), pGlGenRenderbuffers(0),
	pGlRenderbufferStorage(0), pGlFramebufferRenderbuffer(0), pGlGenerateMipmap(0),
	// EXT framebuffer object
	pGlBindFramebufferEXT(0), pGlDeleteFramebuffersEXT(0), pGlGenFramebuffersEXT(0),
	pGlCheckFramebufferStatusEXT(0), pGlFramebufferTexture2DEXT(0),
	pGlBindRenderbufferEXT(0), pGlDeleteRenderbuffersEXT(0), pGlGenRenderbuffersEXT(0),
	pGlRenderbufferStorageEXT(0), pGlFramebufferRenderbufferEXT(0), pGlGenerateMipmapEXT(0),
	pGlActiveStencilFaceEXT(0),
	// MRTs
	pGlDrawBuffersARB(0), pGlDrawBuffersATI(0),
	pGlGenBuffersARB(0), pGlBindBufferARB(0), pGlBufferDataARB(0), pGlDeleteBuffersARB(0),
	pGlBufferSubDataARB(0), pGlGetBufferSubDataARB(0), pGlMapBufferARB(0), pGlUnmapBufferARB(0),
	pGlIsBufferARB(0), pGlGetBufferParameterivARB(0), pGlGetBufferPointervARB(0),
	pGlProvokingVertexARB(0), pGlProvokingVertexEXT(0),
	pGlProgramParameteriARB(0), pGlProgramParameteriEXT(0),
	pGlGenQueriesARB(0), pGlDeleteQueriesARB(0), pGlIsQueryARB(0),
	pGlBeginQueryARB(0), pGlEndQueryARB(0), pGlGetQueryivARB(0),
	pGlGetQueryObjectivARB(0), pGlGetQueryObjectuivARB(0),
	pGlGenOcclusionQueriesNV(0), pGlDeleteOcclusionQueriesNV(0),
	pGlIsOcclusionQueryNV(0), pGlBeginOcclusionQueryNV(0),
	pGlEndOcclusionQueryNV(0), pGlGetOcclusionQueryivNV(0),
	pGlGetOcclusionQueryuivNV(0),
	// Blend
	pGlBlendFuncSeparateEXT(0), pGlBlendFuncSeparate(0),
	pGlBlendEquationEXT(0), pGlBlendEquation(0), pGlBlendEquationSeparateEXT(0), pGlBlendEquationSeparate(0),
	// Indexed
	pGlEnableIndexedEXT(0), pGlDisableIndexedEXT(0),
	pGlColorMaskIndexedEXT(0),
	pGlBlendFuncIndexedAMD(0), pGlBlendFunciARB(0), pGlBlendFuncSeparateIndexedAMD(0), pGlBlendFuncSeparateiARB(0),
	pGlBlendEquationIndexedAMD(0), pGlBlendEquationiARB(0), pGlBlendEquationSeparateIndexedAMD(0), pGlBlendEquationSeparateiARB(0),
	// DSA
    pGlTextureStorage2D(0), pGlTextureStorage3D(0), pGlTextureSubImage2D(0), pGlGetTextureImage(0), pGlNamedFramebufferTexture(0),
    pGlTextureParameteri(0), pGlTextureParameterf(0), pGlTextureParameteriv(0), pGlTextureParameterfv(0),
	pGlCreateTextures(0), pGlCreateFramebuffers(0), pGlBindTextures(0), pGlGenerateTextureMipmap(0),
    // DSA with EXT or functions to simulate it
	pGlTextureStorage2DEXT(0), pGlTexStorage2D(0), pGlTextureStorage3DEXT(0), pGlTexStorage3D(0), pGlTextureSubImage2DEXT(0), pGlGetTextureImageEXT(0),
	pGlNamedFramebufferTextureEXT(0), pGlFramebufferTexture(0), pGlGenerateTextureMipmapEXT(0)
#if defined(GLX_SGI_swap_control)
	,pGlxSwapIntervalSGI(0)
#endif
#if defined(GLX_EXT_swap_control)
	,pGlxSwapIntervalEXT(0)
#endif
#if defined(WGL_EXT_swap_control)
	,pWglSwapIntervalEXT(0)
#endif
#if defined(GLX_MESA_swap_control)
	,pGlxSwapIntervalMESA(0)
#endif
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
{
	for (u32 i=0; i<NIRT_OpenGL_Feature_Count; ++i)
		FeatureAvailable[i]=false;
	DimAliasedLine[0]=1.f;
	DimAliasedLine[1]=1.f;
	DimAliasedPoint[0]=1.f;
	DimAliasedPoint[1]=1.f;
	DimSmoothedLine[0]=1.f;
	DimSmoothedLine[1]=1.f;
	DimSmoothedPoint[0]=1.f;
	DimSmoothedPoint[1]=1.f;
}


void COpenGLExtensionHandler::dump(ELOG_LEVEL logLevel) const
{
	for (u32 i=0; i<NIRT_OpenGL_Feature_Count; ++i)
		os::Printer::log(OpenGLFeatureStrings[i], FeatureAvailable[i]?" true":" false", logLevel);
}


void COpenGLExtensionHandler::dumpFramebufferFormats() const
{
#ifdef _NIRT_WINDOWS_API_
	HDC hdc=wglGetCurrentDC();
	core::stringc wglExtensions;
#ifdef WGL_ARB_extensions_string
	PFNWGLGETEXTENSIONSSTRINGARBPROC irrGetExtensionsString = (PFNWGLGETEXTENSIONSSTRINGARBPROC)wglGetProcAddress("wglGetExtensionsStringARB");
	if (irrGetExtensionsString)
		wglExtensions = irrGetExtensionsString(hdc);
#elif defined(WGL_EXT_extensions_string)
	PFNWGLGETEXTENSIONSSTRINGEXTPROC irrGetExtensionsString = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)wglGetProcAddress("wglGetExtensionsStringEXT");
	if (irrGetExtensionsString)
		wglExtensions = irrGetExtensionsString(hdc);
#endif
	const bool pixel_format_supported = (wglExtensions.find("WGL_ARB_pixel_format") != -1);
	const bool multi_sample_supported = ((wglExtensions.find("WGL_ARB_multisample") != -1) ||
		(wglExtensions.find("WGL_EXT_multisample") != -1) || (wglExtensions.find("WGL_3DFX_multisample") != -1) );
#ifdef _DEBUG
	os::Printer::log("WGL_extensions", wglExtensions);
#endif

#ifdef WGL_ARB_pixel_format
	PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormat_ARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
	if (pixel_format_supported && wglChoosePixelFormat_ARB)
	{
		// This value determines the number of samples used for antialiasing
		// My experience is that 8 does not show a big
		// improvement over 4, but 4 shows a big improvement
		// over 2.

		PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribiv_ARB = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC)wglGetProcAddress("wglGetPixelFormatAttribivARB");
		if (wglGetPixelFormatAttribiv_ARB)
		{
			int vals[128];
			int atts[] = {
				WGL_NUMBER_PIXEL_FORMATS_ARB,
				WGL_DRAW_TO_BITMAP_ARB,
				WGL_ACCELERATION_ARB,
				WGL_NEED_PALETTE_ARB,
				WGL_NEED_SYSTEM_PALETTE_ARB,
				WGL_SWAP_LAYER_BUFFERS_ARB,
				WGL_SWAP_METHOD_ARB,
				WGL_NUMBER_OVERLAYS_ARB,
				WGL_NUMBER_UNDERLAYS_ARB,
				WGL_TRANSPARENT_ARB,
				WGL_TRANSPARENT_RED_VALUE_ARB,
				WGL_TRANSPARENT_GREEN_VALUE_ARB,
				WGL_TRANSPARENT_BLUE_VALUE_ARB,
				WGL_TRANSPARENT_ALPHA_VALUE_ARB,
				WGL_TRANSPARENT_INDEX_VALUE_ARB,
				WGL_SHARE_DEPTH_ARB,
				WGL_SHARE_STENCIL_ARB,
				WGL_SHARE_ACCUM_ARB,
				WGL_SUPPORT_GDI_ARB,
				WGL_SUPPORT_OPENGL_ARB,
				WGL_DOUBLE_BUFFER_ARB,
				WGL_STEREO_ARB,
				WGL_PIXEL_TYPE_ARB,
				WGL_COLOR_BITS_ARB,
				WGL_RED_BITS_ARB,
				WGL_RED_SHIFT_ARB,
				WGL_GREEN_BITS_ARB,
				WGL_GREEN_SHIFT_ARB,
				WGL_BLUE_BITS_ARB,
				WGL_BLUE_SHIFT_ARB,
				WGL_ALPHA_BITS_ARB,
				WGL_ALPHA_SHIFT_ARB,
				WGL_ACCUM_BITS_ARB,
				WGL_ACCUM_RED_BITS_ARB,
				WGL_ACCUM_GREEN_BITS_ARB,
				WGL_ACCUM_BLUE_BITS_ARB,
				WGL_ACCUM_ALPHA_BITS_ARB,
				WGL_DEPTH_BITS_ARB,
				WGL_STENCIL_BITS_ARB,
				WGL_AUX_BUFFERS_ARB
#ifdef WGL_ARB_render_texture
				,WGL_BIND_TO_TEXTURE_RGB_ARB //40
				,WGL_BIND_TO_TEXTURE_RGBA_ARB
#endif
#ifdef WGL_ARB_pbuffer
				,WGL_DRAW_TO_PBUFFER_ARB //42
				,WGL_MAX_PBUFFER_PIXELS_ARB
				,WGL_MAX_PBUFFER_WIDTH_ARB
				,WGL_MAX_PBUFFER_HEIGHT_ARB
#endif
#ifdef WGL_ARB_framebuffer_sRGB
				,WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB //46
#endif
#ifdef WGL_ARB_multisample
				,WGL_SAMPLES_ARB //47
				,WGL_SAMPLE_BUFFERS_ARB
#endif
#ifdef WGL_EXT_depth_float
				,WGL_DEPTH_FLOAT_EXT //49
#endif
				,0,0,0,0
			};
			size_t nums = sizeof(atts)/sizeof(int);
			const bool depth_float_supported= (wglExtensions.find("WGL_EXT_depth_float") != -1);
			if (!depth_float_supported)
			{
				memmove(&atts[49], &atts[50], (nums-50)*sizeof(int));
				nums -= 1;
			}
			if (!multi_sample_supported)
			{
				memmove(&atts[47], &atts[49], (nums-49)*sizeof(int));
				nums -= 2;
			}
			const bool framebuffer_sRGB_supported= (wglExtensions.find("WGL_ARB_framebuffer_sRGB") != -1);
			if (!framebuffer_sRGB_supported)
			{
				memmove(&atts[46], &atts[47], (nums-47)*sizeof(int));
				nums -= 1;
			}
			const bool pbuffer_supported = (wglExtensions.find("WGL_ARB_pbuffer") != -1);
			if (!pbuffer_supported)
			{
				memmove(&atts[42], &atts[46], (nums-46)*sizeof(int));
				nums -= 4;
			}
			const bool render_texture_supported = (wglExtensions.find("WGL_ARB_render_texture") != -1);
			if (!render_texture_supported)
			{
				memmove(&atts[40], &atts[42], (nums-42)*sizeof(int));
				nums -= 2;
			}
			wglGetPixelFormatAttribiv_ARB(hdc,0,0,1,atts,vals);
			const int count = vals[0];
			atts[0]=WGL_DRAW_TO_WINDOW_ARB;
			for (int i=1; i<count; ++i)
			{
				memset(vals,0,sizeof(vals));
#define tmplog(x,y) os::Printer::log(x, core::stringc(y).data())
				const BOOL res = wglGetPixelFormatAttribiv_ARB(hdc,i,0,(UINT)nums,atts,vals);
				if (FALSE==res)
					continue;
				tmplog("Pixel format ",i);
				u32 j=0;
				tmplog("Draw to window " , vals[j]);
				tmplog("Draw to bitmap " , vals[++j]);
				++j;
				tmplog("Acceleration " , (vals[j]==WGL_NO_ACCELERATION_ARB?"No":
					vals[j]==WGL_GENERIC_ACCELERATION_ARB?"Generic":vals[j]==WGL_FULL_ACCELERATION_ARB?"Full":"ERROR"));
				tmplog("Need palette " , vals[++j]);
				tmplog("Need system palette " , vals[++j]);
				tmplog("Swap layer buffers " , vals[++j]);
				++j;
				tmplog("Swap method " , (vals[j]==WGL_SWAP_EXCHANGE_ARB?"Exchange":
					vals[j]==WGL_SWAP_COPY_ARB?"Copy":vals[j]==WGL_SWAP_UNDEFINED_ARB?"Undefined":"ERROR"));
				tmplog("Number of overlays " , vals[++j]);
				tmplog("Number of underlays " , vals[++j]);
				tmplog("Transparent " , vals[++j]);
				tmplog("Transparent red value " , vals[++j]);
				tmplog("Transparent green value " , vals[++j]);
				tmplog("Transparent blue value " , vals[++j]);
				tmplog("Transparent alpha value " , vals[++j]);
				tmplog("Transparent index value " , vals[++j]);
				tmplog("Share depth " , vals[++j]);
				tmplog("Share stencil " , vals[++j]);
				tmplog("Share accum " , vals[++j]);
				tmplog("Support GDI " , vals[++j]);
				tmplog("Support OpenGL " , vals[++j]);
				tmplog("Double Buffer " , vals[++j]);
				tmplog("Stereo Buffer " , vals[++j]);
				tmplog("Pixel type " , vals[++j]);
				tmplog("Color bits" , vals[++j]);
				tmplog("Red bits " , vals[++j]);
				tmplog("Red shift " , vals[++j]);
				tmplog("Green bits " , vals[++j]);
				tmplog("Green shift " , vals[++j]);
				tmplog("Blue bits " , vals[++j]);
				tmplog("Blue shift " , vals[++j]);
				tmplog("Alpha bits " , vals[++j]);
				tmplog("Alpha Shift " , vals[++j]);
				tmplog("Accum bits " , vals[++j]);
				tmplog("Accum red bits " , vals[++j]);
				tmplog("Accum green bits " , vals[++j]);
				tmplog("Accum blue bits " , vals[++j]);
				tmplog("Accum alpha bits " , vals[++j]);
				tmplog("Depth bits " , vals[++j]);
				tmplog("Stencil bits " , vals[++j]);
				tmplog("Aux buffers " , vals[++j]);
				if (render_texture_supported)
				{
					tmplog("Bind to texture RGB" , vals[++j]);
					tmplog("Bind to texture RGBA" , vals[++j]);
				}
				if (pbuffer_supported)
				{
					tmplog("Draw to pbuffer" , vals[++j]);
					tmplog("Max pbuffer pixels " , vals[++j]);
					tmplog("Max pbuffer width" , vals[++j]);
					tmplog("Max pbuffer height" , vals[++j]);
				}
				if (framebuffer_sRGB_supported)
					tmplog("Framebuffer sRBG capable" , vals[++j]);
				if (multi_sample_supported)
				{
					tmplog("Samples " , vals[++j]);
					tmplog("Sample buffers " , vals[++j]);
				}
				if (depth_float_supported)
					tmplog("Depth float" , vals[++j]);
#undef tmplog
			}
		}
	}
#endif
#elif defined(NIRT_LINUX_DEVICE)
#endif
}


void COpenGLExtensionHandler::initExtensions(bool stencilBuffer)
{
	const f32 ogl_ver = core::fast_atof(reinterpret_cast<const c8*>(glGetString(GL_VERSION)));
	Version = static_cast<u16>(core::floor32(ogl_ver)*100+core::round32(core::fract(ogl_ver)*10.0f));
	if ( Version >= 102)
		os::Printer::log("OpenGL driver version is 1.2 or better.", ELL_INFORMATION);
	else
		os::Printer::log("OpenGL driver version is not 1.2 or better.", ELL_WARNING);

	{
		const char* t = reinterpret_cast<const char*>(glGetString(GL_EXTENSIONS));
		size_t len = 0;
		c8 *str = 0;
		if (t)
		{
			len = strlen(t);
			str = new c8[len+1];
		}
		c8* p = str;

		for (size_t i=0; i<len; ++i)
		{
			str[i] = static_cast<char>(t[i]);

			if (str[i] == ' ')
			{
				str[i] = 0;
				for (u32 j=0; j<NIRT_OpenGL_Feature_Count; ++j)
				{
					if (!strcmp(OpenGLFeatureStrings[j], p))
					{
						FeatureAvailable[j] = true;
						break;
					}
				}

				p = p + strlen(p) + 1;
			}
		}

		delete [] str;
	}

	TextureCompressionExtension = FeatureAvailable[NIRT_ARB_texture_compression];
	StencilBuffer=stencilBuffer;

	const char* renderer = (const char*)glGetString(GL_RENDERER);
	if ( renderer )
	{
		IsAtiRadeonX = (strncmp(renderer, "ATI RADEON X", 12) == 0) || (strncmp(renderer, "ATI MOBILITY RADEON X", 21) == 0);
	}

#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
#ifdef _NIRT_WINDOWS_API_
	#define NIRT_OGL_LOAD_EXTENSION(x) wglGetProcAddress(reinterpret_cast<const char*>(x))
#elif defined(_NIRT_COMPILE_WITH_SDL_DEVICE_) && !defined(_NIRT_COMPILE_WITH_X11_DEVICE_)
	#define NIRT_OGL_LOAD_EXTENSION(x) SDL_GL_GetProcAddress(reinterpret_cast<const char*>(x))
#else
	// Accessing the correct function is quite complex
	// All libraries should support the ARB version, however
	// since GLX 1.4 the non-ARB version is the official one
	// So we have to check the runtime environment and
	// choose the proper symbol
	// In case you still have problems please enable the
	// next line by uncommenting it
	// #define _NIRT_GETPROCADDRESS_WORKAROUND_

	#ifndef _NIRT_GETPROCADDRESS_WORKAROUND_
	__GLXextFuncPtr (*NIRT_OGL_LOAD_EXTENSION_FUNCP)(const GLubyte*)=0;
	#ifdef GLX_VERSION_1_4
		int major=0,minor=0;
		if (glXGetCurrentDisplay())
			glXQueryVersion(glXGetCurrentDisplay(), &major, &minor);
		if ((major>1) || (minor>3))
			NIRT_OGL_LOAD_EXTENSION_FUNCP=glXGetProcAddress;
		else
	#endif
			NIRT_OGL_LOAD_EXTENSION_FUNCP=glXGetProcAddressARB;
		#define NIRT_OGL_LOAD_EXTENSION(X) NIRT_OGL_LOAD_EXTENSION_FUNCP(reinterpret_cast<const GLubyte*>(X))
	#else
		#define NIRT_OGL_LOAD_EXTENSION(X) glXGetProcAddressARB(reinterpret_cast<const GLubyte*>(X))
	#endif // workaround
#endif // Windows, SDL, or Linux

	// get multitexturing function pointers
	pGlActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC) NIRT_OGL_LOAD_EXTENSION("glActiveTextureARB");
	pGlClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC) NIRT_OGL_LOAD_EXTENSION("glClientActiveTextureARB");

	// get fragment and vertex program function pointers
	pGlGenProgramsARB = (PFNGLGENPROGRAMSARBPROC) NIRT_OGL_LOAD_EXTENSION("glGenProgramsARB");
	pGlGenProgramsNV = (PFNGLGENPROGRAMSNVPROC) NIRT_OGL_LOAD_EXTENSION("glGenProgramsNV");
	pGlBindProgramARB = (PFNGLBINDPROGRAMARBPROC) NIRT_OGL_LOAD_EXTENSION("glBindProgramARB");
	pGlBindProgramNV = (PFNGLBINDPROGRAMNVPROC) NIRT_OGL_LOAD_EXTENSION("glBindProgramNV");
	pGlProgramStringARB = (PFNGLPROGRAMSTRINGARBPROC) NIRT_OGL_LOAD_EXTENSION("glProgramStringARB");
	pGlLoadProgramNV = (PFNGLLOADPROGRAMNVPROC) NIRT_OGL_LOAD_EXTENSION("glLoadProgramNV");
	pGlDeleteProgramsARB = (PFNGLDELETEPROGRAMSARBPROC) NIRT_OGL_LOAD_EXTENSION("glDeleteProgramsARB");
	pGlDeleteProgramsNV = (PFNGLDELETEPROGRAMSNVPROC) NIRT_OGL_LOAD_EXTENSION("glDeleteProgramsNV");
	pGlProgramLocalParameter4fvARB = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC) NIRT_OGL_LOAD_EXTENSION("glProgramLocalParameter4fvARB");
	pGlCreateShaderObjectARB = (PFNGLCREATESHADEROBJECTARBPROC) NIRT_OGL_LOAD_EXTENSION("glCreateShaderObjectARB");
	pGlCreateShader = (PFNGLCREATESHADERPROC) NIRT_OGL_LOAD_EXTENSION("glCreateShader");
	pGlShaderSourceARB = (PFNGLSHADERSOURCEARBPROC) NIRT_OGL_LOAD_EXTENSION("glShaderSourceARB");
	pGlShaderSource = (PFNGLSHADERSOURCEPROC) NIRT_OGL_LOAD_EXTENSION("glShaderSource");
	pGlCompileShaderARB = (PFNGLCOMPILESHADERARBPROC) NIRT_OGL_LOAD_EXTENSION("glCompileShaderARB");
	pGlCompileShader = (PFNGLCOMPILESHADERPROC) NIRT_OGL_LOAD_EXTENSION("glCompileShader");
	pGlCreateProgramObjectARB = (PFNGLCREATEPROGRAMOBJECTARBPROC) NIRT_OGL_LOAD_EXTENSION("glCreateProgramObjectARB");
	pGlCreateProgram = (PFNGLCREATEPROGRAMPROC) NIRT_OGL_LOAD_EXTENSION("glCreateProgram");
	pGlAttachObjectARB = (PFNGLATTACHOBJECTARBPROC) NIRT_OGL_LOAD_EXTENSION("glAttachObjectARB");
	pGlAttachShader = (PFNGLATTACHSHADERPROC) NIRT_OGL_LOAD_EXTENSION("glAttachShader");
	pGlLinkProgramARB = (PFNGLLINKPROGRAMARBPROC) NIRT_OGL_LOAD_EXTENSION("glLinkProgramARB");
	pGlLinkProgram = (PFNGLLINKPROGRAMPROC) NIRT_OGL_LOAD_EXTENSION("glLinkProgram");
	pGlUseProgramObjectARB = (PFNGLUSEPROGRAMOBJECTARBPROC) NIRT_OGL_LOAD_EXTENSION("glUseProgramObjectARB");
	pGlUseProgram = (PFNGLUSEPROGRAMPROC) NIRT_OGL_LOAD_EXTENSION("glUseProgram");
	pGlDeleteObjectARB = (PFNGLDELETEOBJECTARBPROC) NIRT_OGL_LOAD_EXTENSION("glDeleteObjectARB");
	pGlDeleteProgram = (PFNGLDELETEPROGRAMPROC) NIRT_OGL_LOAD_EXTENSION("glDeleteProgram");
	pGlDeleteShader = (PFNGLDELETESHADERPROC) NIRT_OGL_LOAD_EXTENSION("glDeleteShader");
	pGlGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC) NIRT_OGL_LOAD_EXTENSION("glGetAttachedShaders");
	pGlGetAttachedObjectsARB = (PFNGLGETATTACHEDOBJECTSARBPROC) NIRT_OGL_LOAD_EXTENSION("glGetAttachedObjectsARB");
	pGlGetInfoLogARB = (PFNGLGETINFOLOGARBPROC) NIRT_OGL_LOAD_EXTENSION("glGetInfoLogARB");
	pGlGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC) NIRT_OGL_LOAD_EXTENSION("glGetShaderInfoLog");
	pGlGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC) NIRT_OGL_LOAD_EXTENSION("glGetProgramInfoLog");
	pGlGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC) NIRT_OGL_LOAD_EXTENSION("glGetObjectParameterivARB");
	pGlGetShaderiv = (PFNGLGETSHADERIVPROC) NIRT_OGL_LOAD_EXTENSION("glGetShaderiv");
	pGlGetProgramiv = (PFNGLGETPROGRAMIVPROC) NIRT_OGL_LOAD_EXTENSION("glGetProgramiv");
	pGlGetUniformLocationARB = (PFNGLGETUNIFORMLOCATIONARBPROC) NIRT_OGL_LOAD_EXTENSION("glGetUniformLocationARB");
	pGlGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC) NIRT_OGL_LOAD_EXTENSION("glGetUniformLocation");
	pGlUniform1fvARB = (PFNGLUNIFORM1FVARBPROC) NIRT_OGL_LOAD_EXTENSION("glUniform1fvARB");
	pGlUniform2fvARB = (PFNGLUNIFORM2FVARBPROC) NIRT_OGL_LOAD_EXTENSION("glUniform2fvARB");
	pGlUniform3fvARB = (PFNGLUNIFORM3FVARBPROC) NIRT_OGL_LOAD_EXTENSION("glUniform3fvARB");
	pGlUniform4fvARB = (PFNGLUNIFORM4FVARBPROC) NIRT_OGL_LOAD_EXTENSION("glUniform4fvARB");
	pGlUniform1ivARB = (PFNGLUNIFORM1IVARBPROC) NIRT_OGL_LOAD_EXTENSION("glUniform1ivARB");
	pGlUniform2ivARB = (PFNGLUNIFORM2IVARBPROC) NIRT_OGL_LOAD_EXTENSION("glUniform2ivARB");
	pGlUniform3ivARB = (PFNGLUNIFORM3IVARBPROC) NIRT_OGL_LOAD_EXTENSION("glUniform3ivARB");
	pGlUniform4ivARB = (PFNGLUNIFORM4IVARBPROC) NIRT_OGL_LOAD_EXTENSION("glUniform4ivARB");
	pGlUniform1uiv = (PFNGLUNIFORM1UIVPROC) NIRT_OGL_LOAD_EXTENSION("glUniform1uiv");
	pGlUniform2uiv = (PFNGLUNIFORM2UIVPROC) NIRT_OGL_LOAD_EXTENSION("glUniform2uiv");
	pGlUniform3uiv = (PFNGLUNIFORM3UIVPROC) NIRT_OGL_LOAD_EXTENSION("glUniform3uiv");
	pGlUniform4uiv = (PFNGLUNIFORM4UIVPROC) NIRT_OGL_LOAD_EXTENSION("glUniform4uiv");
	pGlUniformMatrix2fvARB = (PFNGLUNIFORMMATRIX2FVARBPROC) NIRT_OGL_LOAD_EXTENSION("glUniformMatrix2fvARB");
	pGlUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC) NIRT_OGL_LOAD_EXTENSION("glUniformMatrix2x3fv");
	pGlUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)NIRT_OGL_LOAD_EXTENSION("glUniformMatrix2x4fv");
	pGlUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)NIRT_OGL_LOAD_EXTENSION("glUniformMatrix3x2fv");
	pGlUniformMatrix3fvARB = (PFNGLUNIFORMMATRIX3FVARBPROC) NIRT_OGL_LOAD_EXTENSION("glUniformMatrix3fvARB");
	pGlUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)NIRT_OGL_LOAD_EXTENSION("glUniformMatrix3x4fv");
	pGlUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)NIRT_OGL_LOAD_EXTENSION("glUniformMatrix4x2fv");
	pGlUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)NIRT_OGL_LOAD_EXTENSION("glUniformMatrix4x3fv");
	pGlUniformMatrix4fvARB = (PFNGLUNIFORMMATRIX4FVARBPROC) NIRT_OGL_LOAD_EXTENSION("glUniformMatrix4fvARB");
	pGlGetActiveUniformARB = (PFNGLGETACTIVEUNIFORMARBPROC) NIRT_OGL_LOAD_EXTENSION("glGetActiveUniformARB");
	pGlGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC) NIRT_OGL_LOAD_EXTENSION("glGetActiveUniform");

	// get point parameter extension
	pGlPointParameterfARB = (PFNGLPOINTPARAMETERFARBPROC) NIRT_OGL_LOAD_EXTENSION("glPointParameterfARB");
	pGlPointParameterfvARB = (PFNGLPOINTPARAMETERFVARBPROC) NIRT_OGL_LOAD_EXTENSION("glPointParameterfvARB");

	// get stencil extension
	pGlStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC) NIRT_OGL_LOAD_EXTENSION("glStencilFuncSeparate");
	pGlStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC) NIRT_OGL_LOAD_EXTENSION("glStencilOpSeparate");
	pGlStencilFuncSeparateATI = (PFNGLSTENCILFUNCSEPARATEATIPROC) NIRT_OGL_LOAD_EXTENSION("glStencilFuncSeparateATI");
	pGlStencilOpSeparateATI = (PFNGLSTENCILOPSEPARATEATIPROC) NIRT_OGL_LOAD_EXTENSION("glStencilOpSeparateATI");

	// compressed textures
	pGlCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC) NIRT_OGL_LOAD_EXTENSION("glCompressedTexImage2D");
	pGlCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) NIRT_OGL_LOAD_EXTENSION("glCompressedTexSubImage2D");

	// ARB FrameBufferObjects
	pGlBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC) NIRT_OGL_LOAD_EXTENSION("glBindFramebuffer");
	pGlDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC) NIRT_OGL_LOAD_EXTENSION("glDeleteFramebuffers");
	pGlGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC) NIRT_OGL_LOAD_EXTENSION("glGenFramebuffers");
	pGlCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC) NIRT_OGL_LOAD_EXTENSION("glCheckFramebufferStatus");
	pGlFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC) NIRT_OGL_LOAD_EXTENSION("glFramebufferTexture2D");
	pGlBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC) NIRT_OGL_LOAD_EXTENSION("glBindRenderbuffer");
	pGlDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC) NIRT_OGL_LOAD_EXTENSION("glDeleteRenderbuffers");
	pGlGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC) NIRT_OGL_LOAD_EXTENSION("glGenRenderbuffers");
	pGlRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC) NIRT_OGL_LOAD_EXTENSION("glRenderbufferStorage");
	pGlFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC) NIRT_OGL_LOAD_EXTENSION("glFramebufferRenderbuffer");
	pGlGenerateMipmap = (PFNGLGENERATEMIPMAPPROC) NIRT_OGL_LOAD_EXTENSION("glGenerateMipmap");

	// EXT FrameBufferObjects
	pGlBindFramebufferEXT = (PFNGLBINDFRAMEBUFFEREXTPROC) NIRT_OGL_LOAD_EXTENSION("glBindFramebufferEXT");
	pGlDeleteFramebuffersEXT = (PFNGLDELETEFRAMEBUFFERSEXTPROC) NIRT_OGL_LOAD_EXTENSION("glDeleteFramebuffersEXT");
	pGlGenFramebuffersEXT = (PFNGLGENFRAMEBUFFERSEXTPROC) NIRT_OGL_LOAD_EXTENSION("glGenFramebuffersEXT");
	pGlCheckFramebufferStatusEXT = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC) NIRT_OGL_LOAD_EXTENSION("glCheckFramebufferStatusEXT");
	pGlFramebufferTexture2DEXT = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC) NIRT_OGL_LOAD_EXTENSION("glFramebufferTexture2DEXT");
	pGlBindRenderbufferEXT = (PFNGLBINDRENDERBUFFEREXTPROC) NIRT_OGL_LOAD_EXTENSION("glBindRenderbufferEXT");
	pGlDeleteRenderbuffersEXT = (PFNGLDELETERENDERBUFFERSEXTPROC) NIRT_OGL_LOAD_EXTENSION("glDeleteRenderbuffersEXT");
	pGlGenRenderbuffersEXT = (PFNGLGENRENDERBUFFERSEXTPROC) NIRT_OGL_LOAD_EXTENSION("glGenRenderbuffersEXT");
	pGlRenderbufferStorageEXT = (PFNGLRENDERBUFFERSTORAGEEXTPROC) NIRT_OGL_LOAD_EXTENSION("glRenderbufferStorageEXT");
	pGlFramebufferRenderbufferEXT = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC) NIRT_OGL_LOAD_EXTENSION("glFramebufferRenderbufferEXT");
	pGlGenerateMipmapEXT = (PFNGLGENERATEMIPMAPEXTPROC) NIRT_OGL_LOAD_EXTENSION("glGenerateMipmapEXT");
	pGlDrawBuffersARB = (PFNGLDRAWBUFFERSARBPROC) NIRT_OGL_LOAD_EXTENSION("glDrawBuffersARB");
	pGlDrawBuffersATI = (PFNGLDRAWBUFFERSATIPROC) NIRT_OGL_LOAD_EXTENSION("glDrawBuffersATI");

	// get vertex buffer extension
	pGlGenBuffersARB = (PFNGLGENBUFFERSARBPROC) NIRT_OGL_LOAD_EXTENSION("glGenBuffersARB");
	pGlBindBufferARB = (PFNGLBINDBUFFERARBPROC) NIRT_OGL_LOAD_EXTENSION("glBindBufferARB");
	pGlBufferDataARB = (PFNGLBUFFERDATAARBPROC) NIRT_OGL_LOAD_EXTENSION("glBufferDataARB");
	pGlDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC) NIRT_OGL_LOAD_EXTENSION("glDeleteBuffersARB");
	pGlBufferSubDataARB= (PFNGLBUFFERSUBDATAARBPROC) NIRT_OGL_LOAD_EXTENSION("glBufferSubDataARB");
	pGlGetBufferSubDataARB= (PFNGLGETBUFFERSUBDATAARBPROC)NIRT_OGL_LOAD_EXTENSION("glGetBufferSubDataARB");
	pGlMapBufferARB= (PFNGLMAPBUFFERARBPROC) NIRT_OGL_LOAD_EXTENSION("glMapBufferARB");
	pGlUnmapBufferARB= (PFNGLUNMAPBUFFERARBPROC) NIRT_OGL_LOAD_EXTENSION("glUnmapBufferARB");
	pGlIsBufferARB= (PFNGLISBUFFERARBPROC) NIRT_OGL_LOAD_EXTENSION("glIsBufferARB");
	pGlGetBufferParameterivARB= (PFNGLGETBUFFERPARAMETERIVARBPROC) NIRT_OGL_LOAD_EXTENSION("glGetBufferParameterivARB");
	pGlGetBufferPointervARB= (PFNGLGETBUFFERPOINTERVARBPROC) NIRT_OGL_LOAD_EXTENSION("glGetBufferPointervARB");
	pGlProvokingVertexARB= (PFNGLPROVOKINGVERTEXPROC) NIRT_OGL_LOAD_EXTENSION("glProvokingVertex");
	pGlProvokingVertexEXT= (PFNGLPROVOKINGVERTEXEXTPROC) NIRT_OGL_LOAD_EXTENSION("glProvokingVertexEXT");
	pGlProgramParameteriARB= (PFNGLPROGRAMPARAMETERIARBPROC) NIRT_OGL_LOAD_EXTENSION("glProgramParameteriARB");
	pGlProgramParameteriEXT= (PFNGLPROGRAMPARAMETERIEXTPROC) NIRT_OGL_LOAD_EXTENSION("glProgramParameteriEXT");

	// occlusion query
	pGlGenQueriesARB = (PFNGLGENQUERIESARBPROC) NIRT_OGL_LOAD_EXTENSION("glGenQueriesARB");
	pGlDeleteQueriesARB = (PFNGLDELETEQUERIESARBPROC) NIRT_OGL_LOAD_EXTENSION("glDeleteQueriesARB");
	pGlIsQueryARB = (PFNGLISQUERYARBPROC) NIRT_OGL_LOAD_EXTENSION("glIsQueryARB");
	pGlBeginQueryARB = (PFNGLBEGINQUERYARBPROC) NIRT_OGL_LOAD_EXTENSION("glBeginQueryARB");
	pGlEndQueryARB = (PFNGLENDQUERYARBPROC) NIRT_OGL_LOAD_EXTENSION("glEndQueryARB");
	pGlGetQueryivARB = (PFNGLGETQUERYIVARBPROC) NIRT_OGL_LOAD_EXTENSION("glGetQueryivARB");
	pGlGetQueryObjectivARB = (PFNGLGETQUERYOBJECTIVARBPROC) NIRT_OGL_LOAD_EXTENSION("glGetQueryObjectivARB");
	pGlGetQueryObjectuivARB = (PFNGLGETQUERYOBJECTUIVARBPROC) NIRT_OGL_LOAD_EXTENSION("glGetQueryObjectuivARB");
	pGlGenOcclusionQueriesNV = (PFNGLGENOCCLUSIONQUERIESNVPROC) NIRT_OGL_LOAD_EXTENSION("glGenOcclusionQueriesNV");
	pGlDeleteOcclusionQueriesNV = (PFNGLDELETEOCCLUSIONQUERIESNVPROC) NIRT_OGL_LOAD_EXTENSION("glDeleteOcclusionQueriesNV");
	pGlIsOcclusionQueryNV = (PFNGLISOCCLUSIONQUERYNVPROC) NIRT_OGL_LOAD_EXTENSION("glIsOcclusionQueryNV");
	pGlBeginOcclusionQueryNV = (PFNGLBEGINOCCLUSIONQUERYNVPROC) NIRT_OGL_LOAD_EXTENSION("glBeginOcclusionQueryNV");
	pGlEndOcclusionQueryNV = (PFNGLENDOCCLUSIONQUERYNVPROC) NIRT_OGL_LOAD_EXTENSION("glEndOcclusionQueryNV");
	pGlGetOcclusionQueryivNV = (PFNGLGETOCCLUSIONQUERYIVNVPROC) NIRT_OGL_LOAD_EXTENSION("glGetOcclusionQueryivNV");
	pGlGetOcclusionQueryuivNV = (PFNGLGETOCCLUSIONQUERYUIVNVPROC) NIRT_OGL_LOAD_EXTENSION("glGetOcclusionQueryuivNV");

	// blend
	pGlBlendFuncSeparateEXT = (PFNGLBLENDFUNCSEPARATEEXTPROC) NIRT_OGL_LOAD_EXTENSION("glBlendFuncSeparateEXT");
	pGlBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC) NIRT_OGL_LOAD_EXTENSION("glBlendFuncSeparate");
	pGlBlendEquationEXT = (PFNGLBLENDEQUATIONEXTPROC) NIRT_OGL_LOAD_EXTENSION("glBlendEquationEXT");
	pGlBlendEquation = (PFNGLBLENDEQUATIONPROC) NIRT_OGL_LOAD_EXTENSION("glBlendEquation");
	pGlBlendEquationSeparateEXT = (PFNGLBLENDEQUATIONSEPARATEEXTPROC) NIRT_OGL_LOAD_EXTENSION("glBlendEquationSeparateEXT");
	pGlBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC) NIRT_OGL_LOAD_EXTENSION("glBlendEquationSeparate");

	// indexed
	pGlEnableIndexedEXT = (PFNGLENABLEINDEXEDEXTPROC) NIRT_OGL_LOAD_EXTENSION("glEnableIndexedEXT");
	pGlDisableIndexedEXT = (PFNGLDISABLEINDEXEDEXTPROC) NIRT_OGL_LOAD_EXTENSION("glDisableIndexedEXT");
	pGlColorMaskIndexedEXT = (PFNGLCOLORMASKINDEXEDEXTPROC) NIRT_OGL_LOAD_EXTENSION("glColorMaskIndexedEXT");
	pGlBlendFuncIndexedAMD = (PFNGLBLENDFUNCINDEXEDAMDPROC) NIRT_OGL_LOAD_EXTENSION("glBlendFuncIndexedAMD");
	pGlBlendFunciARB = (PFNGLBLENDFUNCIPROC) NIRT_OGL_LOAD_EXTENSION("glBlendFunciARB");
	pGlBlendFuncSeparateIndexedAMD = (PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC) NIRT_OGL_LOAD_EXTENSION("glBlendFuncSeparateIndexedAMD");
	pGlBlendFuncSeparateiARB = (PFNGLBLENDFUNCSEPARATEIPROC) NIRT_OGL_LOAD_EXTENSION("glBlendFuncSeparateiARB");
	pGlBlendEquationIndexedAMD = (PFNGLBLENDEQUATIONINDEXEDAMDPROC) NIRT_OGL_LOAD_EXTENSION("glBlendEquationIndexedAMD");
	pGlBlendEquationiARB = (PFNGLBLENDEQUATIONIPROC) NIRT_OGL_LOAD_EXTENSION("glBlendEquationiARB");
	pGlBlendEquationSeparateIndexedAMD = (PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC) NIRT_OGL_LOAD_EXTENSION("glBlendEquationSeparateIndexedAMD");
	pGlBlendEquationSeparateiARB = (PFNGLBLENDEQUATIONSEPARATEIPROC) NIRT_OGL_LOAD_EXTENSION("glBlendEquationSeparateiARB");

    pGlTextureStorage2D = (PFNGLTEXTURESTORAGE2DPROC) NIRT_OGL_LOAD_EXTENSION("glTextureStorage2D");
    pGlTextureStorage3D = (PFNGLTEXTURESTORAGE3DPROC) NIRT_OGL_LOAD_EXTENSION("glTextureStorage3D");
	pGlTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2DPROC)NIRT_OGL_LOAD_EXTENSION("glTextureSubImage2D");
	pGlGetTextureImage = (PFNGLGETTEXTUREIMAGEPROC)NIRT_OGL_LOAD_EXTENSION("glGetTextureImage");
    pGlNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC) NIRT_OGL_LOAD_EXTENSION("glNamedFramebufferTexture");
    pGlTextureParameteri = (PFNGLTEXTUREPARAMETERIPROC) NIRT_OGL_LOAD_EXTENSION("glTextureParameteri");
	pGlTextureParameterf = (PFNGLTEXTUREPARAMETERFPROC)NIRT_OGL_LOAD_EXTENSION("glTextureParameterf");
	pGlTextureParameteriv = (PFNGLTEXTUREPARAMETERIVPROC)NIRT_OGL_LOAD_EXTENSION("glTextureParameteriv");
	pGlTextureParameterfv = (PFNGLTEXTUREPARAMETERFVPROC)NIRT_OGL_LOAD_EXTENSION("glTextureParameterfv");

    pGlCreateTextures = (PFNGLCREATETEXTURESPROC) NIRT_OGL_LOAD_EXTENSION("glCreateTextures");
    pGlCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERSPROC) NIRT_OGL_LOAD_EXTENSION("glCreateFramebuffers");
    pGlBindTextures = (PFNGLBINDTEXTURESPROC) NIRT_OGL_LOAD_EXTENSION("glBindTextures");
    pGlGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAPPROC) NIRT_OGL_LOAD_EXTENSION("glGenerateTextureMipmap");
    //==============================
    pGlTextureStorage2DEXT = (PFNGLTEXTURESTORAGE2DEXTPROC)NIRT_OGL_LOAD_EXTENSION("glTextureStorage2DEXT");
    pGlTexStorage2D = (PFNGLTEXSTORAGE2DPROC)NIRT_OGL_LOAD_EXTENSION("glTexStorage2D");
    pGlTextureStorage3DEXT = (PFNGLTEXTURESTORAGE3DEXTPROC)NIRT_OGL_LOAD_EXTENSION("glTextureStorage3DEXT");
    pGlTexStorage3D = (PFNGLTEXSTORAGE3DPROC)NIRT_OGL_LOAD_EXTENSION("glTexStorage3D");
	pGlTextureSubImage2DEXT = (PFNGLTEXTURESUBIMAGE2DEXTPROC)NIRT_OGL_LOAD_EXTENSION("glTextureSubImage2DEXT");
	pGlGetTextureImageEXT = (PFNGLGETTEXTUREIMAGEEXTPROC)NIRT_OGL_LOAD_EXTENSION("glGetTextureImageEXT");
    pGlNamedFramebufferTextureEXT = (PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)NIRT_OGL_LOAD_EXTENSION("glNamedFramebufferTextureEXT");
    pGlFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)NIRT_OGL_LOAD_EXTENSION("glFramebufferTexture");
    pGlActiveTexture = (PFNGLACTIVETEXTUREPROC)NIRT_OGL_LOAD_EXTENSION("glActiveTexture");
    pGlGenerateTextureMipmapEXT = (PFNGLGENERATETEXTUREMIPMAPEXTPROC) NIRT_OGL_LOAD_EXTENSION("glGenerateTextureMipmapEXT");

	// get vsync extension
	#if defined(WGL_EXT_swap_control) && !defined(_NIRT_COMPILE_WITH_SDL_DEVICE_)
		pWglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC) NIRT_OGL_LOAD_EXTENSION("wglSwapIntervalEXT");
	#endif
	#if defined(GLX_SGI_swap_control) && !defined(_NIRT_COMPILE_WITH_SDL_DEVICE_)
		pGlxSwapIntervalSGI = (PFNGLXSWAPINTERVALSGIPROC)NIRT_OGL_LOAD_EXTENSION("glXSwapIntervalSGI");
	#endif
	#if defined(GLX_EXT_swap_control) && !defined(_NIRT_COMPILE_WITH_SDL_DEVICE_)
		pGlxSwapIntervalEXT = (PFNGLXSWAPINTERVALEXTPROC)NIRT_OGL_LOAD_EXTENSION("glXSwapIntervalEXT");
	#endif
	#if defined(GLX_MESA_swap_control) && !defined(_NIRT_COMPILE_WITH_SDL_DEVICE_)
		pGlxSwapIntervalMESA = (PFNGLXSWAPINTERVALMESAPROC)NIRT_OGL_LOAD_EXTENSION("glXSwapIntervalMESA");
	#endif
#endif // use extension pointer

	GLint num=0;
	// set some properties
#if defined(GL_ARB_multitexture) || defined(GL_VERSION_1_3)
	if (Version>102 || FeatureAvailable[NIRT_ARB_multitexture])
	{
#if defined(GL_MAX_TEXTURE_UNITS)
		glGetIntegerv(GL_MAX_TEXTURE_UNITS, &num);
#elif defined(GL_MAX_TEXTURE_UNITS_ARB)
		glGetIntegerv(GL_MAX_TEXTURE_UNITS_ARB, &num);
#endif
		Feature.MaxTextureUnits=static_cast<u8>(num);	// MULTITEXTURING (fixed function pipeline texture units)
	}
#endif
#if defined(GL_ARB_vertex_shader) || defined(GL_VERSION_2_0)
	if (Version>=200 || FeatureAvailable[NIRT_ARB_vertex_shader])
	{
		num=0;
#if defined(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS)
		glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &num);
#elif defined(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB)
		glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB, &num);
#endif
		Feature.MaxTextureUnits =core::max_(Feature.MaxTextureUnits,static_cast<u8>(num));
	}
#endif
	glGetIntegerv(GL_MAX_LIGHTS, &num);
	MaxLights=static_cast<u8>(num);
#ifdef GL_EXT_texture_filter_anisotropic
	if (FeatureAvailable[NIRT_EXT_texture_filter_anisotropic])
	{
		glGetIntegerv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &num);
		MaxAnisotropy=static_cast<u8>(num);
	}
#endif
#ifdef GL_VERSION_1_2
	if (Version>101)
	{
		glGetIntegerv(GL_MAX_ELEMENTS_INDICES, &num);
		MaxIndices=num;
	}
#endif
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &num);
	MaxTextureSize=static_cast<u32>(num);
	if (queryFeature(EVDF_GEOMETRY_SHADER))
	{
#if defined(GL_ARB_geometry_shader4) || defined(GL_EXT_geometry_shader4) || defined(GL_NV_geometry_shader4)
		glGetIntegerv(GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT, &num);
		MaxGeometryVerticesOut=static_cast<u32>(num);
#elif defined(GL_NV_geometry_program4)
		extGlGetProgramiv(GEOMETRY_PROGRAM_NV, GL_MAX_PROGRAM_OUTPUT_VERTICES_NV, &num);
		MaxGeometryVerticesOut=static_cast<u32>(num);
#endif
	}
#ifdef GL_EXT_texture_lod_bias
	if (FeatureAvailable[NIRT_EXT_texture_lod_bias])
		glGetFloatv(GL_MAX_TEXTURE_LOD_BIAS_EXT, &MaxTextureLODBias);
#endif
	glGetIntegerv(GL_MAX_CLIP_PLANES, &num);
	MaxUserClipPlanes=static_cast<u8>(num);
	glGetIntegerv(GL_AUX_BUFFERS, &num);
	MaxAuxBuffers=static_cast<u8>(num);
#ifdef GL_ARB_draw_buffers
	if (FeatureAvailable[NIRT_ARB_draw_buffers])
	{
		glGetIntegerv(GL_MAX_DRAW_BUFFERS_ARB, &num);
		Feature.MultipleRenderTarget = static_cast<u8>(num);
	}
#endif
#if defined(GL_ATI_draw_buffers)
#ifdef GL_ARB_draw_buffers
	else
#endif
	if (FeatureAvailable[NIRT_ATI_draw_buffers])
	{
		glGetIntegerv(GL_MAX_DRAW_BUFFERS_ATI, &num);
		Feature.MultipleRenderTarget = static_cast<u8>(num);
	}
#endif
#ifdef GL_ARB_framebuffer_object
	if (FeatureAvailable[NIRT_ARB_framebuffer_object])
	{
		glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &num);
		Feature.ColorAttachment = static_cast<u8>(num);
	}
#endif
#if defined(GL_EXT_framebuffer_object)
#ifdef GL_ARB_framebuffer_object
	else
#endif
		if (FeatureAvailable[NIRT_EXT_framebuffer_object])
		{
			glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS_EXT, &num);
			Feature.ColorAttachment = static_cast<u8>(num);
		}
#endif

	glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, DimAliasedLine);
	glGetFloatv(GL_ALIASED_POINT_SIZE_RANGE, DimAliasedPoint);
	glGetFloatv(GL_SMOOTH_LINE_WIDTH_RANGE, DimSmoothedLine);
	glGetFloatv(GL_SMOOTH_POINT_SIZE_RANGE, DimSmoothedPoint);
#if defined(GL_ARB_shading_language_100) || defined (GL_VERSION_2_0)
	if (FeatureAvailable[NIRT_ARB_shading_language_100] || Version>=200)
	{
		glGetError(); // clean error buffer
#ifdef GL_SHADING_LANGUAGE_VERSION
		const GLubyte* shaderVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
#else
		const GLubyte* shaderVersion = glGetString(GL_SHADING_LANGUAGE_VERSION_ARB);
#endif
		if (glGetError() == GL_INVALID_ENUM)
			ShaderLanguageVersion = 100;
		else
		{
			const f32 sl_ver = core::fast_atof(reinterpret_cast<const c8*>(shaderVersion));
			ShaderLanguageVersion = static_cast<u16>(core::floor32(sl_ver)*100+core::round32(core::fract(sl_ver)*10.0f));
		}
	}
#endif

#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (!pGlActiveTextureARB || !pGlClientActiveTextureARB)
	{
		Feature.MaxTextureUnits = 1;
		os::Printer::log("Failed to load OpenGL's multitexture extension, proceeding without.", ELL_WARNING);
	}
	else
#endif
	Feature.MaxTextureUnits = core::min_(Feature.MaxTextureUnits, static_cast<u8>(MATERIAL_MAX_TEXTURES));
	Feature.MaxTextureUnits = core::min_(Feature.MaxTextureUnits, static_cast<u8>(MATERIAL_MAX_TEXTURES_USED));

#ifdef GL_ARB_occlusion_query
	if (FeatureAvailable[NIRT_ARB_occlusion_query])
	{
		extGlGetQueryiv(GL_SAMPLES_PASSED_ARB,GL_QUERY_COUNTER_BITS_ARB,
						&num);
		OcclusionQuerySupport=(num>0);
	}
	else
#endif
#ifdef GL_NV_occlusion_query
	if (FeatureAvailable[NIRT_NV_occlusion_query])
	{
		glGetIntegerv(GL_PIXEL_COUNTER_BITS_NV, &num);
		OcclusionQuerySupport=(num>0);
	}
	else
#endif
		OcclusionQuerySupport=false;

    Feature.BlendOperation = (Version >= 104) ||
            FeatureAvailable[NIRT_EXT_blend_minmax] ||
            FeatureAvailable[NIRT_EXT_blend_subtract] ||
            FeatureAvailable[NIRT_EXT_blend_logic_op];

#ifdef _DEBUG
	if (FeatureAvailable[NIRT_NVX_gpu_memory_info])
	{
		// undocumented flags, so use the RAW values
		GLint val;
		glGetIntegerv(0x9047, &val);
		os::Printer::log("Dedicated video memory (kB)", core::stringc(val));
		glGetIntegerv(0x9048, &val);
		os::Printer::log("Total video memory (kB)", core::stringc(val));
		glGetIntegerv(0x9049, &val);
		os::Printer::log("Available video memory (kB)", core::stringc(val));
	}
#ifdef GL_ATI_meminfo
	if (FeatureAvailable[NIRT_ATI_meminfo])
	{
		GLint val[4];
		glGetIntegerv(GL_TEXTURE_FREE_MEMORY_ATI, val);
		os::Printer::log("Free texture memory (kB)", core::stringc(val[0]));
		glGetIntegerv(GL_VBO_FREE_MEMORY_ATI, val);
		os::Printer::log("Free VBO memory (kB)", core::stringc(val[0]));
		glGetIntegerv(GL_RENDERBUFFER_FREE_MEMORY_ATI, val);
		os::Printer::log("Free render buffer memory (kB)", core::stringc(val[0]));
	}
#endif

	if (queryFeature(EVDF_TEXTURE_CUBEMAP_SEAMLESS))
		glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

#endif
}

const COpenGLCoreFeature& COpenGLExtensionHandler::getFeature() const
{
	return Feature;
}

bool COpenGLExtensionHandler::queryFeature(E_VIDEO_DRIVER_FEATURE feature) const
{
	switch (feature)
	{
	case EVDF_RENDER_TO_TARGET:
		return true;
	case EVDF_HARDWARE_TL:
		return true; // we cannot tell other things
	case EVDF_MULTITEXTURE:
		return Feature.MaxTextureUnits > 1;
	case EVDF_BILINEAR_FILTER:
		return true;
	case EVDF_MIP_MAP:
		return true;
	case EVDF_MIP_MAP_AUTO_UPDATE:
		return !IsAtiRadeonX && (FeatureAvailable[NIRT_SGIS_generate_mipmap] || FeatureAvailable[NIRT_EXT_framebuffer_object] || FeatureAvailable[NIRT_ARB_framebuffer_object]);
	case EVDF_STENCIL_BUFFER:
		return StencilBuffer;
	case EVDF_VERTEX_SHADER_1_1:
	case EVDF_ARB_VERTEX_PROGRAM_1:
		return FeatureAvailable[NIRT_ARB_vertex_program] || FeatureAvailable[NIRT_NV_vertex_program1_1];
	case EVDF_PIXEL_SHADER_1_1:
	case EVDF_PIXEL_SHADER_1_2:
	case EVDF_ARB_FRAGMENT_PROGRAM_1:
		return FeatureAvailable[NIRT_ARB_fragment_program] || FeatureAvailable[NIRT_NV_fragment_program];
	case EVDF_PIXEL_SHADER_2_0:
	case EVDF_VERTEX_SHADER_2_0:
	case EVDF_ARB_GLSL:
		return (FeatureAvailable[NIRT_ARB_shading_language_100]||Version>=200);
	case EVDF_TEXTURE_NSQUARE:
		return true; // non-square is always supported
	case EVDF_TEXTURE_NPOT:
		// Some ATI cards seem to have only SW support in OpenGL 2.0
		// drivers if the extension is not exposed, so we skip this
		// extra test for now!
		// return (FeatureAvailable[NIRT_ARB_texture_non_power_of_two]||Version>=200);
		return (FeatureAvailable[NIRT_ARB_texture_non_power_of_two]);
	case EVDF_FRAMEBUFFER_OBJECT:
		return FeatureAvailable[NIRT_EXT_framebuffer_object] || FeatureAvailable[NIRT_ARB_framebuffer_object];
	case EVDF_VERTEX_BUFFER_OBJECT:
		return FeatureAvailable[NIRT_ARB_vertex_buffer_object];
	case EVDF_COLOR_MASK:
		return true;
	case EVDF_ALPHA_TO_COVERAGE:
		return FeatureAvailable[NIRT_ARB_multisample];
	case EVDF_GEOMETRY_SHADER:
		return FeatureAvailable[NIRT_ARB_geometry_shader4] || FeatureAvailable[NIRT_EXT_geometry_shader4] || FeatureAvailable[NIRT_NV_geometry_program4] || FeatureAvailable[NIRT_NV_geometry_shader4];
	case EVDF_MULTIPLE_RENDER_TARGETS:
		return FeatureAvailable[NIRT_ARB_draw_buffers] || FeatureAvailable[NIRT_ATI_draw_buffers];
	case EVDF_MRT_BLEND:
	case EVDF_MRT_COLOR_MASK:
		return FeatureAvailable[NIRT_EXT_draw_buffers2];
	case EVDF_MRT_BLEND_FUNC:
		return FeatureAvailable[NIRT_ARB_draw_buffers_blend] || FeatureAvailable[NIRT_AMD_draw_buffers_blend];
	case EVDF_OCCLUSION_QUERY:
		return FeatureAvailable[NIRT_ARB_occlusion_query] && OcclusionQuerySupport;
	case EVDF_POLYGON_OFFSET:
		// both features supported with OpenGL 1.1
		return Version>=101;
	case EVDF_BLEND_OPERATIONS:
		return Feature.BlendOperation;
	case EVDF_BLEND_SEPARATE:
		return (Version>=104) || FeatureAvailable[NIRT_EXT_blend_func_separate];
	case EVDF_TEXTURE_MATRIX:
		return true;
	case EVDF_TEXTURE_COMPRESSED_DXT:
		return FeatureAvailable[NIRT_EXT_texture_compression_s3tc];
	case EVDF_TEXTURE_CUBEMAP:
		return (Version >= 103) || FeatureAvailable[NIRT_ARB_texture_cube_map] || FeatureAvailable[NIRT_EXT_texture_cube_map];
	case EVDF_TEXTURE_CUBEMAP_SEAMLESS:
		return FeatureAvailable[NIRT_ARB_seamless_cube_map];
	case EVDF_DEPTH_CLAMP:
		return FeatureAvailable[NIRT_NV_depth_clamp] || FeatureAvailable[NIRT_ARB_depth_clamp];

	default:
		return false;
	};
}


}
}

#endif
