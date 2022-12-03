// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h
//
// created by Dean Wadsworth aka Varmint Dec 31 2007

#ifndef __VOLUME_LIGHT_SCENE_NODE_H_INCLUDED__
#define __VOLUME_LIGHT_SCENE_NODE_H_INCLUDED__

#include "IVolumeLightSceneNode.h"
#include "IMesh.h"

namespace nirt
{
namespace scene
{
	class CVolumeLightSceneNode : public IVolumeLightSceneNode
	{
	public:

		//! constructor
		CVolumeLightSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id,
			const u32 subdivU = 32, const u32 subdivV = 32,
			const video::SColor foot = video::SColor(51, 0, 230, 180),
			const video::SColor tail = video::SColor(0, 0, 0, 0),
			const core::vector3df& position = core::vector3df(0,0,0),
			const core::vector3df& rotation = core::vector3df(0,0,0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f));

		virtual ~CVolumeLightSceneNode();

		virtual void OnRegisterSceneNode() override;

		//! renders the node.
		virtual void render() override;

		//! returns the axis aligned bounding box of this node
		virtual const core::aabbox3d<f32>& getBoundingBox() const override;

		//! returns the material based on the zero based index i.
		virtual video::SMaterial& getMaterial(u32 i) override;

		//! returns amount of materials used by this scene node.
		virtual u32 getMaterialCount() const override;

		//! Returns type of the scene node
		virtual ESCENE_NODE_TYPE getType() const override { return ESNT_VOLUME_LIGHT; }

		//! Writes attributes of the scene node.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) const override;

		//! Reads attributes of the scene node.
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0) override;

		//! Creates a clone of this scene node and its children.
		virtual ISceneNode* clone(ISceneNode* newParent=0, ISceneManager* newManager=0) override;

		virtual void setSubDivideU(const u32 inU) override;
		virtual void setSubDivideV(const u32 inV) override;

		virtual u32 getSubDivideU() const override { return SubdivideU; }
		virtual u32 getSubDivideV() const override { return SubdivideV; }

		virtual void setFootColor(const video::SColor inColor) override;
		virtual void setTailColor(const video::SColor inColor) override;

		virtual video::SColor getFootColor() const override { return FootColor; }
		virtual video::SColor getTailColor() const override { return TailColor; }

	private:
		void constructLight();

		IMesh* Mesh;

		f32  LPDistance;		// Distance to hypothetical lightsource point -- affects fov angle

		u32  SubdivideU;		// Number of subdivisions in U and V space.
		u32  SubdivideV;		// Controls the number of "slices" in the volume.
		// NOTE : Total number of polygons = 2 + ((SubdivideU + 1) + (SubdivideV + 1)) * 2
		// Each slice being a quad plus the rectangular plane at the bottom.

		video::SColor FootColor;	// Color at the source
		video::SColor TailColor;	// Color at the end.

		// LightDimensions.Y Distance of shooting -- Length of beams
		// LightDimensions.X and LightDimensions.Z determine the
		// size/dimension of the plane
		core::vector3df LightDimensions;
	};

} // end namespace scene
} // end namespace nirt

#endif

