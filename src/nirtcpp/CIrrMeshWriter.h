// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_NIRT_MESH_WRITER_H_INCLUDED
#define NIRT_NIRT_MESH_WRITER_H_INCLUDED

#include "IMeshWriter.h"
#include "S3DVertex.h"
#include "IVideoDriver.h"
#include "IFileSystem.h"
#include "IXMLWriter.h"

namespace nirt
{

namespace scene
{
	class IMeshBuffer;


	//! class to write meshes, implementing a IrrMesh (.irrmesh, .xml) writer
	/** This writer implementation has been originally developed for irrEdit and then
	merged out to the Nirtcpp Engine */
	class CIrrMeshWriter : public IMeshWriter
	{
	public:

		CIrrMeshWriter(video::IVideoDriver* driver, io::IFileSystem* fs);
		virtual ~CIrrMeshWriter();

		//! Returns the type of the mesh writer
		virtual EMESH_WRITER_TYPE getType() const override;

		//! writes a mesh
		virtual bool writeMesh(io::IWriteFile* file, scene::IMesh* mesh, s32 flags=EMWF_NONE) override;

	protected:

		void writeBoundingBox(const core::aabbox3df& box);

		void writeMeshBuffer(const scene::IMeshBuffer* buffer);

		void writeMaterial(const video::SMaterial& material);

		core::stringw getVectorAsStringLine(const core::vector3df& v) const;

		core::stringw getVectorAsStringLine(const core::vector2df& v) const;

		// member variables:

		io::IFileSystem* FileSystem;
		video::IVideoDriver* VideoDriver;
		io::IXMLWriter* Writer;
	};

} // end namespace
} // end namespace

#endif
