// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_COLLADA_MESH_WRITER_H_INCLUDED
#define NIRT_C_COLLADA_MESH_WRITER_H_INCLUDED

#include <nirtcpp/IColladaMeshWriter.hpp>
#include <nirtcpp/S3DVertex.hpp>
#include <nirtcpp/irrMap.hpp>
#include <nirtcpp/IVideoDriver.hpp>
#include <nirtcpp/IXMLWriter.hpp>

namespace nirt
{
namespace io
{
	class IFileSystem;
}

namespace scene
{
	//! Callback interface for properties which can be used to influence collada writing
	// (Implementer note: keep namespace labels here to make it easier for users copying this one)
	class CColladaMeshWriterProperties  : public virtual IColladaMeshWriterProperties
	{
	public:
		//! Which lighting model should be used in the technique (FX) section when exporting effects (materials)
		virtual nirt::scene::E_COLLADA_TECHNIQUE_FX getTechniqueFx(const nirt::video::SMaterial& material) const override;

		//! Which texture index should be used when writing the texture of the given sampler color.
		virtual nirt::s32 getTextureIdx(const nirt::video::SMaterial & material, nirt::scene::E_COLLADA_COLOR_SAMPLER cs) const override;

		//! Return which color from Nirtcpp should be used for the color requested by collada
		virtual nirt::scene::E_COLLADA_NIRT_COLOR getColorMapping(const nirt::video::SMaterial & material, nirt::scene::E_COLLADA_COLOR_SAMPLER cs) const override;

		//! Return custom colors for certain color types requested by collada.
		virtual nirt::video::SColor getCustomColor(const nirt::video::SMaterial & material, nirt::scene::E_COLLADA_COLOR_SAMPLER cs) const override;

		//! Return the settings for transparence
		virtual nirt::scene::E_COLLADA_TRANSPARENT_FX getTransparentFx(const nirt::video::SMaterial& material) const override;

		//! Transparency value for that material.
		virtual nirt::f32 getTransparency(const nirt::video::SMaterial& material) const override;

		//! Reflectivity value for that material
		virtual nirt::f32 getReflectivity(const nirt::video::SMaterial& material) const override;

		//! Return index of refraction for that material
		virtual nirt::f32 getIndexOfRefraction(const nirt::video::SMaterial& material) const override;

		//! Should node be used in scene export? By default all visible nodes are exported.
		virtual bool isExportable(const nirt::scene::ISceneNode * node) const override;

		//! Return the mesh for the given nod. If it has no mesh or shouldn't export it's mesh return 0.
		virtual nirt::scene::IMesh* getMesh(nirt::scene::ISceneNode * node) override;

		//! Return if the node has it's own material overwriting the mesh-materials
		virtual bool useNodeMaterial(const scene::ISceneNode* node) const override;
	};

	class CColladaMeshWriterNames  : public virtual IColladaMeshWriterNames
	{
	public:
		CColladaMeshWriterNames(IColladaMeshWriter * writer);
		virtual nirt::core::stringc nameForMesh(const scene::IMesh* mesh, int instance) override;
		virtual nirt::core::stringc nameForNode(const scene::ISceneNode* node) override;
		virtual nirt::core::stringc nameForMaterial(const video::SMaterial & material, int materialId, const scene::IMesh* mesh, const scene::ISceneNode* node) override;
	protected:
		nirt::core::stringc nameForPtr(const void* ptr) const;
	private:
		IColladaMeshWriter * ColladaMeshWriter;
	};



//! class to write meshes, implementing a COLLADA (.dae, .xml) writer
/** This writer implementation has been originally developed for irrEdit and then
merged out to the Nirtcpp Engine */
class CColladaMeshWriter : public IColladaMeshWriter
{
public:

	CColladaMeshWriter(ISceneManager * smgr, video::IVideoDriver* driver, io::IFileSystem* fs);
	virtual ~CColladaMeshWriter();

	//! Returns the type of the mesh writer
	virtual EMESH_WRITER_TYPE getType() const override;

	//! writes a scene starting with the given node
	virtual bool writeScene(io::IWriteFile* file, scene::ISceneNode* root, int writeRoot) override;

	//! writes a mesh
	virtual bool writeMesh(io::IWriteFile* file, scene::IMesh* mesh, s32 flags=EMWF_NONE) override;

	// Restrict the characters of oldString a set of allowed characters in xs:NCName and add the prefix.
	virtual nirt::core::stringc toNCName(const nirt::core::stringc& oldString, const nirt::core::stringc& prefix=nirt::core::stringc("_NC_")) const override;

	//! After export you can find out which name had been used for writing the geometry for this node.
	virtual const nirt::core::stringc* findGeometryNameForNode(ISceneNode* node) override;

protected:

	void reset();
	bool hasSecondTextureCoordinates(video::E_VERTEX_TYPE type) const;
	void writeUv(const nirt::core::vector2df& vec);
	void writeVector(const nirt::core::vector3df& vec);
	void writeColor(const nirt::video::SColorf& colorf, bool writeAlpha=true);
	inline nirt::core::stringc toString(const nirt::video::ECOLOR_FORMAT format) const;
	inline nirt::core::stringc toString(const nirt::video::E_TEXTURE_CLAMP clamp) const;
	inline nirt::core::stringc toString(const nirt::scene::E_COLLADA_TRANSPARENT_FX opaque) const;
	inline nirt::core::stringc toRef(const nirt::core::stringc& source) const;
	bool isCamera(const scene::ISceneNode* node) const;
	nirt::core::stringc nameForMesh(const scene::IMesh* mesh, int instance) const;
	nirt::core::stringc nameForNode(const scene::ISceneNode* node) const;
	nirt::core::stringc nameForMaterial(const video::SMaterial & material, int materialId, const scene::IMesh* mesh, const scene::ISceneNode* node);
	nirt::core::stringc nameForMaterialSymbol(const scene::IMesh* mesh, int materialId) const;
	nirt::core::stringc findCachedMaterialName(const nirt::video::SMaterial& material) const;
	nirt::core::stringc minTexfilterToString(bool bilinear, bool trilinear) const;
	nirt::core::stringc magTexfilterToString(bool bilinear, bool trilinear) const;
	nirt::core::stringc pathToURI(const nirt::io::path& path) const;
	inline bool isXmlNameStartChar(c8 c) const;
	inline bool isXmlNameChar(c8 c) const;
	s32 getCheckedTextureIdx(const video::SMaterial & material, E_COLLADA_COLOR_SAMPLER cs);
	video::SColor getColorMapping(const video::SMaterial & material, E_COLLADA_COLOR_SAMPLER cs, E_COLLADA_NIRT_COLOR colType);
	void writeAsset();
	void makeMeshNames(nirt::scene::ISceneNode * node);
	void writeNodeMaterials(nirt::scene::ISceneNode * node);
	void writeNodeEffects(nirt::scene::ISceneNode * node);
	void writeNodeLights(nirt::scene::ISceneNode * node);
	void writeNodeCameras(nirt::scene::ISceneNode * node);
	void writeAllMeshGeometries();
	void writeSceneNode(nirt::scene::ISceneNode * node);
	void writeMeshMaterials(scene::IMesh* mesh, nirt::core::array<nirt::core::stringc> * materialNamesOut=0);
	void writeMeshEffects(scene::IMesh* mesh);
	void writeMaterialEffect(const nirt::core::stringc& materialname, const video::SMaterial & material);
	void writeMeshGeometry(const nirt::core::stringc& meshname, scene::IMesh* mesh);
	void writeMeshInstanceGeometry(const nirt::core::stringc& meshname, scene::IMesh* mesh, scene::ISceneNode* node=0);
	void writeMaterial(const nirt::core::stringc& materialname);
	void writeLightInstance(const nirt::core::stringc& lightName);
	void writeCameraInstance(const nirt::core::stringc& cameraName);
	void writeLibraryImages();
	void writeColorFx(const video::SMaterial & material, const c8 * colorname, E_COLLADA_COLOR_SAMPLER cs, const c8* attr1Name=0, const c8* attr1Value=0);
	void writeAmbientLightElement(const video::SColorf & col);
	void writeColorElement(const video::SColor & col, bool writeAlpha=true);
	void writeColorElement(const video::SColorf & col, bool writeAlpha=true);
	void writeTextureSampler(s32 textureIdx);
	void writeFxElement(const video::SMaterial & material, E_COLLADA_TECHNIQUE_FX techFx);
	void writeNode(const c8 * nodeName, const c8 * content);
	void writeFloatElement(nirt::f32 value);
	void writeRotateElement(const nirt::core::vector3df& axis, nirt::f32 angle);
	void writeScaleElement(const nirt::core::vector3df& scale);
	void writeTranslateElement(const nirt::core::vector3df& translate);
	void writeLookAtElement(const nirt::core::vector3df& eyePos, const nirt::core::vector3df& targetPos, const nirt::core::vector3df& upVector);
	void writeMatrixElement(const nirt::core::matrix4& matrix);

	struct SComponentGlobalStartPos
	{
		SComponentGlobalStartPos() : PosStartIndex(0),
				NormalStartIndex(0),
				TCoord0StartIndex(0),
				TCoord1StartIndex(0)
		{ }

		u32 PosStartIndex;
		u32 NormalStartIndex;
		u32 TCoord0StartIndex;
		u32 TCoord1StartIndex;
	};

	io::IFileSystem* FileSystem;
	video::IVideoDriver* VideoDriver;
	io::IXMLWriterUTF8* Writer;
	core::array<video::ITexture*> LibraryImages;
	io::path Directory;

	// Helper struct for creating geometry copies for the ECGI_PER_MESH_AND_MATERIAL settings.
	struct SGeometryMeshMaterials
	{
		bool equals(const core::array<nirt::core::stringc>& names) const
		{
			if ( names.size() != MaterialNames.size() )
				return false;
			for ( nirt::u32 i=0; i<MaterialNames.size(); ++i )
				if ( names[i] != MaterialNames[i] )
					return false;
			return true;
		}

		nirt::core::stringc GeometryName;				// replacing the usual ColladaMesh::Name
		core::array<nirt::core::stringc> MaterialNames;	// Material names exported for this instance
		core::array<const ISceneNode*> MaterialOwners;	// Nodes using this specific mesh-material combination
	};

	// Check per mesh-ptr if stuff has been written for this mesh already
	struct SColladaMesh
	{
		SColladaMesh() : MaterialsWritten(false), EffectsWritten(false)
		{
		}

		SGeometryMeshMaterials * findGeometryMeshMaterials(const nirt::core::array<nirt::core::stringc> materialNames)
		{
			for ( nirt::u32 i=0; i<GeometryMeshMaterials.size(); ++i )
			{
				if ( GeometryMeshMaterials[i].equals(materialNames) )
					return &(GeometryMeshMaterials[i]);
			}
			return NULL;
		}

		const nirt::core::stringc& findGeometryNameForNode(const ISceneNode* node) const
		{
			if ( GeometryMeshMaterials.size() < 2 )
				return Name;
			for ( nirt::u32 i=0; i<GeometryMeshMaterials.size(); ++i )
			{
				if ( GeometryMeshMaterials[i].MaterialOwners.linear_search(node)  >= 0 )
					return GeometryMeshMaterials[i].GeometryName;
			}
			return Name; // (shouldn't get here usually)
		}

		nirt::core::stringc Name;
		bool MaterialsWritten;	// just an optimization doing that here in addition to the MaterialsWritten map
		bool EffectsWritten;	// just an optimization doing that here in addition to the EffectsWritten map

		core::array<SGeometryMeshMaterials> GeometryMeshMaterials;
	};
	typedef core::map<IMesh*, SColladaMesh>::Node MeshNode;
	core::map<IMesh*, SColladaMesh> Meshes;

	// structure for the lights library
	struct SColladaLight
	{
		SColladaLight()	{}
		nirt::core::stringc Name;
	};
	typedef core::map<ISceneNode*, SColladaLight>::Node LightNode;
	core::map<ISceneNode*, SColladaLight> LightNodes;

	// structure for the camera library
	typedef core::map<ISceneNode*, nirt::core::stringc>::Node CameraNode;
	core::map<ISceneNode*, nirt::core::stringc> CameraNodes;

	// Check per name if stuff has been written already
	// TODO: second parameter not needed, we just don't have a core::set class yet in Nirtcpp
	core::map<nirt::core::stringc, bool> MaterialsWritten;
	core::map<nirt::core::stringc, bool> EffectsWritten;

	// Cache material names
	struct MaterialName
	{
		MaterialName(const nirt::video::SMaterial & material, const nirt::core::stringc& name)
			: Material(material), Name(name)
		{}
		nirt::video::SMaterial Material;
		nirt::core::stringc Name;
	};
	nirt::core::array< MaterialName > MaterialNameCache;

	nirt::core::stringc WriteBuffer;	// use for writing short strings to avoid regular memory allocations

	struct EscapeCharacterURL
	{
		EscapeCharacterURL(nirt::c8 c, const nirt::c8* e)
			: Character(c)
		{
			Escape = e;
		}

		nirt::c8 Character;		// unescaped (like ' ')
		nirt::core::stringc Escape;	// escaped (like '%20')
	};
	nirt::core::array<EscapeCharacterURL> EscapeCharsAnyURI;
};


} // end namespace
} // end namespace

#endif
