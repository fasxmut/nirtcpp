// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_SOFTWARE_DRIVER_H_INCLUDED
#define NIRT_C_SOFTWARE_DRIVER_H_INCLUDED

#include "ITriangleRenderer.hpp"
#include "CNullDriver.hpp"
#include <nirtcpp/SViewFrustum.hpp>
#include "CImage.hpp"

namespace nirt
{
namespace video
{
	class CSoftwareDriver : public CNullDriver
	{
	public:

		//! constructor
		CSoftwareDriver(const core::dimension2d<u32>& windowSize, bool fullscreen, io::IFileSystem* io, video::IImagePresenter* presenter);

		//! destructor
		virtual ~CSoftwareDriver();

		//! queries the features of the driver, returns true if feature is available
		virtual bool queryFeature(E_VIDEO_DRIVER_FEATURE feature) const override;

		//! Create render target.
		virtual IRenderTarget* addRenderTarget() override;

		//! sets transformation
		virtual void setTransform(E_TRANSFORMATION_STATE state, const core::matrix4& mat) override;

		//! sets a material
		virtual void setMaterial(const SMaterial& material) override;

		virtual bool setRenderTargetEx(IRenderTarget* target, u16 clearFlag, SColor clearColor = SColor(255,0,0,0),
			f32 clearDepth = 1.f, u8 clearStencil = 0) override;

		//! sets a viewport
		virtual void setViewPort(const core::rect<s32>& area) override;

		virtual bool beginScene(u16 clearFlag, SColor clearColor = SColor(255,0,0,0), f32 clearDepth = 1.f, u8 clearStencil = 0,
			const SExposedVideoData& videoData = SExposedVideoData(), core::rect<s32>* sourceRect = 0) override;

		virtual bool endScene() override;

		//! Only used by the internal engine. Used to notify the driver that
		//! the window was resized.
		virtual void OnResize(const core::dimension2d<u32>& size) override;

		//! returns size of the current render target
		virtual const core::dimension2d<u32>& getCurrentRenderTargetSize() const override;

		//! draws a vertex primitive list
		virtual void drawVertexPrimitiveList(const void* vertices, u32 vertexCount,
				const void* indexList, u32 primitiveCount,
				E_VERTEX_TYPE vType, scene::E_PRIMITIVE_TYPE pType, E_INDEX_TYPE iType) override;

		//! Draws a 3d line.
		virtual void draw3DLine(const core::vector3df& start,
			const core::vector3df& end, SColor color = SColor(255,255,255,255)) override;

		//! draws an 2d image, using a color (if color is other then Color(255,255,255,255)) and the alpha channel of the texture if wanted.
		virtual void draw2DImage(const video::ITexture* texture, const core::position2d<s32>& destPos,
			const core::rect<s32>& sourceRect, const core::rect<s32>* clipRect = 0,
			SColor color=SColor(255,255,255,255), bool useAlphaChannelOfTexture=false) override;

		//! draw an 2d rectangle
		virtual void draw2DRectangle(SColor color, const core::rect<s32>& pos,
			const core::rect<s32>* clip = 0) override;

		//!Draws an 2d rectangle with a gradient.
		virtual void draw2DRectangle(const core::rect<s32>& pos,
			SColor colorLeftUp, SColor colorRightUp, SColor colorLeftDown, SColor colorRightDown,
			const core::rect<s32>* clip = 0) override;

		//! Draws a 2d line.
		virtual void draw2DLine(const core::position2d<s32>& start,
								const core::position2d<s32>& end,
								SColor color=SColor(255,255,255,255)) override;

		//! Draws a single pixel
		virtual void drawPixel(u32 x, u32 y, const SColor & color) override;

		//! \return Returns the name of the video driver. Example: In case of the Direct3D8
		//! driver, it would return "Direct3D8.1".
		virtual const wchar_t* getName() const override;

		//! Returns type of video driver
		virtual E_DRIVER_TYPE getDriverType() const override;

		//! get color format of the current color buffer
		virtual ECOLOR_FORMAT getColorFormat() const override;

		//! Returns the transformation set by setTransform
		virtual const core::matrix4& getTransform(E_TRANSFORMATION_STATE state) const override;

		virtual ITexture* createDeviceDependentTexture(const io::path& name, IImage* image) override;
		virtual ITexture* createDeviceDependentTextureCubemap(const io::path& name, const core::array<IImage*>& image) override;

		//! Creates a render target texture.
		virtual ITexture* addRenderTargetTexture(const core::dimension2d<u32>& size,
				const io::path& name, const ECOLOR_FORMAT format = ECF_UNKNOWN) override;

		virtual void clearBuffers(u16 flag, SColor color = SColor(255,0,0,0), f32 depth = 1.f, u8 stencil = 0) override;

		//! Returns an image created from the last rendered frame.
		virtual IImage* createScreenShot(video::ECOLOR_FORMAT format=video::ECF_UNKNOWN, video::E_RENDER_TARGET target=video::ERT_FRAME_BUFFER) override;

		//! Returns the maximum amount of primitives (mostly vertices) which
		//! the device is able to render with one drawIndexedTriangleList
		//! call.
		virtual u32 getMaximalPrimitiveCount() const override;

		//! Check if the driver supports creating textures with the given color format
		virtual bool queryTextureFormat(ECOLOR_FORMAT format) const override;

	protected:

		//! sets a render target
		void setRenderTargetImage(video::CImage* image);

		//! sets the current Texture
		bool setActiveTexture(u32 stage, video::ITexture* texture);

		//! switches to a triangle renderer
		void switchToTriangleRenderer(ETriangleRenderer renderer);

		//! void selects the right triangle renderer based on the render states.
		void selectRightTriangleRenderer();

		//! clips a triangle agains the viewing frustum
		void clipTriangle(f32* transformedPos);


		//! draws a vertex primitive list
		void drawVertexPrimitiveList16(const void* vertices, u32 vertexCount,
				const u16* indexList, u32 primitiveCount,
				E_VERTEX_TYPE vType, scene::E_PRIMITIVE_TYPE pType);


		template<class VERTEXTYPE>
		void drawClippedIndexedTriangleListT(const VERTEXTYPE* vertices,
			s32 vertexCount, const u16* indexList, s32 triangleCount);

		video::CImage* BackBuffer;
		video::IImagePresenter* Presenter;
		void* WindowId;
		core::rect<s32>* SceneSourceRect;

		core::array<S2DVertex> TransformedPoints;

		video::ITexture* RenderTargetTexture;
		video::CImage* RenderTargetSurface;
		core::position2d<s32> Render2DTranslation;
		core::dimension2d<u32> RenderTargetSize;
		core::dimension2d<u32> ViewPortSize;

		core::matrix4 TransformationMatrix[ETS_COUNT];

		ITriangleRenderer* CurrentTriangleRenderer;
		ITriangleRenderer* TriangleRenderers[ETR_COUNT];
		ETriangleRenderer CurrentRenderer;

		IZBuffer* ZBuffer;

		video::ITexture* Texture;

		SMaterial Material;
	};

} // end namespace video
} // end namespace nirt

#endif
