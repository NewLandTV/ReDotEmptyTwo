#ifndef __TITLE_H__
#define __TITLE_H__

#include "Application.h"
#include "Button.h"

class Title
{
private:
	Application* application;
	Button gameStartButton;
	Button exitButton;

public:
	Title(Application* application);
	~Title();

	void Draw();
};

#endif