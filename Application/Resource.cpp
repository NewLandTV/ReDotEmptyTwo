#include <iostream>
#include "Resource.h"
#include "Util.h"

Resource::Resource() : screen(nullptr), player(nullptr), sprite(), WorldObject(), item()
{

}

Resource::Resource(Screen* screen, Player* player, char sprite, const Vector2& position, const Item& item) : screen(screen), player(player), sprite(sprite), WorldObject(position), item(item)
{

}

Resource::~Resource()
{

}

void Resource::SetSprite(char sprite)
{
	this->sprite = sprite;
}

void Resource::SetItem(const Item& item)
{
	this->item.Set(item);
}

void Resource::Setup(Screen* screen, Player* player, char sprite, const Vector2& position, const Item& item)
{
	this->screen = screen;
	this->player = player;
	this->sprite = sprite;

	this->position.Set(position);
	this->item.Set(item);
}

void Resource::Draw()
{
	Util::Gotoxy(Math::FloorToInt(position.GetX() + screen->GetLeft()), Math::FloorToInt(position.GetY() + screen->GetTop()));
	Util::SetColor(Util::Color::DarkSky);

	std::cout << sprite;
}