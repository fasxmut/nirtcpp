// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_GUI_IMAGE_H_INCLUDED
#define NIRT_C_GUI_IMAGE_H_INCLUDED

#include "IrrCompileConfig.h"
#ifdef _NIRT_COMPILE_WITH_GUI_

#include "IGUIImage.h"

namespace nirt
{
namespace gui
{

	class CGUIImage : public IGUIImage
	{
	public:

		//! constructor
		CGUIImage(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle);

		//! destructor
		virtual ~CGUIImage();

		//! sets an image
		virtual void setImage(video::ITexture* image) override;

		//! Gets the image texture
		virtual video::ITexture* getImage() const override;

		//! sets the color of the image
		virtual void setColor(video::SColor color) override;

		//! sets if the image should scale to fit the element
		virtual void setScaleImage(bool scale) override;

		//! draws the element and its children
		virtual void draw() override;

		//! sets if the image should use its alpha channel to draw itself
		virtual void setUseAlphaChannel(bool use) override;

		//! Gets the color of the image
		virtual video::SColor getColor() const override;

		//! Returns true if the image is scaled to fit, false if not
		virtual bool isImageScaled() const override;

		//! Returns true if the image is using the alpha channel, false if not
		virtual bool isAlphaChannelUsed() const override;

		//! Sets the source rectangle of the image. By default the full image is used.
		virtual void setSourceRect(const core::rect<s32>& sourceRect) override;

		//! Returns the customized source rectangle of the image to be used.
		virtual core::rect<s32> getSourceRect() const override;

		//! Restrict drawing-area.
		virtual void setDrawBounds(const core::rect<f32>& drawBoundUVs) override;

		//! Get drawing-area restrictions.
		virtual core::rect<f32> getDrawBounds() const override;

		//! Sets whether to draw a background color (EGDC_3D_DARK_SHADOW) when no texture is set
		virtual void setDrawBackground(bool draw) override
		{
			DrawBackground = draw;
		}

		//! Checks if a background is drawn when no texture is set
		virtual bool isDrawBackgroundEnabled() const  override
		{
			return DrawBackground;
		}

		//! Writes attributes of the element.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const override;

		//! Reads attributes of the element
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options) override;

	protected:
		void checkBounds(core::rect<s32>& rect)
		{
			f32 clipWidth = (f32)rect.getWidth();
			f32 clipHeight = (f32)rect.getHeight();

			rect.UpperLeftCorner.X += core::round32(DrawBounds.UpperLeftCorner.X*clipWidth);
			rect.UpperLeftCorner.Y += core::round32(DrawBounds.UpperLeftCorner.Y*clipHeight);
			rect.LowerRightCorner.X -= core::round32((1.f-DrawBounds.LowerRightCorner.X)*clipWidth);
			rect.LowerRightCorner.Y -= core::round32((1.f-DrawBounds.LowerRightCorner.Y)*clipHeight);
		}

	private:
		video::ITexture* Texture;
		video::SColor Color;
		bool UseAlphaChannel;
		bool ScaleImage;
		core::rect<s32> SourceRect;
		core::rect<f32> DrawBounds;
		bool DrawBackground;
	};


} // end namespace gui
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_GUI_

#endif // NIRT_C_GUI_IMAGE_H_INCLUDED
