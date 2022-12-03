// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#include "IrrCompileConfig.h"
#ifdef _NIRT_COMPILE_WITH_MD3_LOADER_

#include "CMD3MeshFileLoader.h"
#include "CAnimatedMeshMD3.h"
#include "irrString.h"

namespace nirt
{
namespace scene
{

//! Constructor
CMD3MeshFileLoader::CMD3MeshFileLoader( scene::ISceneManager* smgr)
: SceneManager(smgr)
{
}


//! destructor
CMD3MeshFileLoader::~CMD3MeshFileLoader()
{
}


//! returns true if the file maybe is able to be loaded by this class
//! based on the file extension (e.g. ".bsp")
bool CMD3MeshFileLoader::isALoadableFileExtension(const io::path& filename) const
{
	return core::hasFileExtension ( filename, "md3" );
}


IAnimatedMesh* CMD3MeshFileLoader::createMesh(io::IReadFile* file)
{
	CAnimatedMeshMD3 * mesh = new CAnimatedMeshMD3();

	if ( mesh->loadModelFile ( 0, file, SceneManager->getFileSystem(), SceneManager->getVideoDriver() ) )
		return mesh;

	mesh->drop ();
	return 0;
}


} // end namespace scene
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_MD3_LOADER_