// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_GUI_MESH_VIEWER_H_INCLUDED
#define NIRT_C_GUI_MESH_VIEWER_H_INCLUDED

#include "IrrCompileConfig.h"
#ifdef _NIRT_COMPILE_WITH_GUI_

#include "IGUIMeshViewer.h"
#include "SMaterial.h"

namespace nirt
{

namespace gui
{

	class CGUIMeshViewer : public IGUIMeshViewer
	{
	public:

		//! constructor
		CGUIMeshViewer(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle);

		//! destructor
		virtual ~CGUIMeshViewer();

		//! sets the mesh to be shown
		virtual void setMesh(scene::IAnimatedMesh* mesh) override;

		//! Gets the displayed mesh
		virtual scene::IAnimatedMesh* getMesh() const override;

		//! sets the material
		virtual void setMaterial(const video::SMaterial& material) override;

		//! gets the material
		virtual const video::SMaterial& getMaterial() const override;

		//! called if an event happened.
		virtual bool OnEvent(const SEvent& event) override;

		//! draws the element and its children
		virtual void draw() override;

	private:

		video::SMaterial Material;
		scene::IAnimatedMesh* Mesh;
	};


} // end namespace gui
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_GUI_

#endif // NIRT_C_GUI_MESH_VIEWER_H_INCLUDED
