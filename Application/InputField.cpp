#include <iostream>
#include "InputField.h"

InputField::InputField(const String outputMessage, const Vector2& position, unsigned short minInputLength, unsigned short maxInputLength, Util::Color outputMessageColor) : outputMessage(outputMessage), position(position), minInputLength(minInputLength), maxInputLength(maxInputLength), outputMessageColor(outputMessageColor)
{
	this->outputMessage.Append(" (").Append(minInputLength).Append(" ~ ").Append(maxInputLength).Append(")");
}

InputField::~InputField()
{

}

void InputField::Draw()
{
	Util::Gotoxy(position.GetX() - (outputMessage.GetLength() >> 1), position.GetY() - 1);
	Util::SetColor(outputMessageColor);

	std::cout << outputMessage.GetData();

	Util::Gotoxy(position.GetX() - (outputMessage.GetLength() >> 1), position.GetY() + 1);

	std::cout << ">";
}

void InputField::Clear()
{
	for (int y = position.GetY() - 1; y <= position.GetY() + 1; y++)
	{
		for (int x = position.GetX() - (outputMessage.GetLength() >> 1); x <= position.GetX() + (outputMessage.GetLength() >> 1); x++)
		{
			Util::Gotoxy(x, y);

			std::cout << " ";
		}
	}
}

void InputField::Input(String* out)
{
	char inputBuffer[1024];

	while (true)
	{
		std::cin >> inputBuffer;

		if (minInputLength <= strlen(inputBuffer) && strlen(inputBuffer) <= maxInputLength)
		{
			out->Set(inputBuffer);

			break;
		}

		memset(inputBuffer, 0, 1024);
		Clear();
		Draw();
	}
}