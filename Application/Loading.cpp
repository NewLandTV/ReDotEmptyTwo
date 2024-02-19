#include <iostream>
#include "Loading.h"
#include "Util.h"

Loading::Loading()
{

}

Loading::~Loading()
{

}

void Loading::LoadScene()
{
	Util::SetColor(Util::Color::Sky);

	for (int i = 0; i <= 100; i++)
	{
		Util::Gotoxy(2, 0);

		std::cout << i << "%";

		Util::Wait(25);
	}

	Util::Wait(100);
	Util::Gotoxy(2, 0);

	std::cout << "LOADED.";

	Util::Wait(500);
}