#include "ItemManager.h"

ItemManager::ItemManager()
{

}

ItemManager::~ItemManager()
{

}

unsigned int ItemManager::GetIndexByItem(const Item& item)
{
	for (int i = 0; i < TOTAL_ITEM_COUNT; i++)
	{
		if (items[i].GetName().Equals(item.GetName()))
		{
			return i;
		}
	}

	return INVALID_ITEM_INDEX;
}