#ifndef __LAUNCHER_H__
#define __LAUNCHER_H__

#define MAX_COMMAND_SIZE 1024
#define DOWNLOAD_PATH "C:/NewLand/ReDotEmptyTwo/Downloads/"
#define DOWNLOAD_PATH_W "C:\\NewLand\\ReDotEmptyTwo\\Downloads"

class Launcher
{
public:
	Launcher();
	~Launcher();

	void DownloadApplication();
	void RunApplication();
	void DeleteApplication();
};

#endif