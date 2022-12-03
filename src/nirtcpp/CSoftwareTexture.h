// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_SOFTWARE_TEXTURE_H_INCLUDED
#define NIRT_C_SOFTWARE_TEXTURE_H_INCLUDED

#include "ITexture.h"
#include "IRenderTarget.h"
#include "CImage.h"

namespace irr
{
namespace video
{

class CSoftwareDriver;

/*!
	interface for a Video Driver dependent Texture.
*/
class CSoftwareTexture : public ITexture
{
public:

	//! constructor
	CSoftwareTexture(IImage* surface, const io::path& name, bool renderTarget=false);

	//! destructor
	virtual ~CSoftwareTexture();

	//! lock function
	virtual void* lock(E_TEXTURE_LOCK_MODE mode = ETLM_READ_WRITE, u32 mipmapLevel=0, u32 layer = 0, E_TEXTURE_LOCK_FLAGS lockFlags = ETLF_FLIP_Y_UP_RTT) override;

	//! unlock function
	virtual void unlock() override;

	//! returns unoptimized surface
	virtual CImage* getImage();

	//! returns texture surface
	virtual CImage* getTexture();

	virtual void regenerateMipMapLevels(void* data = 0, u32 layer = 0) override;

private:
	CImage* Image;
	CImage* Texture;
};

/*!
	interface for a Video Driver dependent render target.
*/
class CSoftwareRenderTarget : public IRenderTarget
{
public:
	CSoftwareRenderTarget(CSoftwareDriver* driver);
	virtual ~CSoftwareRenderTarget();

	virtual void setTextures(ITexture* const * textures, u32 numTextures, ITexture* depthStencil, const E_CUBE_SURFACE* cubeSurfaces, u32 numCubeSurfaces) override;

	ITexture* getTexture() const;

protected:
	CSoftwareDriver* Driver;
};


} // end namespace video
} // end namespace irr

#endif
