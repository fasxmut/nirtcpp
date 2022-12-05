/*
This is a simple program that loads a mesh model from disk, add a camera, display the scene.

Compile the program:
	g++ main.cpp -std=c++20 -I ../../include/ -L ../../lib/Linux/ -lnirtcpp -o hello_world
*/

#include <nirtcpp.hpp>
#include <iostream>

int main()
{
	// nirt::NirtcppDevice
	nirt::NirtcppDevice * device = nirt::createDevice(
		nirt::video::EDT_BURNINGSVIDEO, // Select video driver.
		nirt::core::dimension2du{1280, 720}, // Window Size.
		32, // Color Depth, only useful in fullscreen mode.
		false, // fullscreen?
		true, // stencil buffer?
		true, // vsync?
		nullptr // event receiver
	);
	if (!device) {
		std::cerr << "Can not create nirt::NirtcppDevice!\n";
		return 1;
	}

	nirt::video::IVideoDriver * driver = device->getVideoDriver();
	nirt::scene::ISceneManager * smgr = device->getSceneManager();

	// Irrlicht File System.
	nirt::io::IFileSystem * fs = device->getFileSystem();
	const std::string media_path = "../../media";
	// After add a system path to irrlicht, you can load file easily.
	bool status = fs->addFileArchive(media_path.data());
	if (!status)
		std::cerr << "Can not add media path: " << media_path << std::endl;

	// Add a camera node to the scene. We can not see anything without a camera.
	nirt::scene::ICameraSceneNode * fps_camera = smgr->addCameraSceneNodeFPS();
	// Set camera position.
	fps_camera->setPosition(nirt::core::vector3df{0,0,-15});

	nirt::scene::IAnimatedMeshSceneNode * ninja_node = smgr->addAnimatedMeshSceneNode(
		smgr->getMesh("ninja.b3d"), // Mesh model on disk.
		nullptr, // Parent node
		-1, // Node id
		nirt::core::vector3df{0,-5,0}, // Position
		nirt::core::vector3df{0,150,0}, // Rotation       Rotate 150 degrees about Y.
		nirt::core::vector3df{1,1,1}, // Scale
		false // Still add if the mesh is empty?
	);

	// Turn off light. For a beginner's code, this program does not use advanced lighting here.
	ninja_node->setMaterialFlag(nirt::video::EMF_LIGHTING, false);


	// 'device->run()' will do two task: display the scene, and return if the window is running.
	while (device->run()) {
		if (device->isWindowActive()) {
			driver->beginScene(true, true, nirt::video::SColor{0xff34699a});
			smgr->drawAll();
			driver->endScene();
		} else {
			device->yield(); // Yield the device to save resources if the window is inactive.
		}
	}
	device->drop();
	std::cout << "Window is closed." << std::endl;
}

