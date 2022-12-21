#include <nirtcpp/nirtcpp.hpp>
#include <iostream>
#include <tuple>
#include <string>

namespace quake3 = nirt::scene::quake3;
using namespace std::string_literals;

std::string q3m_index_to_string(const quake3::eQ3MeshIndex & index)
{
	switch (index)
	{
	case quake3::E_Q3_MESH_GEOMETRY:
		return "E_Q3_MESH_GEOMETRY";
	case quake3::E_Q3_MESH_ITEMS:
		return "E_Q3_MESH_ITEMS";
	case quake3::E_Q3_MESH_BILLBOARD:
		return "E_Q3_MESH_BILLBOARD";
	case quake3::E_Q3_MESH_UNRESOLVED:
		return "E_Q3_MESH_UNRESOLVED";
	default:
		return "eQ3MeshIndex:"s + std::to_string(index);
	}
}

auto load_q3_mesh = [] (nirt::scene::ISceneManager * smgr,
	nirt::scene::IMetaTriangleSelector * meta_selector, nirt::scene::IQ3LevelMesh * q3l_mesh,
	quake3::eQ3MeshIndex index) -> void
{
	nirt::scene::IMesh * level_mesh = q3l_mesh->getMesh(index);
	std::uint32_t mb_count = level_mesh->getMeshBufferCount();
	std::cout << q3m_index_to_string(index) << " => ";
	if (mb_count == 0)
	{
		std::cout << "no mesh buffer!\n";
		return;
	}
	else
	{
		std::cout << mb_count << " mesh buffers!\n";
	}
	for (std::uint32_t mb_index; mb_index<mb_count; mb_index++)
	{
		nirt::scene::IMeshBuffer * mesh_buffer = level_mesh->getMeshBuffer(mb_index);
		if (!mesh_buffer)
			continue;
		nirt::video::SMaterial & mb_material = mesh_buffer->getMaterial();
		nirt::s32 shader_index = mb_material.MaterialTypeParam2;
		const quake3::IShader * shader = q3l_mesh->getShader(shader_index);
		if (!shader)
			continue;
		nirt::scene::IMeshSceneNode * node = smgr->addQuake3SceneNode(
			mesh_buffer,
			shader,
			nullptr,
			-1
		);
		if (!node)
			continue;
		nirt::scene::ITriangleSelector * selector = smgr->createTriangleSelector(
			node->getMesh(),
			node
		);
		node->setTriangleSelector(selector);
		meta_selector->addTriangleSelector(selector);
		selector->drop();
	}
};

auto load_extra_mesh = [] (nirt::scene::ISceneManager * smgr,
	nirt::scene::IMetaTriangleSelector * meta_selector, nirt::scene::IQ3LevelMesh * q3l_mesh) -> void
{
	for (auto & index: {quake3::E_Q3_MESH_ITEMS, quake3::E_Q3_MESH_BILLBOARD,
		quake3::E_Q3_MESH_FOG, quake3::E_Q3_MESH_UNRESOLVED})
	{
		load_q3_mesh(smgr, meta_selector, q3l_mesh, index);
	}
};

int main()
try
{
	nirt::NirtcppDevice * device = nirt::createDevice(
		nirt::video::EDT_OPENGL,
		nirt::core::dimension2du{1280, 720},
		32,
		false,
		true,
		true,
		nullptr
	);
	if (device == nullptr)
		throw std::runtime_error{"ERROR: nirt::createDevice"};
	auto [driver, smgr, nfs, cursor] = std::make_tuple(
		device->getVideoDriver(),
		device->getSceneManager(),
		device->getFileSystem(),
		device->getCursorControl()
	);
	nirt::scene::ICameraSceneNode * camera = smgr->addCameraSceneNodeFPS(
		nullptr, 100.0f, 0.5f, -1, nullptr, 0, false, 5.0f, false, true
	);
	cursor->setVisible(false);
	
	nirt::scene::IMetaTriangleSelector * meta_selector = smgr->createMetaTriangleSelector();
	
	for (const std::string path: {"../../../media/oa_koth2.pk3", "../../media/oa_koth2.pk3",
		"../media/oa_koth2.pk3", "./media/oa_koth2.pk3", "oa_koth2.pk3"})
	{
		if (nfs->addFileArchive(path.data()))
			break;
	}
	
	nirt::scene::IAnimatedMesh * map_mesh = smgr->getMesh("oa_koth2.bsp");
	if (!map_mesh)
		throw std::runtime_error{"ERROR: Load Map Mesh"};
	
	nirt::scene::IOctreeSceneNode * map_node = smgr->addOctreeSceneNode(
		map_mesh->getMesh(quake3::E_Q3_MESH_GEOMETRY),
		nullptr,
		-1,
		32
	);
	
	nirt::scene::ITriangleSelector * selector = smgr->createOctreeTriangleSelector(
		map_node->getMesh(),
		map_node,
		32
	);
	map_node->setTriangleSelector(selector);
	meta_selector->addTriangleSelector(selector);
	selector->drop();
	
	load_extra_mesh(smgr, meta_selector, (nirt::scene::IQ3LevelMesh *)map_mesh);
	
	nirt::scene::ISceneNodeAnimator * colli = smgr->createCollisionResponseAnimator(
		meta_selector,
		camera,
		nirt::core::vector3df{10, 30, 10},
		nirt::core::vector3df{0, -10000, 0},
		nirt::core::vector3df{0, 12, 0},
		0.005f
	);
	camera->setPosition({-252,862,768});
	camera->addAnimator(colli);
	colli->drop();

	while (device->run())
	{
		if (device->isWindowActive())
		{
			driver->beginScene(nirt::video::ECBF_COLOR | nirt::video::ECBF_DEPTH,
				nirt::video::SColor{0xff3779a3});
			smgr->drawAll();
			driver->endScene();
		}
		else
		{
			device->yield();
		}
	}
}
catch (std::exception & err)
{
	std::cerr << "------------------------------------------------------------------------\n"
		<< "[std::exception] " << err.what() << std::endl;
	return 1;
}

