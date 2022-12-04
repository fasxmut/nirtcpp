#include "CMeshTextureLoader.hpp"
#include <nirtcpp/IFileSystem.hpp>
#include <nirtcpp/IVideoDriver.hpp>

namespace nirt
{
namespace scene
{

CMeshTextureLoader::CMeshTextureLoader(nirt::io::IFileSystem* fs, nirt::video::IVideoDriver* driver)
: FileSystem(fs)
, VideoDriver(driver)
, MeshFile(0)
, MaterialFile(0)
{
}

//! Set a custom texture path.
void CMeshTextureLoader::setTexturePath(const nirt::io::path& path)
{
	TexturePath = path;
	preparePath(TexturePath);
}

//! Get the current custom texture path.
const nirt::io::path& CMeshTextureLoader::getTexturePath() const
{
	return TexturePath;
}

bool CMeshTextureLoader::checkTextureName( const nirt::io::path& filename)
{
	if (FileSystem->existFile(filename))
	{
		TextureName = filename;
		return true;
	}

	return false;
}

//! Get the texture by searching for it in all paths that makes sense for the given textureName.
nirt::video::ITexture* CMeshTextureLoader::getTexture(const nirt::io::path& textureName)
{
	if ( textureName.empty() || !FileSystem || !VideoDriver)
		return NULL;

	// Pre-process texture filename.
	nirt::io::path simplifiedTexName(textureName);
	simplifiedTexName.replace(NIRT_TEXT('\\'),NIRT_TEXT('/'));

	// user defined texture path
	if ( !TexturePath.empty() )
	{
		if ( checkTextureName(TexturePath + simplifiedTexName) )
			return VideoDriver->getTexture(TextureName);

		if ( checkTextureName(TexturePath + FileSystem->getFileBasename(simplifiedTexName)) )
			return VideoDriver->getTexture(TextureName);
	}

	// just the name itself
	if ( checkTextureName(simplifiedTexName) )
		return VideoDriver->getTexture(TextureName);

	// look in files relative to the folder of the meshfile
	if ( MeshFile )
	{
		if ( MeshPath.empty() )
		{
			MeshPath = FileSystem->getFileDir(MeshFile->getFileName());
			preparePath(MeshPath);
		}
		if ( !MeshPath.empty() )
		{
			if ( checkTextureName(MeshPath + simplifiedTexName) )
				return VideoDriver->getTexture(TextureName);

			if ( checkTextureName(MeshPath + FileSystem->getFileBasename(simplifiedTexName)) )
				return VideoDriver->getTexture(TextureName);
		}
	}

	// look in files relative to the folder of the materialfile
	if ( MaterialFile )
	{
		if ( MaterialPath.empty() )
		{
			MaterialPath = FileSystem->getFileDir(MaterialFile->getFileName());
			preparePath(MaterialPath);
		}
		if ( !MaterialPath.empty() )
		{
			if ( checkTextureName(MaterialPath + simplifiedTexName) )
				return VideoDriver->getTexture(TextureName);

			if ( checkTextureName(MaterialPath + FileSystem->getFileBasename(simplifiedTexName)) )
				return VideoDriver->getTexture(TextureName);
		}
	}

	// check current working directory
	if ( checkTextureName(FileSystem->getFileBasename(simplifiedTexName)) )
		return VideoDriver->getTexture(TextureName);

	TextureName = NIRT_TEXT("");
	return NULL;
}

//! Meshloaders will search paths relative to the meshFile.
void CMeshTextureLoader::setMeshFile(const nirt::io::IReadFile* meshFile)
{
	// no grab (would need a weak_ptr)
	MeshFile = meshFile;
	MeshPath = NIRT_TEXT("");	// do a lazy evaluation later
}

//! Meshloaders will try to look relative to the path of the materialFile
void CMeshTextureLoader::setMaterialFile(const nirt::io::IReadFile* materialFile)
{
	// no grab (would need a weak_ptr)
	MaterialFile = materialFile;
	MaterialPath = NIRT_TEXT("");	// do a lazy evaluation later
}

} // end namespace scnene
} // end namespace nirt
