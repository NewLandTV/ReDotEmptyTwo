#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "String.h"
#include "Version.h"

class Application
{
private:
	String name;
	Version version;
	
	unsigned short width;
	unsigned short height;
	unsigned int fps;
	unsigned long long waitFrameDeltaTime;

public:
	Application(const String& name, Version version, unsigned short width, unsigned short height, unsigned int fps);
	~Application();

	void Run();
	void ShowInfo();

	const Version* GetVersion() const { return &version; }
	unsigned short GetWidth() const { return width; }
	unsigned short GetHeight() const { return height; }
	unsigned int GetFPS() const { return fps; }
	void SetFPS(unsigned int fps);
};

#endif