#ifndef __INPUTFIEND_H__
#define __INPUTFIEND_H__

#include "String.h"
#include "Vector2.h"
#include "Util.h"

class InputField
{
private:
	String outputMessage;
	Vector2 position;

	unsigned short minInputLength;
	unsigned short maxInputLength;

	Util::Color outputMessageColor;

public:
	InputField(const String outputMessage, const Vector2& position, unsigned short minInputLength, unsigned short maxInputLength, Util::Color outputMessageColor = Util::Color::Grey);
	~InputField();

	const Vector2& GetPosition() const { return position; }
	unsigned short GetMinInputLength() const { return minInputLength; }
	unsigned short GetMaxInputLength() const { return maxInputLength; }
	void Draw();
	void Clear();
	void Input(String* out);
};

#endif