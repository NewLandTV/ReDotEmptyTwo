#include "Vector2.h"

const Vector2 Vector2::zero = Vector2(0.0f, 0.0f);
const Vector2 Vector2::one = Vector2(1.0f, 1.0f);
const Vector2 Vector2::right = Vector2(1.0f, 0.0f);
const Vector2 Vector2::left = Vector2(-1.0f, 0.0f);
const Vector2 Vector2::up = Vector2(0.0f, 1.0f);
const Vector2 Vector2::down = Vector2(0.0f, -1.0f);

Vector2::Vector2() : x(0), y(0)
{

}

Vector2::Vector2(float x, float y) : x(x), y(y)
{

}

Vector2::~Vector2()
{

}

Vector2& Vector2::Set(float x, float y)
{
	this->x = x;
	this->y = y;

	return *this;
}

Vector2& Vector2::Set(const Vector2& vector2)
{
	x = vector2.x;
	y = vector2.y;

	return *this;
}

Vector2& Vector2::SetX(float x)
{
	this->x = x;

	return *this;
}

Vector2& Vector2::SetY(float y)
{
	this->y = y;

	return *this;
}

bool Vector2::Equals(float x, float y)
{
	return this ->x == x && this->y == y;
}

bool Vector2::Equals(const Vector2& vector2)
{
	return x == vector2.x && y == vector2.y;
}

bool Vector2::operator == (const Vector2& vector2)
{
	return Equals(vector2);
}

bool Vector2::operator != (const Vector2& vector2)
{
	return !Equals(vector2);
}