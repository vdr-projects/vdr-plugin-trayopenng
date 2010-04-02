/*
 * Plugin for VDR to open the CD/DVD-Tray
 *
 * Copyright (C) 2010 Ulrich Eckhardt <uli-vdr@uli-eckhardt.de>
 *
 * This code is distributed under the terms and conditions of the
 * GNU GENERAL PUBLIC LICENSE. See the file COPYING for details.
 *
 */

#ifndef _TRAYOPENNG_H
#define _TRAYOPENNG_H

#include <vdr/plugin.h>
#include <vdr/status.h>
#include "setup.h"

static const char *VERSION        = "0.5.0";
static const char *HIDEMAINMENUEENTRY = "HideMainMenuEntry";
static const char *MAINMENUENTRY  = trNOOP("Trayopenng");
static const char *DESCRIPTION    = trNOOP("Open and close tray of CDROM");

#define MAX_CMD_LEN 1024

class cPluginTrayopenng: public cPlugin {
private:
    bool mShowMainMenu;
    char mDevice[PATH_MAX + 1];
    char mCommand[MAX_CMD_LEN];

public:
    cPluginTrayopenng(void);
    virtual const char *Version(void) { return VERSION; };
    virtual const char *Description(void) { return tr(DESCRIPTION); };
    virtual const char *CommandLineHelp(void);
    virtual bool ProcessArgs(int argc, char *argv[]);
    virtual bool Initialize(void) { return true; };
    virtual bool Start(void) { return true; };
    virtual void Stop(void) { };
    virtual void Housekeeping(void) {};
    virtual void MainThreadHook(void) {};
    virtual cString Active(void) { return NULL; };
    virtual time_t WakeupTime(void) { return 0; };
    virtual const char *MainMenuEntry(void);
    virtual cOsdObject *MainMenuAction(void);
    virtual cMenuSetupPage *SetupMenu(void);
    virtual bool SetupParse(const char *Name, const char *Value);
    virtual bool Service(const char *Id, void *Data = NULL) {return false;};
    virtual const char **SVDRPHelpPages(void);
    virtual cString SVDRPCommand(const char *Command, const char *Option,
            int &ReplyCode);

    bool getHideMainMenuEntry(void) { return mShowMainMenu; };
    void setHideMainMenuEntry(bool hide) { mShowMainMenu = hide; };
};

#endif
