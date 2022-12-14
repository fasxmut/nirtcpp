// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#include "CSceneNodeAnimatorTexture.hpp"
#include <nirtcpp/ITexture.hpp>

namespace nirt
{
namespace scene
{


//! constructor
CSceneNodeAnimatorTexture::CSceneNodeAnimatorTexture(const core::array<video::ITexture*>& textures,
					 s32 timePerFrame, bool loop, u32 now)
: ISceneNodeAnimatorFinishing(0),
	TimePerFrame(timePerFrame), Loop(loop)
{
	#ifdef _DEBUG
	setDebugName("CSceneNodeAnimatorTexture");
	#endif

	for (u32 i=0; i<textures.size(); ++i)
	{
		if (textures[i])
			textures[i]->grab();

		Textures.push_back(textures[i]);
	}

	StartTime = now;
	FinishTime = now + (timePerFrame * Textures.size());
}


//! destructor
CSceneNodeAnimatorTexture::~CSceneNodeAnimatorTexture()
{
	clearTextures();
}


void CSceneNodeAnimatorTexture::clearTextures()
{
	for (u32 i=0; i<Textures.size(); ++i)
		if (Textures[i])
			Textures[i]->drop();
}


//! animates a scene node
void CSceneNodeAnimatorTexture::animateNode(ISceneNode* node, u32 timeMs)
{
	if(!node)
		return;

	if (Textures.size())
	{
		const u32 t = (timeMs-(StartTime+PauseTimeSum));

		u32 idx = 0;
		if (!Loop && timeMs >= FinishTime+PauseTimeSum)
		{
			idx = Textures.size() - 1;
			HasFinished = true;
		}
		else
		{
			idx = (t/TimePerFrame) % Textures.size();
		}

		if (idx < Textures.size())
			node->setMaterialTexture(0, Textures[idx]);
	}
}


//! Writes attributes of the scene node animator.
void CSceneNodeAnimatorTexture::serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const
{
	ISceneNodeAnimatorFinishing::serializeAttributes(out, options);

	out->addInt("TimePerFrame", TimePerFrame);
	out->addBool("Loop", Loop);

	// add one texture in addition when serializing for editors
	// to make it easier to add textures quickly

	u32 count = Textures.size();
	if ( options && (options->Flags & io::EARWF_FOR_EDITOR))
		count += 1;

	for (u32 i=0; i<count; ++i)
	{
		core::stringc tname = "Texture";
		tname += (int)(i+1);

		out->addTexture(tname.data(), i<Textures.size() ? Textures[i] : 0);
	}
}


//! Reads attributes of the scene node animator.
void CSceneNodeAnimatorTexture::deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options)
{
	ISceneNodeAnimatorFinishing::deserializeAttributes(in, options);

	TimePerFrame = in->getAttributeAsInt("TimePerFrame");
	Loop = in->getAttributeAsBool("Loop");

	clearTextures();

	for(u32 i=1; true; ++i)
	{
		core::stringc tname = "Texture";
		tname += (int)i;

		if (in->existsAttribute(tname.data()))
		{
			video::ITexture* tex = in->getAttributeAsTexture(tname.data());
			if (tex)
			{
				tex->grab();
				Textures.push_back(tex);
			}
		}
		else
			break;
	}
}


ISceneNodeAnimator* CSceneNodeAnimatorTexture::createClone(ISceneNode* node, ISceneManager* newManager)
{
	CSceneNodeAnimatorTexture * newAnimator =
		new CSceneNodeAnimatorTexture(Textures, TimePerFrame, Loop, StartTime);
	newAnimator->cloneMembers(this);

	return newAnimator;
}


} // end namespace scene
} // end namespace nirt

