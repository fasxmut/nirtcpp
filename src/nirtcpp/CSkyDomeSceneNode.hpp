// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp
// Code for this scene node has been contributed by Anders la Cour-Harbo (alc)

#ifndef NIRT_C_SKY_DOME_SCENE_NODE_H_INCLUDED
#define NIRT_C_SKY_DOME_SCENE_NODE_H_INCLUDED

#include <nirtcpp/ISceneNode.hpp>
#include <nirtcpp/SMeshBuffer.hpp>

namespace nirt
{
namespace scene
{

class CSkyDomeSceneNode : public ISceneNode
{
	public:
		CSkyDomeSceneNode(video::ITexture* texture, u32 horiRes, u32 vertRes,
			f32 texturePercentage, f32 spherePercentage, f32 radius,
			ISceneNode* parent, ISceneManager* smgr, s32 id);
		virtual ~CSkyDomeSceneNode();
		virtual void OnRegisterSceneNode() override;
		virtual void render() override;
		virtual const core::aabbox3d<f32>& getBoundingBox() const override;
		virtual video::SMaterial& getMaterial(u32 i) override;
		virtual u32 getMaterialCount() const override;
		virtual ESCENE_NODE_TYPE getType() const override { return ESNT_SKY_DOME; }

		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const override;
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options) override;
		virtual ISceneNode* clone(ISceneNode* newParent=0, ISceneManager* newManager=0) override;

	private:

		void generateMesh();

		SMeshBuffer* Buffer;

		u32 HorizontalResolution, VerticalResolution;
		f32 TexturePercentage, SpherePercentage, Radius;
};


}
}

#endif
