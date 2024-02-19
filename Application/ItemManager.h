#ifndef __ITEMMANAGER_H__
#define __ITEMMANAGER_H__

#include "Item.h"

#define TOTAL_ITEM_COUNT 3
#define INVALID_ITEM_INDEX (TOTAL_ITEM_COUNT + 1)

class ItemManager
{
private:
	Item items[TOTAL_ITEM_COUNT] =
	{
		Item("Wood", "The basic resource for making items.", 1),
		Item("Stone", "The basic resource for making items.", 1),
		Item("Seed", "It's an important resource for farm.", 1)
	};

public:
	ItemManager();
	~ItemManager();

	unsigned int GetIndexByItem(const Item& item);
	const Item& GetItemByIndex(unsigned int index, unsigned int count = 1) { return items[index].SetCount(count); }
};

#endif