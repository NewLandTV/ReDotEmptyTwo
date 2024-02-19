#include "WorldObject.h"

WorldObject::WorldObject() : position(0, 0), active(true)
{

}

WorldObject::WorldObject(const Vector2& position) : position(position), active(true)
{

}

WorldObject::WorldObject(const Vector2& position, bool active) : position(position), active(active)
{

}

WorldObject::~WorldObject()
{

}

void WorldObject::SetPosition(Vector2 position)
{
	this->position = position;
}

void WorldObject::SetActive(bool active)
{
	this->active = active;
}