/*
    This source file is part of Rigs of Rods
    Copyright 2005-2012 Pierre-Michel Ricordel
    Copyright 2007-2012 Thomas Fischer
    Copyright 2013+     Petr Ohlidal & contributors

    For more information, see http://www.rigsofrods.org/

    Rigs of Rods is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 3, as
    published by the Free Software Foundation.

    Rigs of Rods is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Rigs of Rods. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file
/// @author Moncef Ben Slimane
/// @date   12/2014

#pragma once

#include "ForwardDeclarations.h"
#include "GUI_SimUtilsLayout.h"
#include "InterThreadStoreVector.h"

namespace RoR {

struct NotificationMessage
{
    unsigned long time; //!< post time in milliseconds since RoR start
    unsigned long ttl; //!< in milliseconds
    Ogre::UTFString txt; //!< not POD, beware...
    Ogre::UTFString title; //!< not POD, beware...
};

namespace GUI {

class SimUtils: public SimUtilsLayout
{
public:
    SimUtils();
    ~SimUtils();

    void SetBaseVisible(bool v);
    bool IsBaseVisible();

    void SetFPSBoxVisible(bool v);
    bool IsFPSBoxVisible() { return b_fpsbox; }

    void SetTruckInfoBoxVisible(bool v);
    bool IsTruckInfoBoxVisible() { return b_truckinfo; }

    void UpdateStats(float dt, Beam* truck); //different from Framestep!
    void framestep(float dt);

    void PushNotification(Ogre::String Title, Ogre::String text);
    void HideNotificationBox();
    void DisableNotifications(bool disabled);

private:
    bool b_fpsbox;
    bool b_truckinfo;
    bool b_notification;

    //taken from TruckHUD.h
    std::map<int, float> avVelos;
    std::map<int, float> maxNegLatG;
    std::map<int, float> maxNegSagG;
    std::map<int, float> maxNegVerG;
    std::map<int, float> maxPosLatG;
    std::map<int, float> maxPosSagG;
    std::map<int, float> maxPosVerG;
    std::map<int, float> maxVelos;
    std::map<int, float> minVelos;

    //Colors
    Ogre::UTFString MainThemeColor; // colour key shortcut
    Ogre::UTFString WhiteColor; // colour key shortcut
    Ogre::UTFString RedColor; // colour key shortcut
    Ogre::UTFString BlueColor; // colour key shortcut

    Ogre::String truckstats;

    std::vector<NotificationMessage> tmpWaitingNotifications;

    // logic
    float alpha;
    long pushTime;
    bool m_notifications_disabled;
};

} // namespace GUI
} // namespace RoR
