// Copyright (C) 2007-2012 Christian Stehno
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_STL_MESH_FILE_LOADER_H_INCLUDED
#define NIRT_C_STL_MESH_FILE_LOADER_H_INCLUDED

#include <nirtcpp/IMeshLoader.hpp>
#include <nirtcpp/irrString.hpp>
#include <nirtcpp/vector3d.hpp>

namespace nirt
{
namespace scene
{

//! Meshloader capable of loading STL meshes.
class CSTLMeshFileLoader : public IMeshLoader
{
public:

	//! returns true if the file maybe is able to be loaded by this class
	//! based on the file extension (i.e. ".stl")
	virtual bool isALoadableFileExtension(const io::path& filename) const override;

	//! creates/loads an animated mesh from the file.
	//! \return Pointer to the created mesh. Returns 0 if loading failed.
	//! If you no longer need the mesh, you should call IAnimatedMesh::drop().
	//! See IReferenceCounted::drop() for more information.
	virtual IAnimatedMesh* createMesh(io::IReadFile* file) override;

private:

	// skips to the first non-space character available
	void goNextWord(io::IReadFile* file) const;
	// returns the next word
	const core::stringc& getNextToken(io::IReadFile* file);
	// skip to next printable character after the first line break
	void goNextLine(io::IReadFile* file) const;

	//! Read 3d vector of floats
	void getNextVector(io::IReadFile* file, core::vector3df& vec, bool binary);

	//! Buffering last read token to avoid reallocating string all the time
	core::stringc Token;
};

} // end namespace scene
} // end namespace nirt

#endif
