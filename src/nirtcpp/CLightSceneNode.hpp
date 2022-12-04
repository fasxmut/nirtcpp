// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_LIGHT_SCENE_NODE_H_INCLUDED
#define NIRT_C_LIGHT_SCENE_NODE_H_INCLUDED

#include <nirtcpp/ILightSceneNode.hpp>

namespace nirt
{
namespace scene
{

//! Scene node which is a dynamic light. You can switch the light on and off by
//! making it visible or not, and let it be animated by ordinary scene node animators.
class CLightSceneNode : public ILightSceneNode
{
public:

	//! constructor
	CLightSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id,
		const core::vector3df& position, video::SColorf color, f32 range);

	//! pre render event
	virtual void OnRegisterSceneNode() override;

	//! render
	virtual void render() override;

	//! set node light data from light info
	virtual void setLightData(const video::SLight& light) override;

	//! \return Returns the light data.
	virtual const video::SLight& getLightData() const override;

	//! \return Returns the light data.
	virtual video::SLight& getLightData() override;

	//! Sets if the node should be visible or not.
	/** All children of this node won't be visible either, when set
	to true.
	\param isVisible If the node shall be visible. */
	virtual void setVisible(bool isVisible) override;

	//! returns the axis aligned bounding box of this node
	virtual const core::aabbox3d<f32>& getBoundingBox() const override;

	//! Returns type of the scene node
	virtual ESCENE_NODE_TYPE getType() const override { return ESNT_LIGHT; }

	//! Writes attributes of the scene node.
	virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) const override;

	//! Reads attributes of the scene node.
	virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0) override;

	//! Creates a clone of this scene node and its children.
	virtual ISceneNode* clone(ISceneNode* newParent=0, ISceneManager* newManager=0) override;

	//! Sets the light's radius of influence.
	/** Outside this radius the light won't lighten geometry and cast no
	shadows. Setting the radius will also influence the attenuation, setting
	it to (0,1/radius,0). If you want to override this behavior, set the
	attenuation after the radius.
	\param radius The new radius. */
	virtual void setRadius(f32 radius) override;

	//! Gets the light's radius of influence.
	/** \return The current radius. */
	virtual f32 getRadius() const override;

	//! Sets the light type.
	/** \param type The new type. */
	virtual void setLightType(video::E_LIGHT_TYPE type) override;

	//! Gets the light type.
	/** \return The current light type. */
	virtual video::E_LIGHT_TYPE getLightType() const override;

	//! Sets whether this light casts shadows.
	/** Enabling this flag won't automatically cast shadows, the meshes
	will still need shadow scene nodes attached. But one can enable or
	disable distinct lights for shadow casting for performance reasons.
	\param shadow True if this light shall cast shadows. */
	virtual void enableCastShadow(bool shadow=true) override;

	//! Check whether this light casts shadows.
	/** \return True if light would cast shadows, else false. */
	virtual bool getCastShadow() const override;

	//! Updates the absolute position based on the relative and the parents position
	virtual void updateAbsolutePosition() override;

private:

	video::SLight LightData;
	core::aabbox3d<f32> BBox;
	s32 DriverLightIndex;
	bool LightIsOn;
	void doLightRecalc();
};


} // end namespace scene
} // end namespace nirt

#endif
