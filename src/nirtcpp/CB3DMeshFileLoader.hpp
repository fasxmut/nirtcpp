// Copyright (C) 2006-2012 Luke Hos.hppke
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

// B3D Mesh loader
// File format designed by Mark Sibly for the Blitz3D engine and has been
// declared public domain

#include <nirtcpp/IrrCompileConfig.hpp>

#ifndef NIRT_C_B3D_MESH_LOADER_H_INCLUDED
#define NIRT_C_B3D_MESH_LOADER_H_INCLUDED

#include <nirtcpp/IMeshLoader.hpp>
#include <nirtcpp/ISceneManager.hpp>
#include "CSkinnedMesh.hpp"
#include "SB3DStructs.hpp"
#include <nirtcpp/IReadFile.hpp>

namespace nirt
{

namespace scene
{

//! Meshloader for B3D format
class CB3DMeshFileLoader : public IMeshLoader
{
public:

	//! Constructor
	CB3DMeshFileLoader(scene::ISceneManager* smgr);

	//! returns true if the file maybe is able to be loaded by this class
	//! based on the file extension (e.g. ".bsp")
	virtual bool isALoadableFileExtension(const io::path& filename) const override;

	//! creates/loads an animated mesh from the file.
	//! \return Pointer to the created mesh. Returns 0 if loading failed.
	//! If you no longer need the mesh, you should call IAnimatedMesh::drop().
	//! See IReferenceCounted::drop() for more information.
	virtual IAnimatedMesh* createMesh(io::IReadFile* file) override;

private:

	bool load();
	bool readChunkNODE(CSkinnedMesh::SJoint* InJoint);
	bool readChunkMESH(CSkinnedMesh::SJoint* InJoint);
	bool readChunkVRTS(CSkinnedMesh::SJoint* InJoint);
	bool readChunkTRIS(scene::SSkinMeshBuffer *MeshBuffer, u32 MeshBufferID, s32 Vertices_Start);
	bool readChunkBONE(CSkinnedMesh::SJoint* InJoint);
	bool readChunkKEYS(CSkinnedMesh::SJoint* InJoint);
	bool readChunkANIM();
	bool readChunkTEXS();
	bool readChunkBRUS();

	void loadTextures(SB3dMaterial& material) const;

	void readString(core::stringc& newstring);
	void readFloats(f32* vec, u32 count);

	core::array<SB3dChunk> B3dStack;

	core::array<SB3dMaterial> Materials;
	core::array<SB3dTexture> Textures;

	core::array<s32> AnimatedVertices_VertexID;

	core::array<s32> AnimatedVertices_BufferID;

	core::array<video::S3DVertex2TCoords> BaseVertices;

	ISceneManager*	SceneManager;
	CSkinnedMesh*	AnimatedMesh;
	io::IReadFile*	B3DFile;

	//B3Ds have Vertex ID's local within the mesh I don't want this
	// Variable needs to be class member due to recursion in calls
	u32 VerticesStart;

	bool NormalsInFile;
	bool HasVertexColors;
	bool ShowWarning;
};


} // end namespace scene
} // end namespace nirt

#endif // NIRT_C_B3D_MESH_LOADER_H_INCLUDED
