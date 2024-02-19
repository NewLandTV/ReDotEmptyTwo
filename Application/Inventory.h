#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "Application.h"
#include "Screen.h"
#include "Player.h"
#include "Item.h"
#include "ItemManager.h"
#include "Button.h"
#include "MoveCursor.h"

class Inventory
{
private:
	Application* application;
	Screen* screen;
	Player* player;
	Item* items;
	ItemManager* itemManager;
	Button closeButton;
	MoveCursor itemListMoveCursor;

	unsigned short slotCount;
	unsigned short totalItems;
	unsigned short select;

	bool isShow;

	void DrawItemDetails(unsigned short index);

public:
	Inventory(Application* application, Screen* screen, Player* player, ItemManager* itemManager, unsigned short slotCount);
	~Inventory();

	Inventory& Add(const Item& item);
	Inventory& Add(unsigned int itemIndex);

	// GetItem
	const Item* GetItem(unsigned int index);
	const Item* GetItem(const String& itemName);

	void DrawIcon();
	void DrawItemList();
	void ItemListLoop();
	void HideItemList();
	void Clear();

	// Getters
	unsigned short GetSlotCount() const { return slotCount; }
	unsigned short GetTotalItems() const { return totalItems; }
	bool IsShow() const { return isShow; }

	// Setters
	Inventory& SetSlotCount(unsigned short slotCount);
};

#endif