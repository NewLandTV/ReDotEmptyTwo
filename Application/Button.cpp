#include <iostream>
#include "Button.h"
#include "Util.h"
#include "Math.h"

Button::Button(const String& text, const Vector2& position, const Vector2& scale, Util::Color color) : text(text), position(position), scale(scale), color(color)
{

}

Button::~Button()
{

}

void Button::Draw()
{
	Util::SetColor(color);

	for (int y = 0; y < scale.GetY(); y++)
	{
		for (int x = 0; x < scale.GetX(); x++)
		{
			Util::Gotoxy(position.GetX() - (Math::FloorToInt(scale.GetX()) >> 1) + x, position.GetY() - (Math::FloorToInt(scale.GetY()) >> 1) + y);

			std::cout << "+";
		}
	}

	Util::Gotoxy(position.GetX() - (text.GetLength() >> 1), position.GetY());

	std::cout << text.GetData();
}