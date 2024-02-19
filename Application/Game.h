#ifndef __GAME_H__
#define __GAME_H__

#include "Application.h"

class Game
{
private:
	Application* application;

public:
	Game(Application* application);
	~Game();

	void Draw();
};

#endif