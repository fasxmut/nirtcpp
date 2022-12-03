// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_MD2_MESH_FILE_LOADER_H_INCLUDED
#define NIRT_C_MD2_MESH_FILE_LOADER_H_INCLUDED

#include "IMeshLoader.h"

namespace nirt
{
namespace scene
{

class CAnimatedMeshMD2;

//! Meshloader capable of loading MD2 files
class CMD2MeshFileLoader : public IMeshLoader
{
public:

	//! Constructor
	CMD2MeshFileLoader();

	//! returns true if the file maybe is able to be loaded by this class
	//! based on the file extension (e.g. ".bsp")
	virtual bool isALoadableFileExtension(const io::path& filename) const override;

	//! creates/loads an animated mesh from the file.
	//! \return Pointer to the created mesh. Returns 0 if loading failed.
	//! If you no longer need the mesh, you should call IAnimatedMesh::drop().
	//! See IReferenceCounted::drop() for more information.
	virtual IAnimatedMesh* createMesh(io::IReadFile* file) override;

private:
	//! Loads the file data into the mesh
	bool loadFile(io::IReadFile* file, CAnimatedMeshMD2* mesh);

};

} // end namespace scene
} // end namespace nirt

#endif // NIRT_C_MD2_MESH_LOADER_H_INCLUDED
