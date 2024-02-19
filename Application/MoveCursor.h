#ifndef __MOVECURSOR_H__
#define __MOVECURSOR_H__

#include "Vector2.h"
#include "Util.h"

class MoveCursor
{
private:
	Vector2* positionsByIndex;

	unsigned short positionsCount;
	unsigned short cursorIndex;

	char clearBackgroundChar;

	Util::Color cursorColor;
	Util::Color backgroundColor;

public:
	MoveCursor(unsigned short positionsCount, char clearBackgroundChar = ' ', Util::Color cursorColor = Util::Color::Grey, Util::Color backgroundColor = Util::Color::Grey);
	~MoveCursor();

	MoveCursor& ChangePositionsCount(unsigned short positionsCount);
	MoveCursor& SetPositionByIndex(unsigned short index, const Vector2& position);
	MoveCursor& ShowPosition(unsigned short index);
	MoveCursor& SetCursorIndex(unsigned short cursorIndex);
	unsigned short GetPositionsCount() const { return positionsCount; }
	short Loop();
};

#endif