#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include "WorldObject.h"
#include "Screen.h"
#include "Player.h"
#include "Vector2.h"
#include "Item.h"
#include "Math.h"

class Resource : public WorldObject
{
private:
	Screen* screen;
	Player* player;

	char sprite;
	Item item;

public:
	Resource();
	Resource(Screen* screen, Player* player, char sprite, const Vector2& position, const Item& item);
	~Resource();

	// Getters
	char GetSprite() const { return sprite; }
	const Item& GetItem() const { return item; }

	// Setters
	void SetSprite(char sprite);
	void SetItem(const Item& item);

	void Setup(Screen* screen, Player* player, char sprite, const Vector2& position, const Item& item);

	// Render
	void Draw();

	// Logics
	bool CheckCollisionToPlayer() { return Math::FloorToInt(player->GetPosition()->GetX()) == Math::FloorToInt(position.GetX()) && Math::FloorToInt(player->GetPosition()->GetY()) == Math::FloorToInt(position.GetY()); }
};

#endif