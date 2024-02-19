#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "Vector2.h"

class Screen
{
private:
	Vector2 leftTop;
	Vector2 rightBottom;

public:
	Screen(Vector2 leftTop, Vector2 rightBottom);
	~Screen();

	unsigned short GetLeft() { return leftTop.GetX(); }
	unsigned short GetRight() { return rightBottom.GetX(); }
	unsigned short GetTop() { return leftTop.GetY(); }
	unsigned short GetBottom() { return rightBottom.GetY(); }
};

#endif