#ifndef __DATA_H__
#define __DATA_H__

#include "Player.h"
#include "Inventory.h"
#include "Time.h"

class Data
{
private:
	Player* player;
	Inventory* inventory;
	ItemManager* itemManager;
	Time* time;

public:
	Data(Player* player, Inventory* inventory, ItemManager* itemManager, Time* time);
	~Data();

	// Getters
	const Vector2* GetPlayerPosition() const { return player->GetPosition(); }
	const unsigned int GetPlayerCurrentLevel() const { return player->GetCurrentLevel(); }
	const unsigned int GetPlayerMaxLevel() const { return player->GetMaxLevel(); }
	const unsigned int GetPlayerCurrentHealth() const { return player->GetCurrentHealth(); }
	const unsigned int GetPlayerMaxHealth() const { return player->GetMaxHealth(); }
	const unsigned int GetPlayerCurrentHungry() const { return player->GetCurrentHungry(); }
	const unsigned int GetPlayerMaxHungry() const { return player->GetMaxHungry(); }
	const unsigned int GetPlayerCurrentThirst() const { return player->GetCurrentThirst(); }
	const unsigned int GetPlayerMaxThirst() const { return player->GetMaxThirst(); }
	const String& GetPlayerName() const { return player->GetName(); }

	const unsigned short GetInventoryTotalItems() const { return inventory->GetTotalItems(); }
	const unsigned int GetInventoryItemIndexByIndex(unsigned int index) const { return itemManager->GetIndexByItem(*inventory->GetItem(index)); }
	const unsigned int GetInventoryItemCountByIndex(unsigned int index) const { return inventory->GetItem(index)->GetCount(); }

	const String& GetTimeToString() const { return time->GetCurrentWorldDateTimeToString(); }

	// Setters
	void SetPlayerPosition(const Vector2& position) { player->SetPosition(position); }
	void SetPlayerCurrentLevel(unsigned int currentLevel) { player->SetCurrentLevel(currentLevel, false); }
	void SetPlayerMaxLevel(unsigned int maxLevel) { player->SetMaxLevel(maxLevel, false); }
	void SetPlayerCurrentHealth(unsigned int currentHealth) { player->SetCurrentHealth(currentHealth, false); }
	void SetPlayerMaxHealth(unsigned int maxHealth) { player->SetMaxHealth(maxHealth, false); }
	void SetPlayerCurrentHungry(unsigned int currentHungry) { player->SetCurrentHungry(currentHungry, false); }
	void SetPlayerMaxHungry(unsigned int maxHungry) { player->SetMaxHungry(maxHungry, false); }
	void SetPlayerCurrentThirst(unsigned int currentThirst) { player->SetCurrentThirst(currentThirst, false); }
	void SetPlayerMaxThirst(unsigned int maxThirst) { player->SetMaxThirst(maxThirst, false); }
	void SetPlayerName(const String& name) { player->SetName(name); }

	void SetInventorySlotCount(unsigned short slotCount) { inventory->SetSlotCount(slotCount); }
	void AddItemByItemIndex(unsigned int itemIndex, unsigned int itemCount) { inventory->Add(itemManager->GetItemByIndex(itemIndex, itemCount)); }

	void SetTime(DateTime dateTime) { time->SetWorldDateTime(dateTime); }
};

#endif