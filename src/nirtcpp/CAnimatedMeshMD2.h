// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_ANIMATED_MESH_MD2_H_INCLUDED
#define NIRT_C_ANIMATED_MESH_MD2_H_INCLUDED

#include "IAnimatedMeshMD2.h"
#include "IMesh.h"
#include "CMeshBuffer.h"
#include "IReadFile.h"
#include "S3DVertex.h"
#include "irrArray.h"
#include "irrString.h"

namespace nirt
{
namespace scene
{

	class CAnimatedMeshMD2 : public IAnimatedMeshMD2
	{
	public:

		//! constructor
		CAnimatedMeshMD2();

		//! destructor
		virtual ~CAnimatedMeshMD2();

		//! returns the amount of frames. If the amount is 1, it is a static (=non animated) mesh.
		virtual u32 getFrameCount() const override;

		//! Gets the default animation speed of the animated mesh.
		/** \return Amount of frames per second. If the amount is 0, it is a static, non animated mesh. */
		virtual f32 getAnimationSpeed() const override
		{
			return FramesPerSecond;
		}

		//! Gets the frame count of the animated mesh.
		/** \param fps Frames per second to play the animation with. If the amount is 0, it is not animated.
		The actual speed is set in the scene node the mesh is instantiated in.*/
		virtual void setAnimationSpeed(f32 fps) override
		{
			FramesPerSecond=fps;
		}

		//! returns the animated mesh based on a detail level. 0 is the lowest, 255 the highest detail. Note, that some Meshes will ignore the detail level.
		virtual IMesh* getMesh(s32 frame, s32 detailLevel=255, s32 startFrameLoop=-1, s32 endFrameLoop=-1) override;

		//! returns amount of mesh buffers.
		virtual u32 getMeshBufferCount() const override;

		//! returns pointer to a mesh buffer
		virtual IMeshBuffer* getMeshBuffer(u32 nr) const override;

		//! Returns pointer to a mesh buffer which fits a material
		/** \param material: material to search for
		\return Returns the pointer to the mesh buffer or
		NULL if there is no such mesh buffer. */
		virtual IMeshBuffer* getMeshBuffer( const video::SMaterial &material) const override;

		//! returns an axis aligned bounding box
		virtual const core::aabbox3d<f32>& getBoundingBox() const override;

		//! set user axis aligned bounding box
		virtual void setBoundingBox( const core::aabbox3df& box) override;

		//! sets a flag of all contained materials to a new value
		virtual void setMaterialFlag(video::E_MATERIAL_FLAG flag, bool newvalue) override;

		//! set the hardware mapping hint, for driver
		virtual void setHardwareMappingHint(E_HARDWARE_MAPPING newMappingHint, E_BUFFER_TYPE buffer=EBT_VERTEX_AND_INDEX) override;

		//! flags the meshbuffer as changed, reloads hardware buffers
		virtual void setDirty(E_BUFFER_TYPE buffer=EBT_VERTEX_AND_INDEX) override;

		//! Returns the type of the animated mesh.
		virtual E_ANIMATED_MESH_TYPE getMeshType() const override;

		//! Returns frame loop data for a special MD2 animation type.
		virtual void getFrameLoop(EMD2_ANIMATION_TYPE,
			s32& outBegin, s32& outEnd, s32& outFps) const override;

		//! Returns frame loop data for a special MD2 animation type.
		virtual bool getFrameLoop(const c8* name,
			s32& outBegin, s32& outEnd, s32& outFps) const override;

		//! Returns amount of md2 animations in this file.
		virtual s32 getAnimationCount() const override;

		//! Returns name of md2 animation.
		//! \param nr: Zero based index of animation.
		virtual const c8* getAnimationName(s32 nr) const override;


		//
		// exposed for loader
		//

		//! the buffer that contains the most recent animation
		SMeshBuffer* InterpolationBuffer;

		//! Frames used to calculate InterpolationBuffer
		u32 InterpolationFirstFrame, InterpolationSecondFrame;
		f32 InterpolationFrameDiv;

		//! named animations
		struct SAnimationData
		{
			core::stringc name;
			s32 begin;
			s32 end;
			s32 fps;
		};

		//! scale and translations for keyframes
		struct SKeyFrameTransform
		{
			core::vector3df scale;
			core::vector3df translate;
		};

		//! md2 vertex data
		struct SMD2Vert
		{
			core::vector3d<u8> Pos;
			u8                 NormalIdx;
		};

		//! keyframe transformations
		core::array<SKeyFrameTransform> FrameTransforms;

		//! keyframe vertex data
		core::array<SMD2Vert> *FrameList;

		//! bounding boxes for each keyframe
		core::array<core::aabbox3d<f32> > BoxList;

		//! named animations
		core::array< SAnimationData > AnimationData;

		u32 FrameCount;

	private:

		//! updates the interpolation buffer
		void updateInterpolationBuffer(s32 frame, s32 startFrame, s32 endFrame);

		f32 FramesPerSecond;
	};

} // end namespace scene
} // end namespace nirt

#endif
