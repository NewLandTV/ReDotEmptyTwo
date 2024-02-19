#include <iostream>
#include <Windows.h>
#include <urlmon.h>
#include <wininet.h>
#include <direct.h>
#include "Launcher.h"
#include "String.h"

#pragma comment(lib,"UrlMon.lib")
#pragma comment(lib, "wininet.lib")

Launcher::Launcher()
{
	system("title Re Dot Empty Two - Game Launcher");
	system("mode con cols=120 lines=30");
	system("chcp 437");
	system("cls");
}

Launcher::~Launcher()
{

}

void Launcher::DownloadApplication()
{
	String downloadPath = DOWNLOAD_PATH;
	char url[MAX_COMMAND_SIZE];
	char filename[MAX_COMMAND_SIZE];

	// Input
	std::cin >> url >> filename;

	// FIle name is [version.exe]
	downloadPath.Append(filename).Append(".exe");

	// Check and create folder
	char buffer[MAX_COMMAND_SIZE];
	char* ptr = buffer;

	strcpy_s(buffer, downloadPath.GetData());

	buffer[MAX_COMMAND_SIZE - 1] = '\0';

	while (*ptr)
	{
		if (*ptr == '/')
		{
			*ptr = '\0';

			_mkdir(buffer);

			*ptr = '/';
		}

		ptr++;
	}

	// Download application
	HRESULT hresult = URLDownloadToFileA(0, String("https://drive.google.com/uc?export=download&id=").Append(url).Append("&confirm=t").GetData(), downloadPath.GetData(), 0, 0);

	if (hresult != S_OK)
	{
		std::cout << "Download failed!" << std::endl;

		return;
	}

	DeleteUrlCacheEntryA(url);

	std::cout << "Download success!" << std::endl;
}

void Launcher::RunApplication()
{
	char filename[MAX_COMMAND_SIZE];

	// Input filename
	std::cin >> filename;

	// Run
	system(String(DOWNLOAD_PATH).Append(filename).Append(".exe").GetData());
}

void Launcher::DeleteApplication()
{
	char filename[MAX_COMMAND_SIZE];

	// Input filename
	std::cin >> filename;

	// Delete
	if (remove(String(DOWNLOAD_PATH).Append(filename).Append(".exe").GetData()) == 0)
	{
		std::cout << "The " << filename << " version of the application has been removed.";

		return;
	}

	std::cout << "Application delete failed.";
}