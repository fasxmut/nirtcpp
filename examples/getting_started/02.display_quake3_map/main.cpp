/*
This program loads a quake3 map.
*/

#include <nirtcpp.hpp>
#include <iostream>
#include <string>

using namespace std::string_literals;

int main()
try {
	// nirt::NirtcppDevice
	nirt::NirtcppDevice * device = nirt::createDevice(
		nirt::video::EDT_OPENGL, // Select video driver.
		nirt::core::dimension2du{1280, 720}, // Window Size.
		32, // Color Depth, only useful in fullscreen mode.
		false, // fullscreen?
		true, // stencil buffer?
		true, // vsync?
		nullptr // event receiver
	);
	if (!device)
		throw std::runtime_error{"Can not create nirt::NirtcppDevice!"};
	device->setWindowCaption(L"Display Quake3 Map");

	nirt::video::IVideoDriver * driver = device->getVideoDriver();
	nirt::scene::ISceneManager * smgr = device->getSceneManager();

	nirt::io::IFileSystem * nfs = smgr->getFileSystem();

	// If the filesystem failed to add, we continue.
	if (!nfs->addFileArchive("../../../media/q3dm6ish.pk3"))
	if (!nfs->addFileArchive("../../media/q3dm6ish.pk3"))
	if (!nfs->addFileArchive("../media/q3dm6ish.pk3"))
	if (!nfs->addFileArchive("./media/q3dm6ish.pk3"))
	if (!nfs->addFileArchive("./q3dm6ish.pk3"))
		std::cerr << "Can not add file archive to filesystem!\n";

	const std::string map_name = "q3dm6ish.bsp";

	nirt::scene::IOctreeSceneNode * map_node = smgr->addOctreeSceneNode(
		smgr->getMesh(map_name.data()), // Mesh
		nullptr, // Parent Node
		-1, // id
		128, // Minimal polygons per node, less polys, more nodes to be splitted into.
		false // Still Add this node if the mesh is empty?
	);

	// If the map loading failed, we do not want to continue.
	if (!map_node)
		throw std::runtime_error{"Can not load map: "s + map_name};

	map_node->setPosition(nirt::core::vector3df{0});

	nirt::scene::ICameraSceneNode * fps_camera = smgr->addCameraSceneNodeFPS(
		nullptr, // Parent Node
		100.0f, // Rotation Speed
		0.5f, // Move Speed
		-1, // id
		nullptr, // Key Map Array: SKeyMap *
		0, // Key Map Array Size
		false, // Disable Vertical Movement ?
		5.0f, // Jump Speed
		false, // Invert Mouse ?
		true // Active ?
	);

	nirt::gui::ICursorControl * cursor = device->getCursorControl();
	cursor->setVisible(false); // Hide mouse cursor

	fps_camera->setPosition(nirt::core::vector3df{0, 0, -100});

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

