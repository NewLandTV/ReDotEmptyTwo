#ifndef __WORLDOBJECT_H__
#define __WORLDOBJECT_H__

#include "Vector2.h"

class WorldObject
{
protected:
	Vector2 position;
	bool active;

public:
	WorldObject();
	WorldObject(const Vector2& position);
	WorldObject(const Vector2& position, bool active);
	~WorldObject();

	Vector2* GetPosition() { return &position; }
	bool GetActive() { return active; }
	void SetPosition(Vector2 position);
	void SetActive(bool active);
};

#endif