#include <iostream>
#include "Launcher.h"
#include "String.h"

int main()
{
	Launcher launcher = Launcher();

	char command[MAX_COMMAND_SIZE];

	while (true)
	{
		// Command input
		std::cout << ">";
		std::cin >> command;

		// Process command
		if (_stricmp(command, "Download") == 0)
		{
			launcher.DownloadApplication();
		}
		else if (_stricmp(command, "Run") == 0)
		{
			launcher.RunApplication();

			system("cls");
		}
		else if (_stricmp(command, "Delete") == 0)
		{
			launcher.DeleteApplication();
		}
		else if (_stricmp(command, "List") == 0)
		{
			system(String("dir ").Append(DOWNLOAD_PATH_W).GetData());
		}
		else if (_stricmp(command, "Cls") == 0)
		{
			system("cls");
		}
		else if (_stricmp(command, "Exit") == 0)
		{
			return 0;
		}
		else if (_stricmp(command, "Help") == 0)
		{
			std::cout << "Download  Download the application by entering the download link and file version." << std::endl;
			std::cout << "Run       Run that version of the application." << std::endl;
			std::cout << "Delete    Delete that version of the application." << std::endl;
			std::cout << "List      Displays a list of files and subdirectories in a directory." << std::endl;
			std::cout << "Cls       Clear the screen." << std::endl;
			std::cout << "Exit      Quits the 'Re Dot Empty Two Game Launcher.exe' program." << std::endl;
			std::cout << "Help      Provides help information for 'Re Dot Empty Two Game Launcher' commands." << std::endl;
		}
		else
		{
			std::cout << "'" << command << "' is not recognized as an internal or external command." << std::endl;
			std::cout << "operable program file." << std::endl;
		}

		std::cout << std::endl;
	}

	return 0;
}