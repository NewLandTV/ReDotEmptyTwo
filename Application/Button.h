#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "String.h"
#include "Vector2.h"
#include "Util.h"

class Button
{
private:
	String text;
	Vector2 position;
	Vector2 scale;
	Util::Color color;
	
public:
	Button(const String& text, const Vector2& position, const Vector2& scale, Util::Color color);
	~Button();

	const Vector2& GetPosition() const { return position; }
	const Vector2& GetScale() const { return scale; }
	void Draw();
};

#endif