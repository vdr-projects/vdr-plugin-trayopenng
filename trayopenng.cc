/*
 * Plugin for VDR to open the CD/DVD-Tray
 *
 * Copyright (C) 2010 Ulrich Eckhardt <uli-vdr@uli-eckhardt.de>
 *
 * This code is distributed under the terms and conditions of the
 * GNU GENERAL PUBLIC LICENSE. See the file COPYING for details.
 *
 */

#include <getopt.h>
#include <stdlib.h>
#include "trayopenng.h"

cPluginTrayopenng::cPluginTrayopenng(void)
{
    strcpy(mDevice, "/dev/dvd");
    strcpy(mCommand, "eject -T");
}

const char *cPluginTrayopenng::CommandLineHelp(void)
{
    return "-d  --device  <device>   CD-Rom Device : /dev/cdrom\n"
            "-c  --command <command>  Eject command : eject -T";
}

bool cPluginTrayopenng::ProcessArgs(int argc, char *argv[])
{
    static struct option long_options[] = {
            { "device", required_argument, NULL, 'd' },
            { "command", required_argument, NULL, 'c' },
            { NULL }
    };
    int c, option_index = 0;

    while ((c = getopt_long(argc, argv, "d:", long_options, &option_index))
            != -1) {
        switch (c) {
        case 'd':
            strcpy(mDevice, optarg);
            break;
        case 'c':
            strcpy(mCommand, optarg);
            break;
        default:
            return false;
        }
    }
    return true;
}

const char *cPluginTrayopenng::MainMenuEntry(void)
{
    if (mShowMainMenu) {
        return MAINMENUENTRY;
    }
    return NULL;
}

cOsdObject *cPluginTrayopenng::MainMenuAction(void)
{
    char *buf = NULL;
    asprintf(&buf, "%s %s", mCommand, mDevice);
    if (buf == NULL) {
        esyslog("%s %d Out of memory", __FILE__, __LINE__);
        return NULL;
    }
    dsyslog("Trayopenng: Command %s", buf);
    system(buf);
    return NULL;
}

cMenuSetupPage *cPluginTrayopenng::SetupMenu(void)
{
    return new cMenuSetupTrayopenng (this);
}

bool cPluginTrayopenng::SetupParse(const char *Name, const char *Value)
{
    if (strcasecmp(Name, HIDEMAINMENUEENTRY) == 0) {
        mShowMainMenu = atoi(Value);
        return true;
    }
    return false;
}

const char **cPluginTrayopenng::SVDRPHelpPages(void)
{
    static const char *HelpPages[] = {
        "EJECT\n"
        "    Open/Close the CD-Tray.",
        NULL
    };
    return HelpPages;

}

cString cPluginTrayopenng::SVDRPCommand(const char *Command,
                                            const char *Option, int &ReplyCode)
{
    if (strcasecmp(Command, "EJECT") == 0) {
        MainMenuAction();
        return "OK";
    }
    return NULL;
}


VDRPLUGINCREATOR(cPluginTrayopenng)
; // Don't touch this!
