#include <iostream>
#include <cstdlib>
#include "Game.h"
#include "Util.h"

Game::Game(Application* application) : application(application)
{

}

Game::~Game()
{

}

void Game::Draw()
{
	system("cls");

	Util::Gotoxy((application->GetWidth() >> 1) - 9, application->GetHeight() >> 1);
	Util::SetColor(Util::Color::DarkRed);

	std::cout << "This is game scene.";

	Util::Wait(2000);

	system("cls");

	Util::Wait(1000);
}