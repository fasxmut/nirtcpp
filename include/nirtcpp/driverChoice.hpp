// Copyright (C) 2009-2012 Christian Stehno
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_E_DRIVER_CHOICE_H_INCLUDED
#define NIRT_E_DRIVER_CHOICE_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <nirtcpp/EDriverTypes.hpp>
#include <nirtcpp/NirtcppDevice.hpp>

namespace nirt
{
    
    //! ask user for driver
    static nirt::video::E_DRIVER_TYPE driverChoiceConsole(bool allDrivers=false)
    {
#if defined (_NIRT_IPHONE_PLATFORM_) || defined (_NIRT_ANDROID_PLATFORM_)
        return nirt::video::EDT_OGLES2;
#else
        printf("Please select the driver you want:\n");
        nirt::u32 i=0;
        char c  = 'a';
        
        for (i=nirt::video::EDT_COUNT; i>0; --i)
        {
            if ( allDrivers || nirt::NirtcppDevice::isDriverSupported(nirt::video::E_DRIVER_TYPE(i-1)) )
            {
                printf(" (%c) %s\n", c, nirt::video::DRIVER_TYPE_NAMES[i-1]);
				++c;
            }
        }

		char userSelection;
        std::cin >> userSelection;
        c = 'a';
        
        for (i=nirt::video::EDT_COUNT; i>0; --i)
        {
			if ( allDrivers || nirt::NirtcppDevice::isDriverSupported(nirt::video::E_DRIVER_TYPE(i-1)) )
			{
				if (userSelection == c)
					return nirt::video::E_DRIVER_TYPE(i-1);
				++c;
			}
        }

        return nirt::video::EDT_COUNT;
#endif
    }
    
	/*
		For using an alternative camera in the examples.
		Try to translate the viewpoint (Maya internal CameraRotation)
	*/
	static inline void switchToMayaCamera(NirtcppDevice* device)
	{
#if 1
		return;
#else
		if (!device) return;

		scene::ICameraSceneNode* camera = device->getSceneManager()->getActiveCamera();
		if (!camera || camera->getID() == 54321) return;


		core::vector3df target = camera->getTarget() - camera->getPosition();
		core::vector3df relativeRotation = target.getHorizontalAngle();

		scene::ICameraSceneNode* maya = device->getSceneManager()->addCameraSceneNodeMaya(
			0, -1500, 1000, 1500,
			54321,
			target.getLength(),
			true,
			relativeRotation.X + 90, relativeRotation.Y
		);
		if (maya)
		{
			maya->setNearValue(camera->getNearValue());
			maya->setFarValue(camera->getFarValue());
		}

		device->getCursorControl()->setVisible(true);
		device->setResizable(true);
#endif
	}

} // end namespace nirt

#endif
