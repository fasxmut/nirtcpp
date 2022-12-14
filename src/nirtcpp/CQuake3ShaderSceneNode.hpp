// Copyright (C) 2002-2012 Nikolaus Gebhardt / Thomas Alten
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_QUAKE3_SCENE_NODE_H_INCLUDED
#define NIRT_C_QUAKE3_SCENE_NODE_H_INCLUDED

#include <nirtcpp/IMeshSceneNode.hpp>
#include <nirtcpp/IQ3Shader.hpp>
#include <nirtcpp/IFileSystem.hpp>
#include <nirtcpp/SMeshBuffer.hpp>
#include <nirtcpp/SMeshBufferLightMap.hpp>
#include <nirtcpp/SMesh.hpp>
#include <nirtcpp/ISceneManager.hpp>

namespace nirt
{
namespace scene
{

//! Scene node which is a quake3 shader.
class CQuake3ShaderSceneNode : public scene::IMeshSceneNode
{
public:

	CQuake3ShaderSceneNode( ISceneNode* parent, ISceneManager* mgr, s32 id,
				io::IFileSystem* fileSystem,
				const IMeshBuffer* original,
				const quake3::IShader* shader
			);

	virtual ~CQuake3ShaderSceneNode();

	virtual void OnRegisterSceneNode() override;
	virtual void render() override;
	virtual void OnAnimate(u32 timeMs) override;
	virtual const core::aabbox3d<f32>& getBoundingBox() const override;

	virtual u32 getMaterialCount() const override;
	virtual video::SMaterial& getMaterial(u32 i) override;

	//! Returns type of the scene node
	virtual ESCENE_NODE_TYPE getType() const override { return ESNT_Q3SHADER_SCENE_NODE; }

	virtual void setMesh(IMesh* mesh)override {}
	virtual IMesh* getMesh() override { return Mesh; }
	virtual void setReadOnlyMaterials(bool readonly) override {}
	virtual bool isReadOnlyMaterials() const override { return true; }

	//! Creates shadow volume scene node as child of this node
	//! and returns a pointer to it.
	virtual IShadowVolumeSceneNode* addShadowVolumeSceneNode(const IMesh* shadowMesh,
		s32 id, bool zfailmethod=true, f32 infinity=10000.0f) override;

	//! Removes a child from this scene node.
	//! Implemented here, to be able to remove the shadow properly, if there is one,
	//! or to remove attached childs.
	virtual bool removeChild(ISceneNode* child) override;

private:
	const quake3::IShader* Shader;
	SMesh *Mesh;
	IShadowVolumeSceneNode* Shadow;
	const SMeshBufferLightMap* Original;
	SMeshBuffer* MeshBuffer;
	core::vector3df MeshOffset;

	struct SQ3Texture
	{
		SQ3Texture () :
			TextureIndex ( 0 ),
			TextureFrequency(0.f),
			TextureAddressMode( video::ETC_REPEAT )
			{
				Texture.setAllocStrategy ( core::ALLOC_STRATEGY_SAFE );
			}

		quake3::tTexArray Texture;

		u32 TextureIndex;
		f32 TextureFrequency;
		video::E_TEXTURE_CLAMP TextureAddressMode;	// Wrapping/Clamping
	};

	core::array< SQ3Texture > Q3Texture;

	void loadTextures ( io::IFileSystem * fileSystem );
	void addBuffer ( scene::SMeshBufferLightMap * buffer );
	void cloneBuffer ( scene::SMeshBuffer *dest, const scene::SMeshBufferLightMap * buffer, bool translateCenter );

	void deformvertexes_wave ( f32 dt, quake3::SModifierFunction &function );
	void deformvertexes_move ( f32 dt, quake3::SModifierFunction &function );
	void deformvertexes_bulge( f32 dt, quake3::SModifierFunction &function );
	void deformvertexes_autosprite( f32 dt, quake3::SModifierFunction &function );
	void deformvertexes_autosprite2( f32 dt, quake3::SModifierFunction &function );
	void deformvertexes_normal ( f32 dt, quake3::SModifierFunction &function );

	void vertextransform_tcgen ( f32 dt, quake3::SModifierFunction &function );
	void vertextransform_rgbgen ( f32 dt, quake3::SModifierFunction &function );
	void vertextransform_alphagen ( f32 dt, quake3::SModifierFunction &function );

	void transformtex ( const core::matrix4 &m, const u32 clamp );

	f32 TimeAbs;

	void animate( u32 stage, core::matrix4 &texture );

	E_SCENE_NODE_RENDER_PASS getRenderStage() const;

};


} // end namespace scene
} // end namespace nirt

#endif
