#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include <Windows.h>
#include "Application.h"
#include "ItemManager.h"
#include "Screen.h"
#include "Player.h"
#include "Inventory.h"
#include "SaveAndLoad.h"
#include "Data.h"
#include "Resource.h"
#include "Time.h"

int CtrlHandler(DWORD ctrlType);

class GameManager
{
private:
	Application* application;
	ItemManager itemManager;
	Screen screen;
	Player player;
	Inventory inventory;
	SaveAndLoad saveAndLoad;
	Data data;
	Resource* resources;
	Time time;

public:
	static GameManager* instance;

	GameManager(Application* application);
	~GameManager();

	void Update(float deltaTime);
	void ExitEvent();
};

#endif