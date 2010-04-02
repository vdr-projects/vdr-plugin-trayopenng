/*
 * Plugin for VDR to open the CD/DVD-Tray
 *
 * Copyright (C) 2010 Ulrich Eckhardt <uli-vdr@uli-eckhardt.de>
 *
 * This code is distributed under the terms and conditions of the
 * GNU GENERAL PUBLIC LICENSE. See the file COPYING for details.
 *
 */

#ifndef _SETUP_H
#define _SETUP_H

class cPluginTrayopenng;

class cMenuSetupTrayopenng: public cMenuSetupPage {
private:
    bool mShowMainMenu;
    cPluginTrayopenng *pPlugin;

protected:
    virtual void Store(void);

public:
    cMenuSetupTrayopenng(cPluginTrayopenng *Plugin);
};

#endif
