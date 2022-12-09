/*
This program loads a quake3 map as world map, and create collision detection between user (camera) and the world map.
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
	device->setWindowCaption(L"Collision Detection of Nirtcpp");

	nirt::video::IVideoDriver * driver = device->getVideoDriver();
	nirt::scene::ISceneManager * smgr = device->getSceneManager();

	nirt::io::IFileSystem * nfs = smgr->getFileSystem();

	// If the filesystem failed to add, we continue.
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
		128, // Minimal Polygons Per-Node
		false // Still Add this node if the mesh is empty?
	);

	// If the map loading failed, we do not want to continue.
	if (!map_node)
		throw std::runtime_error{"Can not load map: "s + map_name};

	map_node->setPosition(nirt::core::vector3df{0});

	nirt::scene::ICameraSceneNode * fps_camera = smgr->addCameraSceneNodeFPS(
		nullptr, 100.0f, 0.5f, -1, nullptr, 0, false, 5.0f, false, true
	);
	fps_camera->setPosition(nirt::core::vector3df{0, 0, -100});

	nirt::gui::ICursorControl * cursor = device->getCursorControl();
	cursor->setVisible(false); // Hide mouse cursor

	// Irrlicht triangle selector is used for collision detection.
	nirt::scene::ITriangleSelector * selector = smgr->createTriangleSelector(
		map_node->getMesh(), // Where the triangles are taken.
		map_node, // Node of which visibility and transformation are used.
		128 // Minimal polygons per node, less polys, more nodes to be splitted into.
	);
	// BOOST_ASSERT(map_node->getTriangleSelector() == nullptr);
	// Set the triangle selector of the scene node (world map).
	map_node->setTriangleSelector(selector);

	// Create collision detection animator.
	nirt::scene::ISceneNodeAnimator * collision_detection = smgr->createCollisionResponseAnimator(
		selector,
		fps_camera,
		nirt::core::vector3df{5, 40, 5}, // Bounding Box Radius (ellipsoid Radius)
		nirt::core::vector3df{0, -1000, 0}, // Gravity in X, Y, Z directions.
		nirt::core::vector3df{0, 20, 0}, // Ellipsoid Translation.
		0.005f // Sliding Value
	);
	fps_camera->addAnimator(collision_detection); // You need to add the collision animator to the node.

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

