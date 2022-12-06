// Copyright (C) 2010-2012 Gaz Davidson
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_SMF_MESH_LOADER_H_INCLUDED
#define NIRT_C_SMF_MESH_LOADER_H_INCLUDED

#include <nirtcpp/IMeshLoader.hpp>
#include <nirtcpp/SMesh.hpp>

namespace nirt
{

namespace video
{
	class IVideoDriver;
}
namespace io
{
	class IFileSystem;
}

namespace scene
{

//! Class which can load
class CSMFMeshFileLoader : public virtual IMeshLoader
{
public:

	CSMFMeshFileLoader(nirt::io::IFileSystem* fs, video::IVideoDriver* driver);

	//! Returns true if the file might be loaded by this class.
	virtual bool isALoadableFileExtension(const io::path& filename) const override;

	//! Creates/loads an animated mesh from the file.
	virtual IAnimatedMesh* createMesh(io::IReadFile* file) override;
private:

	void loadLimb(io::IReadFile* file, scene::SMesh* mesh, const core::matrix4 &parentTransformation);
};

} // end namespace scene

namespace io
{
	class BinaryFile
	{
	public:
		//! reads most types from the given file, moving the file pointer along
		template <class T>
		static void read(io::IReadFile* file, T &out, bool bigEndian=false);

		//! reads a 3d vector from the file, moving the file pointer along
		static void read(io::IReadFile* file, core::vector3df &outVector2d, bool bigEndian=false);

		//! reads a 2d vector from the file, moving the file pointer along
		static void read(io::IReadFile* file, core::vector2df &outVector2d, bool bigEndian=false);

		//! reads a null terminated string from the file, moving the file pointer along
		static void read(io::IReadFile* file, core::stringc &outString, bool bigEndian=false);

	};
}

} // end namespace nirt

#endif // NIRT_C_SMF_MESH_LOADER_H_INCLUDED
