// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp
//
// This Loader has been originally written by Saurav Mohapatra. I (Nikolaus Gebhardt)
// modified some minor things and integrated it into Nirtcpp 0.9. Thanks a lot
// to Saurav Mohapatra for his work on this and that he gave me his permission to
// add it into Nirtcpp.
// I did some changes to Saurav Mohapatra's loader, so I'm writing this down here:
// - Replaced all dependencies to STL and stdio with nirt:: methods/constructs.
// - Moved everything into namespace nirt::scene
// - Replaced logging with Nirtcpp's internal logger.
// - Removed dependency to NirtcppDevice
// - Moved all internal structures into CCSMLoader.cpp
// - Made the texture root parameter dependent on a ISceneManager string parameter
// - removed exceptions
// - Implemented CCCSMLoader as IMeshLoader
// - Fixed some problems with memory leaks
// - Fixed bounding box calculation
//
// The original readme of this file looks like this:
//
// This component provides a loader for the Cartography shop 4.x .csm maps for Nirtcpp Engine.
// This is a part of the M_TRIX Project.
// This is licensed under the ZLib/LibPNG license
// The IrrCSM library is written by Saurav Mohapatra.
//
// Features
//
// The IrrCSM library features the following capabilities
//
//  * Loads the .csm 4.0 and 4.1 files transparently
//  * Presents the loaded file as nirt::scene::IAnimatedMesh for easy creation of IOctreeSceneNode
//  * Loads the textures given the correct texture root. hence map and textures can be in separate directories
//
// For more information go to http://www.geocities.com/standard_template/irrcsm/downloads.html

#ifndef __CSM_LOADER_H_INCLUDED__
#define __CSM_LOADER_H_INCLUDED__

#include <nirtcpp/irrArray.hpp>
#include <nirtcpp/IMesh.hpp>
#include <nirtcpp/irrString.hpp>
#include <nirtcpp/IFileSystem.hpp>
#include <nirtcpp/IMeshLoader.hpp>

namespace nirt
{
namespace scene
{
	class CSMFile;
	class ISceneManager;

	class CCSMLoader : public scene::IMeshLoader
	{
	public:

		CCSMLoader(ISceneManager* manager, io::IFileSystem* fs);

		//! returns true if the file maybe is able to be loaded by this class
		//! based on the file extension (e.g. ".bsp")
		virtual bool isALoadableFileExtension(const io::path& filename) const override;

		//! creates/loads an animated mesh from the file.
		virtual IAnimatedMesh* createMesh(io::IReadFile* file) override;

	private:

		scene::IMesh* createCSMMesh(io::IReadFile* file);

		scene::IMesh* createNirtcppMesh(const CSMFile* csmFile, const io::path& lmprefix);

		io::IFileSystem* FileSystem;
		scene::ISceneManager* SceneManager;
	};

} // end namespace
} // end namespace

#endif

