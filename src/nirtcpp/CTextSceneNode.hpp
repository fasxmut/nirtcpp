// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_TEXT_SCENE_NODE_H_INCLUDED
#define NIRT_C_TEXT_SCENE_NODE_H_INCLUDED

#include <nirtcpp/ITextSceneNode.hpp>
#include <nirtcpp/IBillboardTextSceneNode.hpp>
#include <nirtcpp/IGUIFont.hpp>
#include <nirtcpp/IGUIFontBitmap.hpp>
#include <nirtcpp/ISceneCollisionManager.hpp>
#include <nirtcpp/SMesh.hpp>

namespace nirt
{
namespace scene
{

	class ICameraSceneNode;

	class CTextSceneNode : public ITextSceneNode
	{
	public:

		//! constructor
		CTextSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id,
			gui::IGUIFont* font, scene::ISceneCollisionManager* coll,
			const core::vector3df& position = core::vector3df(0,0,0), const wchar_t* text=0,
			video::SColor color=video::SColor(100,0,0,0));

		//! destructor
		virtual ~CTextSceneNode();

		virtual void OnRegisterSceneNode() override;

		//! renders the node.
		virtual void render() override;

		//! returns the axis aligned bounding box of this node
		virtual const core::aabbox3d<f32>& getBoundingBox() const override;

		//! sets the text string
		virtual void setText(const wchar_t* text) override;

		//! get the text string
		virtual const wchar_t* getText() const override;

		//! sets the color of the text
		virtual void setTextColor(video::SColor color) override;

		//! get the color of the text
		virtual video::SColor getTextColor() const override;

		//! set the font used to draw the text
		virtual void setFont(gui::IGUIFont* font) override;

		//! Get the font used to draw the text
		virtual gui::IGUIFont* getFont() const override;

		//! Returns type of the scene node
		virtual ESCENE_NODE_TYPE getType() const override { return ESNT_TEXT; }

	private:

		core::stringw Text;
		video::SColor Color;
		gui::IGUIFont* Font;
		scene::ISceneCollisionManager* Coll;
		core::aabbox3d<f32> Box;
	};

	class CBillboardTextSceneNode : public IBillboardTextSceneNode
	{
	public:

		CBillboardTextSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id,
			gui::IGUIFont* font,const wchar_t* text,
			const core::vector3df& position, const core::dimension2d<f32>& size,
			video::SColor colorTop, video::SColor shade_bottom);

		//! destructor
		virtual ~CBillboardTextSceneNode();

		//! sets the vertex positions etc
		virtual void OnAnimate(u32 timeMs) override;

		//! registers the node into the transparent pass
		virtual void OnRegisterSceneNode() override;

		//! renders the node.
		virtual void render() override;

		//! returns the axis aligned bounding box of this node
		virtual const core::aabbox3d<f32>& getBoundingBox() const override;

		//! sets the text string
		virtual void setText(const wchar_t* text) override;

		//! get the text string
		virtual const wchar_t* getText() const override;

		//! Get the font used to draw the text
		virtual gui::IGUIFont* getFont() const override;

		//! sets the size of the billboard
		virtual void setSize(const core::dimension2d<f32>& size) override;

		//! gets the size of the billboard
		virtual const core::dimension2d<f32>& getSize() const override;

		virtual video::SMaterial& getMaterial(u32 i) override;

		//! returns amount of materials used by this scene node.
		virtual u32 getMaterialCount() const override;

		//! Returns type of the scene node
		virtual ESCENE_NODE_TYPE getType() const override { return ESNT_BILLBOARD_TEXT; }

		//! Set the color of all vertices of the billboard
		//! \param overallColor: the color to set
		virtual void setColor(const video::SColor & overallColor) override;

		//! Set the color of the top and bottom vertices of the billboard
		//! \param topColor: the color to set the top vertices
		//! \param bottomColor: the color to set the bottom vertices
		virtual void setColor(const video::SColor & topColor, const video::SColor & bottomColor) override;

		//! Gets the color of the top and bottom vertices of the billboard
		//! \param topColor: stores the color of the top vertices
		//! \param bottomColor: stores the color of the bottom vertices
		virtual void getColor(video::SColor & topColor, video::SColor & bottomColor) const override;

		virtual void setSize(f32 height, f32 bottomEdgeWidth, f32 topEdgeWidth) override
		{
			setSize(core::dimension2df(bottomEdgeWidth, height));
		}

		virtual void getSize(f32& height, f32& bottomEdgeWidth, f32& topEdgeWidth) const override
		{
			height = Size.Height;
			bottomEdgeWidth = Size.Width;
			topEdgeWidth = Size.Width;
		}

		virtual const core::aabbox3d<f32>& getTransformedBillboardBoundingBox(const nirt::scene::ICameraSceneNode* camera) override;

		//! Get the amount of mesh buffers.
		virtual u32 getMeshBufferCount() const override
		{
			return Mesh ? Mesh->getMeshBufferCount() : 0;
		}

		//! Get pointer to the mesh buffer.
		virtual IMeshBuffer* getMeshBuffer(u32 nr) const override
		{
			return Mesh ? Mesh->getMeshBuffer(nr) : 0;
		}

	protected:
		void updateMesh(const nirt::scene::ICameraSceneNode* camera);

	private:

		core::stringw Text;
		gui::IGUIFontBitmap* Font;

		core::dimension2d<f32> Size;
		core::aabbox3d<f32> BBox;
		video::SMaterial Material;

		video::SColor ColorTop;
		video::SColor ColorBottom;
		struct SSymbolInfo
		{
			u32 bufNo;
			f32 Width;
			f32 Kerning;
			u32 firstInd;
			u32 firstVert;
		};

		core::array < SSymbolInfo > Symbol;

		SMesh *Mesh;
	};

} // end namespace scene
} // end namespace nirt

#endif
