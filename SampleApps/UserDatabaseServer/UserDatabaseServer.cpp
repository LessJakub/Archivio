#include <iostream>
#include "../UserDatabaseServer/UsersController.h"
#include <ArchivioHeader.h>
#include <Logger.h>

Logger serverLogger("archivioServerConfig.json");

int main()
{
    UsersController controller;

    controller.StartListen("localhost", 8080);
}