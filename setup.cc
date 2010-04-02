/*
 * Plugin for VDR to open the CD/DVD-Tray
 *
 * Copyright (C) 2010 Ulrich Eckhardt <uli-vdr@uli-eckhardt.de>
 *
 * This code is distributed under the terms and conditions of the
 * GNU GENERAL PUBLIC LICENSE. See the file COPYING for details.
 *
 */

#include <vdr/menuitems.h>
#include "trayopenng.h"

cMenuSetupTrayopenng::cMenuSetupTrayopenng(cPluginTrayopenng *Plugin)
    : cMenuSetupPage()
{
    SetPlugin (Plugin);
    pPlugin = Plugin;
    mShowMainMenu = pPlugin->getHideMainMenuEntry();
    Add(new cMenuEditBoolItem(tr("Show in main menu"),
            (int *)&mShowMainMenu));
}

void cMenuSetupTrayopenng::Store(void)
{
    SetupStore(HIDEMAINMENUEENTRY, (int)mShowMainMenu);
    pPlugin->setHideMainMenuEntry(mShowMainMenu);
}

