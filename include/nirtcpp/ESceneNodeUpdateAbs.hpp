// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_E_SCENE_NODE_UPDATE_ABS_H_INCLUDED
#define NIRT_E_SCENE_NODE_UPDATE_ABS_H_INCLUDED

namespace nirt
{
namespace scene
{
	//! Options how ISceneNode::updateAbsolutePosition calculates the AbsoluteTransformation
	enum ESCENE_NODE_UPDATE_ABS
	{
		//! Node and parent transformation matrices are multiplied (default)
		ESNUA_TRANSFORM_MATRIX,

		//! Only transform the position of the node transformation matrix 
		//! by the parent transformation matrix.
		//! Parent will not affect the rotation/scale of the node transformation.
		ESNUA_TRANSFORM_POSITION
	};

	//! Names for culling type
	const c8* const SceneNodeUpdateAbsNames[] =
	{
		"matrix",
		"pos",
		0
	};

} // end namespace scene
} // end namespace nirt

#endif
