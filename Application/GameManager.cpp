#include <iostream>
#include "GameManager.h"
#include "Util.h"
#include "InputField.h"

int CtrlHandler(DWORD ctrlType)
{
	switch (ctrlType)
	{
	case CTRL_C_EVENT:
	case CTRL_CLOSE_EVENT:
	case CTRL_BREAK_EVENT:
	case CTRL_LOGOFF_EVENT:
	case CTRL_SHUTDOWN_EVENT:
	default:
		GameManager::instance->ExitEvent();

		break;
	}

	return 0;
}

GameManager* GameManager::instance = nullptr;

GameManager::GameManager(Application* application) : application(application), itemManager(), screen(Vector2(0.0f, 4.0f), Vector2(application->GetWidth(), application->GetHeight())), player(application, &screen, 9999, 100, 50, 50, 4.2f, 7.5f), inventory(application, &screen, &player, &itemManager, 10), saveAndLoad(application), data(&player, &inventory, &itemManager, &time), resources(new Resource[TOTAL_ITEM_COUNT]), time(application, DateTime(2023, 0, 0, 0, 0, 0))
{
	instance = this;

	// Load data
	if (!saveAndLoad.Load(&data))
	{
		// Input player name
		InputField playerNameInputField = InputField("What's your name?", Vector2(application->GetWidth() >> 1, (application->GetHeight() >> 1) - 5), 1, 10, Util::Color::DarkGrey);

		playerNameInputField.Draw();

		String name = String(String::empty);

		playerNameInputField.Input(&name);

		player.SetName(name);

		playerNameInputField.Clear();
	}

	// Initialize resources
	const char* resourceSprites = "_@,";

	for (int i = 0; i < TOTAL_ITEM_COUNT; i++)
	{
		resources[i].Setup(&screen, &player, resourceSprites[i], Vector2(5.0f + i * 2.0f, 4.0f), itemManager.GetItemByIndex(i, (i + 1) * 2));
		resources[i].Draw();
	}

	// Register exit event
	if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, 1))
	{
		exit(0);
	}

	// Draw basic ui settings
	Util::SetColor(Util::Color::Grey);

	for (int i = 0; i < application->GetWidth(); i++)
	{
		Util::Gotoxy(i, screen.GetTop() - 1);

		std::cout << "-";
	}

	for (int i = 0; i < 3; i++)
	{
		Util::Gotoxy(70, i);

		std::cout << "|";
	}

	Util::Gotoxy(70, 3);

	std::cout << "+";

	// Draw player
	player.Draw();

	// Draw UI
	inventory.DrawIcon();
}

GameManager::~GameManager()
{

}

void GameManager::Update(float deltaTime)
{
	if (inventory.IsShow())
	{
		inventory.ItemListLoop();
	}
	else
	{
		// Deactivate after acquiring a resource on the map
		for (int i = 0; i < TOTAL_ITEM_COUNT; i++)
		{
			if (!resources[i].GetActive())
			{
				continue;
			}

			if (resources[i].CheckCollisionToPlayer())
			{
				inventory.Add(resources[i].GetItem());
				resources[i].SetActive(false);

				continue;
			}

			resources[i].Draw();
		}

		player.Movement(deltaTime);

		if (Util::GetKeyDown(Util::KeyCode::I) || Util::GetKeyDown(Util::KeyCode::i))
		{
			inventory.DrawItemList();
		}
	}

	player.UpdateStatus(deltaTime);
	time.Update();
	time.Draw();
}

void GameManager::ExitEvent()
{
	system("cls");

	saveAndLoad.Save(&data);

	// Deletes
	if (resources != nullptr)
	{
		delete[] resources;
	}

	// Draw saving message
	Util::SetColor(Util::Color::DarkSky);

	String savingStr = String("Saving.");

	for (int i = 0; i < 3; i++, savingStr.Append("."))
	{
		Util::Gotoxy((application->GetWidth() >> 1) - (savingStr.GetLength() >> 1), application->GetHeight() >> 1);

		std::cout << savingStr.GetData();

		Util::Wait(200);
	}
}