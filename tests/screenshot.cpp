// Copyright (C) 2008-2012 Colin MacDonald
// No rights reserved: this software is in the public domain.

#include "testUtils.hpp"

using namespace nirt;

static nirt::u8 aa = 0;	// AntiAlias used in testShotsInShots

// Tests screenshots features
static bool testShots(video::E_DRIVER_TYPE type)
{
	NirtcppDevice *device = createDevice(type, core::dimension2d<u32>(160, 120), 32);
	if (!device)
		return true;

	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager * smgr = device->getSceneManager();

	logTestString("Testing driver %ls\n", driver->getName());

	scene::IAnimatedMesh* mesh = smgr->getMesh("../media/sydney.md2");
	scene::IAnimatedMeshSceneNode* node;

	if (!mesh)
		return false;
	node = smgr->addAnimatedMeshSceneNode(mesh);
	if (!node)
		return false;

	stabilizeScreenBackground(driver);

	node->setPosition(core::vector3df(20, 0, 30));
	node->setMaterialFlag(video::EMF_LIGHTING, false);
	node->setMaterialTexture(0, driver->getTexture("../media/sydney.bmp"));
	node->setLoopMode(false);

	smgr->addCameraSceneNode();

	node->setMD2Animation(scene::EMAT_DEATH_FALLBACK);
	node->setCurrentFrame((f32)(node->getEndFrame()));
	node->setAnimationSpeed(0);

	device->run();
	driver->beginScene(video::ECBF_COLOR | video::ECBF_DEPTH, video::SColor(255, 255, 255, 0));
	smgr->drawAll();
	driver->endScene();

	for (s32 i=0; i<video::ECF_UNKNOWN; ++i)
	{
		video::IImage* img = driver->createScreenShot((video::ECOLOR_FORMAT)i);
		logTestString("Color Format %d %ssupported\n", i, (img && img->getColorFormat() == i)?"":"un");

#if 0	// Enable for a quick check while testing.
		// If someone adds comparison images please use another scene without animation
		// and maybe a texture using the full color spectrum.
		if ( img )
		{
			nirt::core::stringc screenshotFilename = "results/";
			screenshotFilename += shortDriverName(driver);
			screenshotFilename += "screenshot";
			screenshotFilename += core::stringc(i);
			screenshotFilename += ".png";
			driver->writeImageToFile(img, screenshotFilename.data());
		}
#endif

		if (img)
			img->drop();
	}
	device->closeDevice();
	device->run();
	device->drop();

	return true;
}

// render some recognizable stuff
static void drawSomeStuff(video::IVideoDriver* driver)
{
	driver->draw2DRectangle(core::recti(5,5,155,115), 
				video::SColor(255, 100, 0, 0),
				video::SColor(255, 0, 200, 0),
				video::SColor(255, 0, 0, 200),
				video::SColor(255, 20, 150, 150));
	driver->draw2DLine(core::position2di(10,10), core::position2di(150,110), video::SColor(255,250,50,0));
	driver->draw2DLine(core::position2di(0,120), core::position2di(80,60), video::SColor(255,50,50,250));
}

// Make a screenshot, then draw it again (scaled down) together with the stuff the screenshot was made from
static bool testShotsOfShots(video::E_DRIVER_TYPE type)
{
	SNirtcppCreationParameters params;
	params.AntiAlias = aa;
	params.WindowSize = core::dimension2du(160, 120);
	params.DriverType = type;

	NirtcppDevice *device = createDeviceEx(params);

	if (!device)
		return true; // in case the driver type does not exist

	video::IVideoDriver* driver = device->getVideoDriver();
	logTestString("Testing driver %ls\n", driver->getName());
	stabilizeScreenBackground(driver);

	device->run();
	driver->beginScene(video::ECBF_COLOR | video::ECBF_DEPTH, video::SColor(255,100,101,140));
	drawSomeStuff(driver);
	driver->endScene();
	video::IImage* img = driver->createScreenShot();

	bool result = true;
	if ( img )
	{
		video::ITexture * screenshot = driver->addTexture(io::path("firstScreenshot"), img);

		driver->beginScene(video::ECBF_COLOR | video::ECBF_DEPTH, video::SColor(255,100,101,140));
		drawSomeStuff(driver);
		driver->draw2DImage(screenshot, core::recti(0, 30, 80, 90), core::recti(screenshot->getOriginalSize()), 0, 0, 0);
		driver->endScene();
		img->drop();

		nirt::core::stringc name("-shotsInShots");
		name += nirt::core::stringc((int)aa);
		name += ".png";
		result = takeScreenshotAndCompareAgainstReference(driver, name.data());
		if ( !result )
		{
			logTestString("driver color format: %s\n", video::ColorFormatNames[driver->getColorFormat()]);
		}
	}
	else
	{
		logTestString("Failed to create a screenshot");
		result = false;
	}


	device->closeDevice();
	device->run();
	device->drop();

	return result;
}

bool screenshot()
{
	bool result = true;
	TestWithAllHWDrivers(testShots);
	aa = 0;
	TestWithAllDrivers(testShotsOfShots);
	aa = 2;	// testing something that might cause troubles with Nouveau on some systems
	TestWithAllDrivers(testShotsOfShots);
	return result;
}
