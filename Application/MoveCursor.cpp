#include <iostream>
#include <conio.h>
#include "MoveCursor.h"

MoveCursor::MoveCursor(unsigned short positionsCount, char clearBackgroundChar, Util::Color cursorColor, Util::Color backgroundColor) : positionsByIndex(new Vector2[positionsCount]), positionsCount(positionsCount), cursorIndex(0), clearBackgroundChar(clearBackgroundChar), cursorColor(cursorColor), backgroundColor(backgroundColor)
{

}

MoveCursor::~MoveCursor()
{
	if (positionsByIndex != nullptr)
	{
		delete[] positionsByIndex;
	}
}

MoveCursor& MoveCursor::ChangePositionsCount(unsigned short positionsCount)
{
	if (positionsByIndex != nullptr)
	{
		delete[] positionsByIndex;
	}

	positionsByIndex = new Vector2[positionsCount];

	this->positionsCount = positionsCount;

	if (cursorIndex > positionsCount)
	{
		cursorIndex = positionsCount;
	}

	return *this;
}

MoveCursor& MoveCursor::SetPositionByIndex(unsigned short index, const Vector2& position)
{
	positionsByIndex[index] = position;

	return *this;
}

MoveCursor& MoveCursor::ShowPosition(unsigned short index)
{
	Util::Gotoxy(positionsByIndex[index].GetX(), positionsByIndex[index].GetY());
	Util::SetColor(cursorColor);

	std::cout << ">";

	return *this;
}

MoveCursor& MoveCursor::SetCursorIndex(unsigned short cursorIndex)
{
	this->cursorIndex = cursorIndex;

	return *this;
}

short MoveCursor::Loop()
{
	int key = Util::Input();

	if (key == 13)
	{
		return -5;
	}
	else if (key != 224)
	{
		return -1;
	}

	switch (_getch())
	{
	case 72:
		if (cursorIndex > 0)
		{
			Util::Gotoxy(positionsByIndex[cursorIndex].GetX(), positionsByIndex[cursorIndex].GetY());
			Util::SetColor(backgroundColor);

			std::cout << clearBackgroundChar;

			cursorIndex--;

			Util::Gotoxy(positionsByIndex[cursorIndex].GetX(), positionsByIndex[cursorIndex].GetY());
			Util::SetColor(cursorColor);

			std::cout << ">";
		}

		break;
	case 80:
		if (cursorIndex < positionsCount - 1)
		{
			Util::Gotoxy(positionsByIndex[cursorIndex].GetX(), positionsByIndex[cursorIndex].GetY());
			Util::SetColor(backgroundColor);

			std::cout << clearBackgroundChar;

			cursorIndex++;

			Util::Gotoxy(positionsByIndex[cursorIndex].GetX(), positionsByIndex[cursorIndex].GetY());
			Util::SetColor(cursorColor);

			std::cout << ">";
		}

		break;
	}

	return cursorIndex;
}