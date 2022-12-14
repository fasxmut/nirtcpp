// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_SCENE_NODE_ANIMATOR_TEXTURE_H_INCLUDED
#define NIRT_C_SCENE_NODE_ANIMATOR_TEXTURE_H_INCLUDED

#include <nirtcpp/irrArray.hpp>
#include "ISceneNodeAnimatorFinishing.hpp"

namespace nirt
{
namespace scene
{
	class CSceneNodeAnimatorTexture : public ISceneNodeAnimatorFinishing
	{
	public:

		//! constructor
		CSceneNodeAnimatorTexture(const core::array<video::ITexture*>& textures,
			s32 timePerFrame, bool loop, u32 now);

		//! destructor
		virtual ~CSceneNodeAnimatorTexture();

		//! animates a scene node
		virtual void animateNode(ISceneNode* node, u32 timeMs) override;

		//! Writes attributes of the scene node animator.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) const override;

		//! Reads attributes of the scene node animator.
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0) override;

		//! Returns type of the scene node animator
		virtual ESCENE_NODE_ANIMATOR_TYPE getType() const override { return ESNAT_TEXTURE; }

		//! Creates a clone of this animator.
		/** Please note that you will have to drop
		(IReferenceCounted::drop()) the returned pointer after calling
		this. */
		virtual ISceneNodeAnimator* createClone(ISceneNode* node, ISceneManager* newManager=0) override;


	private:

		void clearTextures();

		core::array<video::ITexture*> Textures;
		u32 TimePerFrame;
		bool Loop;
	};


} // end namespace scene
} // end namespace nirt

#endif
