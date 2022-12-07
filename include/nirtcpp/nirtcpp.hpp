/* irrlicht.h -- interface of the 'Irrlicht Engine'

  Copyright (C) 2002-2012 Nikolaus Gebhardt

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Please note that the Irrlicht Engine is based in part on the work of the
  Independent JPEG Group, the zlib and the libPng. This means that if you use
  the Irrlicht Engine in your product, you must acknowledge somewhere in your
  documentation that you've used the IJG code. It would also be nice to mention
  that you use the Irrlicht Engine, the zlib and libPng. See the README files
  in the jpeglib, the zlib and libPng for further information.
*/
/*
Please note that this nirtcpp/nirtcpp.hpp is renamed from irrlicht.h.
*/

#ifndef NIRTCPP_H_INCLUDED
#define NIRTCPP_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>
#include <nirtcpp/aabbox3d.hpp>
#include <nirtcpp/CDynamicMeshBuffer.hpp>
#include <nirtcpp/CIndexBuffer.hpp>
#include <nirtcpp/CMeshBuffer.hpp>
#include <nirtcpp/coreutil.hpp>
#include <nirtcpp/CVertexBuffer.hpp>
#include <nirtcpp/IProfiler.hpp>
#include <nirtcpp/dimension2d.hpp>
#include <nirtcpp/ECullingTypes.hpp>
#include <nirtcpp/EDebugSceneTypes.hpp>
#include <nirtcpp/EDriverFeatures.hpp>
#include <nirtcpp/EDriverTypes.hpp>
#include <nirtcpp/EGUIAlignment.hpp>
#include <nirtcpp/EGUIElementTypes.hpp>
#include <nirtcpp/EHardwareBufferFlags.hpp>
#include <nirtcpp/EMaterialFlags.hpp>
#include <nirtcpp/EMaterialTypes.hpp>
#include <nirtcpp/EMeshWriterEnums.hpp>
#include <nirtcpp/EMessageBoxFlags.hpp>
#include <nirtcpp/ESceneNodeAnimatorTypes.hpp>
#include <nirtcpp/ESceneNodeTypes.hpp>
#include <nirtcpp/ETerrainElements.hpp>
#include <nirtcpp/fast_atof.hpp>
#include <nirtcpp/heapsort.hpp>
#include <nirtcpp/IAnimatedMesh.hpp>
#include <nirtcpp/IAnimatedMeshMD2.hpp>
#include <nirtcpp/IAnimatedMeshMD3.hpp>
#include <nirtcpp/IAnimatedMeshSceneNode.hpp>
#include <nirtcpp/IAttributeExchangingObject.hpp>
#include <nirtcpp/IAttributes.hpp>
#include <nirtcpp/IBillboardSceneNode.hpp>
#include <nirtcpp/IBillboardTextSceneNode.hpp>
#include <nirtcpp/IBoneSceneNode.hpp>
#include <nirtcpp/ICameraSceneNode.hpp>
#include <nirtcpp/IContextManager.hpp>
#include <nirtcpp/ICursorControl.hpp>
#include <nirtcpp/IDummyTransformationSceneNode.hpp>
#include <nirtcpp/IDynamicMeshBuffer.hpp>
#include <nirtcpp/IEventReceiver.hpp>
#include <nirtcpp/IFileList.hpp>
#include <nirtcpp/IFileSystem.hpp>
#include <nirtcpp/IGeometryCreator.hpp>
#include <nirtcpp/IGPUProgrammingServices.hpp>
#include <nirtcpp/IGUIButton.hpp>
#include <nirtcpp/IGUICheckBox.hpp>
#include <nirtcpp/IGUIColorSelectDialog.hpp>
#include <nirtcpp/IGUIComboBox.hpp>
#include <nirtcpp/IGUIContextMenu.hpp>
#include <nirtcpp/IGUIEditBox.hpp>
#include <nirtcpp/IGUIElement.hpp>
#include <nirtcpp/IGUIElementFactory.hpp>
#include <nirtcpp/IGUIEnvironment.hpp>
#include <nirtcpp/IGUIFileOpenDialog.hpp>
#include <nirtcpp/IGUIFont.hpp>
#include <nirtcpp/IGUIFontBitmap.hpp>
#include <nirtcpp/IGUIImage.hpp>
#include <nirtcpp/IGUIInOutFader.hpp>
#include <nirtcpp/IGUIListBox.hpp>
#include <nirtcpp/IGUIMeshViewer.hpp>
#include <nirtcpp/IGUIScrollBar.hpp>
#include <nirtcpp/IGUISkin.hpp>
#include <nirtcpp/IGUISpinBox.hpp>
#include <nirtcpp/IGUISpriteBank.hpp>
#include <nirtcpp/IGUIStaticText.hpp>
#include <nirtcpp/IGUITabControl.hpp>
#include <nirtcpp/IGUITable.hpp>
#include <nirtcpp/IGUIToolbar.hpp>
#include <nirtcpp/IGUIWindow.hpp>
#include <nirtcpp/IGUITreeView.hpp>
#include <nirtcpp/IGUIProfiler.hpp>
#include <nirtcpp/IImage.hpp>
#include <nirtcpp/IImageLoader.hpp>
#include <nirtcpp/IImageWriter.hpp>
#include <nirtcpp/IIndexBuffer.hpp>
#include <nirtcpp/ILightSceneNode.hpp>
#include <nirtcpp/ILogger.hpp>
#include <nirtcpp/IMaterialRenderer.hpp>
#include <nirtcpp/IMaterialRendererServices.hpp>
#include <nirtcpp/IMesh.hpp>
#include <nirtcpp/IMeshBuffer.hpp>
#include <nirtcpp/IMeshCache.hpp>
#include <nirtcpp/IMeshLoader.hpp>
#include <nirtcpp/IMeshManipulator.hpp>
#include <nirtcpp/IMeshSceneNode.hpp>
#include <nirtcpp/IMeshWriter.hpp>
#include <nirtcpp/IOctreeSceneNode.hpp>
#include <nirtcpp/IColladaMeshWriter.hpp>
#include <nirtcpp/IMetaTriangleSelector.hpp>
#include <nirtcpp/IOSOperator.hpp>
#include <nirtcpp/IParticleSystemSceneNode.hpp> // also includes all emitters and attractors
#include <nirtcpp/IQ3LevelMesh.hpp>
#include <nirtcpp/IQ3Shader.hpp>
#include <nirtcpp/IReadFile.hpp>
#include <nirtcpp/IReferenceCounted.hpp>
#include <nirtcpp/irrArray.hpp>
#include <nirtcpp/IRandomizer.hpp>
#include <nirtcpp/IRenderTarget.hpp>
#include <nirtcpp/NirtcppDevice.hpp>
#include <nirtcpp/irrList.hpp>
#include <nirtcpp/irrMap.hpp>
#include <nirtcpp/irrMath.hpp>
#include <nirtcpp/irrString.hpp>
#include <nirtcpp/irrTypes.hpp>
#include <nirtcpp/path.hpp>
#include <nirtcpp/irrXML.hpp>
#include <nirtcpp/ISceneCollisionManager.hpp>
#include <nirtcpp/ISceneLoader.hpp>
#include <nirtcpp/ISceneManager.hpp>
#include <nirtcpp/ISceneNode.hpp>
#include <nirtcpp/ISceneNodeAnimator.hpp>
#include <nirtcpp/ISceneNodeAnimatorCameraFPS.hpp>
#include <nirtcpp/ISceneNodeAnimatorCameraMaya.hpp>
#include <nirtcpp/ISceneNodeAnimatorCollisionResponse.hpp>
#include <nirtcpp/ISceneNodeAnimatorFactory.hpp>
#include <nirtcpp/ISceneNodeFactory.hpp>
#include <nirtcpp/ISceneUserDataSerializer.hpp>
#include <nirtcpp/IShaderConstantSetCallBack.hpp>
#include <nirtcpp/IShadowVolumeSceneNode.hpp>
#include <nirtcpp/ISkinnedMesh.hpp>
#include <nirtcpp/ITerrainSceneNode.hpp>
#include <nirtcpp/ITextSceneNode.hpp>
#include <nirtcpp/ITexture.hpp>
#include <nirtcpp/ITimer.hpp>
#include <nirtcpp/ITriangleSelector.hpp>
#include <nirtcpp/IVertexBuffer.hpp>
#include <nirtcpp/IVideoDriver.hpp>
#include <nirtcpp/IVideoModeList.hpp>
#include <nirtcpp/IVolumeLightSceneNode.hpp>
#include <nirtcpp/IWriteFile.hpp>
#include <nirtcpp/IXMLReader.hpp>
#include <nirtcpp/IXMLWriter.hpp>
#include <nirtcpp/ILightManager.hpp>
#include <nirtcpp/Keycodes.hpp>
#include <nirtcpp/line2d.hpp>
#include <nirtcpp/line3d.hpp>
#include <nirtcpp/matrix4.hpp>
#include <nirtcpp/plane3d.hpp>
#include <nirtcpp/position2d.hpp>
#include <nirtcpp/quaternion.hpp>
#include <nirtcpp/rect.hpp>
#include <nirtcpp/S3DVertex.hpp>
#include <nirtcpp/SAnimatedMesh.hpp>
#include <nirtcpp/SceneParameters.hpp>
#include <nirtcpp/SColor.hpp>
#include <nirtcpp/SExposedVideoData.hpp>
#include <nirtcpp/SIrrCreationParameters.hpp>
#include <nirtcpp/SKeyMap.hpp>
#include <nirtcpp/SLight.hpp>
#include <nirtcpp/SMaterial.hpp>
#include <nirtcpp/SMesh.hpp>
#include <nirtcpp/SMeshBuffer.hpp>
#include <nirtcpp/SMeshBufferLightMap.hpp>
#include <nirtcpp/SMeshBufferTangents.hpp>
#include <nirtcpp/SParticle.hpp>
#include <nirtcpp/SSharedMeshBuffer.hpp>
#include <nirtcpp/SSkinMeshBuffer.hpp>
#include <nirtcpp/SVertexIndex.hpp>
#include <nirtcpp/SViewFrustum.hpp>
#include <nirtcpp/triangle3d.hpp>
#include <nirtcpp/vector2d.hpp>
#include <nirtcpp/vector3d.hpp>

/*! \mainpage Nirtcpp Engine 1.9 API documentation
 *
 * <div align="center"><img src="logobig.png" ></div>
 *
 * \section intro Introduction
 *
 * Welcome to the Nirtcpp Engine API documentation.
 * Here you'll find any information you'll need to develop applications with
 * the Nirtcpp Engine. If you are looking for a tutorial on how to start, you'll
 * find some on the homepage of the Nirtcpp Engine at
 * <A HREF="http://nirtcpp.sourceforge.net" >nirtcpp.sourceforge.net</A>
 * or inside the SDK in the examples directory.
 *
 * The Nirtcpp Engine is intended to be an easy-to-use 3d engine, so
 * this documentation is an important part of it. If you have any questions or
 * suggestions, just send a email to the author of the engine, Nikolaus Gebhardt
 * (niko (at) nirtcpp3d.org).
 *
 *
 * \section links Links
 *
 * <A HREF="namespaces.html">Namespaces</A>: A very good place to start reading
 * the documentation.<BR>
 * <A HREF="annotated.html">Class list</A>: List of all classes with descriptions.<BR>
 * <A HREF="functions.html">Class members</A>: Good place to find forgotten features.<BR>
 *
 * \section irrexample Short example
 *
 * A simple application, starting up the engine, loading a Quake 2 animated
 * model file and the corresponding texture, animating and displaying it
 * in front of a blue background and placing a user controlable 3d camera
 * would look like the following code. I think this example shows the usage
 * of the engine quite well:
 *
 * \code
 * #include <nirtcpp/nirtcpp.hpp>
 * using namespace nirt;
 *
 * int main()
 * {
 *	// start up the engine
 *	NirtcppDevice *device = createDevice(video::EDT_OPENGL,
 *		core::dimension2d<u32>(640,480));
 *
 *	video::IVideoDriver* driver = device->getVideoDriver();
 *	scene::ISceneManager* scenemgr = device->getSceneManager();
 *
 *	device->setWindowCaption(L"Hello World!");
 *
 *	// load and show quake2 .md2 model
 *	scene::ISceneNode* node = scenemgr->addAnimatedMeshSceneNode(
 *		scenemgr->getMesh("quake2model.md2"));
 *
 *	// if everything worked, add a texture and disable lighting
 *	if (node)
 *	{
 *		node->setMaterialTexture(0, driver->getTexture("texture.bmp"));
 *		node->setMaterialFlag(video::EMF_LIGHTING, false);
 *	}
 *
 *	// add a first person shooter style user controlled camera
 *	scenemgr->addCameraSceneNodeFPS();
 *
 *	// draw everything
 *	while(device->run() && driver)
 *	{
 *		driver->beginScene(video::ECBF_COLOR | video::ECBF_DEPTH, video::SColor(255,0,0,255));
 *		scenemgr->drawAll();
 *		driver->endScene();
 *	}
 *
 *	// delete device
 *	device->drop();
 *	return 0;
 * }
 * \endcode
 *
 * Nirtcpp can load a lot of file formats automatically, see nirt::scene::ISceneManager::getMesh()
 * for a detailed list. So if you would like to replace the simple blue screen background by
 * a cool Quake 3 Map, optimized by an octree, just insert this code
 * somewhere before the while loop:
 *
 * \code
 *	// add .pk3 archive to the file system
 *	device->getFileSystem()->addZipFileArchive("quake3map.pk3");
 *
 *	// load .bsp file and show it using an octree
 *	scenemgr->addOctreeSceneNode(
 *		scenemgr->getMesh("quake3map.bsp"));
 * \endcode
 *
 * As you can see, the engine uses namespaces. Everything in the engine is
 * placed into the namespace 'irr', but there are also 5 sub namespaces.
 * You can find a list of all namespaces with descriptions at the
 * <A HREF="namespaces.html"> namespaces page</A>.
 * This is also a good place to start reading the documentation. If you
 * don't want to write the namespace names all the time, just use all namespaces like
 * this:
 * \code
 * using namespace core;
 * using namespace scene;
 * using namespace video;
 * using namespace io;
 * using namespace gui;
 * \endcode
 *
 * There is a lot more the engine can do, but I hope this gave a short
 * overview over the basic features of the engine. For more examples, please take
 * a look into the examples directory of the SDK.
 */

#include <nirtcpp/SIrrCreationParameters.hpp>

//! Everything in the Nirtcpp Engine can be found in this namespace.
namespace nirt
{
	//! Creates an Nirtcpp device. The Nirtcpp device is the root object for using the engine.
	/** If you need more parameters to be passed to the creation of the Nirtcpp Engine device,
	use the createDeviceEx() function.
	\param driverType: Type of the video driver to use. This can currently be video::EDT_NULL,
	video::EDT_SOFTWARE, video::EDT_BURNINGSVIDEO, video::EDT_DIRECT3D9 and video::EDT_OPENGL.
	\param windowSize: Size of the window or the video mode in fullscreen mode.
	\param bits: Bits per pixel in fullscreen mode. Ignored if windowed mode.
	\param fullscreen: Should be set to true if the device should run in fullscreen. Otherwise
		the device runs in windowed mode.
	\param stencilbuffer: Specifies if the stencil buffer should be enabled. Set this to true,
	if you want the engine be able to draw stencil buffer shadows. Note that not all
	devices are able to use the stencil buffer. If they don't no shadows will be drawn.
	\param vsync: Specifies vertical synchronization: If set to true, the driver will wait
	for the vertical retrace period, otherwise not.
	\param receiver: A user created event receiver.
	\return Returns pointer to the created NirtcppDevice or null if the
	device could not be created.
	*/
	extern "C" NIRTCPP_API NirtcppDevice* IRRCALLCONV createDevice(
		video::E_DRIVER_TYPE driverType = video::EDT_SOFTWARE,
		// parentheses are necessary for some compilers
		const core::dimension2d<u32>& windowSize = (core::dimension2d<u32>(640,480)),
		u32 bits = 32,
		bool fullscreen = false,
		bool stencilbuffer = true,
		bool vsync = false,
		IEventReceiver* receiver = 0);

	//! using type alias for Function Pointer
	using funcptr_createDevice = NirtcppDevice* (IRRCALLCONV *)(
			video::E_DRIVER_TYPE driverType,
			const core::dimension2d<u32>& windowSize,
			u32 bits,
			bool fullscreen,
			bool stencilbuffer,
			bool vsync,
			IEventReceiver* receiver);


	//! Creates an Nirtcpp device with the option to specify advanced parameters.
	/** Usually you should used createDevice() for creating an Nirtcpp Engine device.
	Use this function only if you wish to specify advanced parameters like a window
	handle in which the device should be created.
	\param parameters: Structure containing advanced parameters for the creation of the device.
	See nirt::SNirtcppCreationParameters for details.
	\return Returns pointer to the created NirtcppDevice or null if the
	device could not be created. */
	extern "C" NIRTCPP_API NirtcppDevice* IRRCALLCONV createDeviceEx(
		const SNirtcppCreationParameters& parameters);

	//! using type alias for Function Pointer
	using funcptr_createDeviceEx = NirtcppDevice* (IRRCALLCONV *)( const SNirtcppCreationParameters& parameters );


	// THE FOLLOWING IS AN EMPTY LIST OF ALL SUB NAMESPACES
	// EXISTING ONLY FOR THE DOCUMENTATION SOFTWARE DOXYGEN.

	//! Basic classes such as vectors, planes, arrays, lists, and so on can be found in this namespace.
	namespace core
	{
	}

	//! The gui namespace contains useful classes for easy creation of a graphical user interface.
	namespace gui
	{
	}

	//! This namespace provides interfaces for input/output: Reading and writing files, accessing zip archives, xml files, ...
	namespace io
	{
	}

	//! All scene management can be found in this namespace: Mesh loading, special scene nodes like octrees and billboards, ...
	namespace scene
	{
	}

	//! The video namespace contains classes for accessing the video driver. All 2d and 3d rendering is done here.
	namespace video
	{
	}
}

/*! \file nirtcpp/nirtcpp.hpp
	\brief Main header file of the nirtcpp, the only file needed to include.
*/

#endif
