#include <iostream>
#include <Windows.h>
#include <chrono>
#include "Application.h"
#include "Util.h"
#include "Math.h"
#include "GameManager.h"

Application::Application(const String& name, Version version, unsigned short width, unsigned short height, unsigned int fps) : name(name), version(version), width(width), height(height), fps(fps), waitFrameDeltaTime(Math::RoundToInt(Math::DivideEx(1000, fps)))
{
	// Set title
	String titleCommand = "title ";

	titleCommand.Append(name);

	system(titleCommand.GetData());

	// Set console width and height
	String modeConCommand = "mode con cols=";

	int tempLength;

	for (tempLength = 0; width; tempLength++)
	{
		width = Math::DivideEx(width, 10);
	}

	tempLength++;

	char* temp = new char[tempLength];

	sprintf_s(temp, tempLength, "%d", this->width);

	modeConCommand.Append(temp);

	delete[] temp;

	for (tempLength = 0; height; tempLength++)
	{
		height = Math::DivideEx(height, 10);
	}

	tempLength++;

	temp = new char[tempLength];

	modeConCommand.Append(" lines=");

	sprintf_s(temp, tempLength, "%d", this->height);

	modeConCommand.Append(temp);

	delete[] temp;

	system(modeConCommand.GetData());

	// Set window position
	SetWindowPos(GetConsoleWindow(), 0, this->width * 0.75, this->height * 2, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// Set console cursor info
	CONSOLE_CURSOR_INFO consoleCursorInfo;

	consoleCursorInfo.bVisible = 0;
	consoleCursorInfo.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
}

Application::~Application()
{

}

void Application::Run()
{
	GameManager gameManager = GameManager(this);

	auto time1 = std::chrono::system_clock::now();
	auto time2 = std::chrono::system_clock::now();

	while (true)
	{
		time2 = std::chrono::system_clock::now();

		std::chrono::duration<float> elapsedTime = time2 - time1;

		time1 = time2;

		gameManager.Update(elapsedTime.count());

		Util::Wait(waitFrameDeltaTime);
	}
}

void Application::ShowInfo()
{
	Util::Gotoxy(2, height - 4);
	Util::SetColor(Util::Color::DarkGrey);

	std::cout << name.GetData();

	Util::Gotoxy(2, height - 3);

	std::cout << "v" << version.ToString().GetData();

	Util::Gotoxy(2, height - 2);

	std::cout << width << "x" << height;
}

void Application::SetFPS(unsigned int fps)
{
	this->fps = fps;

	waitFrameDeltaTime = Math::RoundToInt(Math::DivideEx(1000, fps));
}