#include <iostream>
#include <conio.h>
#include "TItle.h"
#include "Util.h"

Title::Title(Application* application) : application(application), gameStartButton("Game Start", Vector2(application->GetWidth() >> 1, (application->GetHeight() >> 1) + 10), Vector2(16.0f, 3.0f), Util::Color::White), exitButton("Exit", Vector2(application->GetWidth() >> 1, (application->GetHeight() >> 1) + 14), Vector2(16.0f, 3.0f), Util::Color::White)
{
	
}

Title::~Title()
{

}

void Title::Draw()
{
	gameStartButton.Draw();
	exitButton.Draw();
}