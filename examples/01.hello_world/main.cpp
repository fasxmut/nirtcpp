/*
This is a simple program that loads a mesh model from disk, add a camera, display the scene.
*/

#include <nirtcpp.hpp>
#include <iostream>
#include <string>

using namespace std::string_literals;

int main()
try {
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
	if (!device)
		throw std::runtime_error{"Can not create nirt::NirtcppDevice!"};

	nirt::video::IVideoDriver * driver = device->getVideoDriver();
	nirt::scene::ISceneManager * smgr = device->getSceneManager();

	// Add a camera node to the scene. We can not see anything without a camera.
	nirt::scene::ICameraSceneNode * fps_camera = smgr->addCameraSceneNodeFPS();
	// Set camera position.
	fps_camera->setPosition(nirt::core::vector3df{0,0,-15});

	const std::string ninja_mesh_filename = "../../media/ninja.b3d";
	nirt::scene::IAnimatedMeshSceneNode * ninja_node = smgr->addAnimatedMeshSceneNode(
		smgr->getMesh(ninja_mesh_filename.data()), // Mesh model on disk.
		nullptr, // Parent node
		-1, // Node id
		nirt::core::vector3df{0,-5,0}, // Position
		nirt::core::vector3df{0,150,0}, // Rotation       Rotate 150 degrees about Y.
		nirt::core::vector3df{1,1,1}, // Scale
		false // Still add if the mesh is empty?
	);
	if (!ninja_node)
		std::cerr << "Can not load ninja_node: " << ninja_mesh_filename << '\n';
	else // Turn off light. For a beginner's code, this program does not use advanced lighting here.
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
} catch (std::exception & err) {
	std::cerr << "========================================================================\n";
	std::cerr << "[std::exception] " << err.what() << '\n';
	return 1;
}

