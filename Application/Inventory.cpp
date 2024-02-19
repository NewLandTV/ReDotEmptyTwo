#include <iostream>
#include "Inventory.h"
#include "Util.h"

void Inventory::DrawItemDetails(unsigned short index)
{
	// Clear previously displayed details
	Util::SetColor(Util::Color::Grey);

	for (int y = screen->GetTop() + 3; y < screen->GetTop() + 6; y++)
	{
		for (int x = application->GetWidth() - 60; x < application->GetWidth() - 5; x++)
		{
			Util::Gotoxy(x, y);

			std::cout << "~";
		}
	}

	// Show items[index]'s details
	Util::SetColor(Util::Color::DarkGreen);
	Util::Gotoxy(application->GetWidth() - 60, screen->GetTop() + 3);

	std::cout << "Name : " << items[index].GetName().GetData();

	Util::Gotoxy(application->GetWidth() - 60, screen->GetTop() + 4);

	std::cout << "Count : " << items[index].GetCount();

	Util::Gotoxy(application->GetWidth() - 60, screen->GetTop() + 5);

	std::cout << "Description : " << items[index].GetDescription().GetData();
}

Inventory::Inventory(Application* application, Screen* screen, Player* player, ItemManager* itemManager, unsigned short slotCount) : application(application), screen(screen), player(player), items(new Item[slotCount]), itemManager(itemManager), closeButton("Close", Vector2(application->GetWidth() >> 1, application->GetHeight() - 5.0f), Vector2(9.0f, 3.0f), Util::Color::White), itemListMoveCursor(1, '~', Util::Color::DarkBlue, Util::Color::Grey), slotCount(slotCount), totalItems(0), select(1), isShow(false)
{
	itemListMoveCursor.SetPositionByIndex(0, Vector2(closeButton.GetPosition().GetX() - 6.0f, closeButton.GetPosition().GetY()));
}

Inventory::~Inventory()
{
	if (items != nullptr)
	{
		delete[] items;
	}
}

Inventory& Inventory::Add(const Item& item)
{
	for (int i = 0; i < slotCount; i++)
	{
		if (items[i].GetCount() == 0)
		{
			totalItems++;

			DrawIcon();

			items[i].Set(item.GetName(), item.GetDescription(), item.GetCount());
			itemListMoveCursor.ChangePositionsCount(totalItems + 1);

			for (int j = 0; j < totalItems; j++)
			{
				itemListMoveCursor.SetPositionByIndex(j, Vector2(5.0f, screen->GetTop() + 3.0f + j * 2.0f));
			}

			itemListMoveCursor.SetPositionByIndex(itemListMoveCursor.GetPositionsCount() - 1, Vector2(closeButton.GetPosition().GetX() - 6.0f, closeButton.GetPosition().GetY()));

			if (isShow)
			{
				DrawItemList();
			}

			return *this;
		}
		else if (items[i].GetName().Equals(item.GetName()))
		{
			items[i].SetCount(items[i].GetCount() + item.GetCount());

			if (isShow)
			{
				DrawItemList();
			}

			return *this;
		}
	}

	return *this;
}

Inventory& Inventory::Add(unsigned int itemIndex)
{
	return Add(itemManager->GetItemByIndex(itemIndex));
}

const Item* Inventory::GetItem(unsigned int index)
{
	return index < slotCount ? &items[index] : nullptr;
}

const Item* Inventory::GetItem(const String& itemName)
{
	for (int i = 0; i < slotCount; i++)
	{
		if (items[i].GetName().Equals(itemName))
		{
			return &items[i];
		}
	}

	return nullptr;
}

void Inventory::DrawIcon()
{
	Util::Gotoxy(72, 0);
	Util::SetColor(Util::Color::Yellow);

	std::cout << "Inventory";

	Util::Gotoxy(75, 1);

	std::cout << "(I)";

	String totalItemCountStr = String(String::empty).Append(totalItems).Append("/").Append(slotCount);

	Util::Gotoxy(76 - (totalItemCountStr.GetLength() >> 1), 2);

	std::cout << totalItemCountStr.GetData();
}

void Inventory::DrawItemList()
{
	isShow = true;
	select = 0;

	itemListMoveCursor.SetCursorIndex(0);

	// Top
	Util::Gotoxy(2, screen->GetTop() + 1);
	Util::SetColor(Util::Color::DarkGrey);

	std::cout << "+";

	Util::Gotoxy(application->GetWidth() - 3, screen->GetTop() + 1);

	std::cout << "+";

	for (int i = 3; i < application->GetWidth() - 3; i++)
	{
		Util::Gotoxy(i, screen->GetTop() + 1);

		std::cout << "-";
	}

	// Bottom
	Util::Gotoxy(2, application->GetHeight() - 2);

	std::cout << "+";

	Util::Gotoxy(application->GetWidth() - 3, application->GetHeight() - 2);

	std::cout << "+";

	for (int i = 3; i < application->GetWidth() - 3; i++)
	{
		Util::Gotoxy(i, application->GetHeight() - 2);

		std::cout << "-";
	}

	// Left, Right border
	for (int i = screen->GetTop() + 2; i < application->GetHeight() - 2; i++)
	{
		Util::Gotoxy(2, i);

		std::cout << "|";

		Util::Gotoxy(application->GetWidth() - 3, i);

		std::cout << "|";
	}
	
	// Fill empty (center)
	Util::SetColor(Util::Color::Grey);

	for (int y = screen->GetTop() + 2; y < application->GetHeight() - 2; y++)
	{
		for (int x = 3; x < application->GetWidth() - 3; x++)
		{
			Util::Gotoxy(x, y);

			std::cout << "~";
		}
	}

	// Show item list (center)
	Util::SetColor(Util::Color::DarkGreen);

	for (int i = 0; i < totalItems; i++)
	{
		if (items[i].GetCount() > 0)
		{
			Util::Gotoxy(7, screen->GetTop() + 3 + i * 2);

			std::cout << items[i].GetName().GetData() << " * " << items[i].GetCount();
		}
	}

	closeButton.Draw();
	itemListMoveCursor.ShowPosition(0);
}

void Inventory::ItemListLoop()
{
	short temp = itemListMoveCursor.Loop();

	if (temp == -5)
	{
		if (select == itemListMoveCursor.GetPositionsCount() - 1)
		{
			HideItemList();

			return;
		}

		DrawItemDetails(select);
	}
	else if (temp != -1)
	{
		select = temp;
	}
}

void Inventory::HideItemList()
{
	for (int y = screen->GetTop() + 1; y < application->GetHeight() - 1; y++)
	{
		for (int x = 2; x < application->GetWidth() - 2; x++)
		{
			Util::Gotoxy(x, y);

			std::cout << " ";
		}
	}

	player->Draw();

	isShow = false;
}

void Inventory::Clear()
{
	totalItems = 0;

	for (int i = 0; i < slotCount; i++)
	{
		items[i].Set(Item(String::empty, String::empty, 0));
	}

	itemListMoveCursor.ChangePositionsCount(1).SetPositionByIndex(0, Vector2(closeButton.GetPosition().GetX() - 6.0f, closeButton.GetPosition().GetY()));

	if (isShow)
	{
		DrawItemList();
	}
}

Inventory& Inventory::SetSlotCount(unsigned short slotCount)
{
	unsigned int* itemIndexArray = new unsigned int[totalItems];

	for (int i = 0; i < totalItems; i++)
	{
		itemIndexArray[i] = itemManager->GetIndexByItem(items[i]);
	}

	Clear();

	this->slotCount = slotCount;

	if (items != nullptr)
	{
		delete[] items;
	}

	items = new Item[slotCount];

	if (slotCount < totalItems)
	{
		totalItems = slotCount;
	}

	for (int i = 0; i < totalItems; i++)
	{
		Add(itemIndexArray[i]);
	}

	delete[] itemIndexArray;

	return *this;
}