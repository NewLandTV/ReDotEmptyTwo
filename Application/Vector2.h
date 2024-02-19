#ifndef __VECTOR2_H__
#define __VECTOR2_H__

class Vector2
{
private:
	float x;
	float y;

public:
	static const Vector2 zero;
	static const Vector2 one;
	static const Vector2 right;
	static const Vector2 left;
	static const Vector2 up;
	static const Vector2 down;

	Vector2();
	Vector2(float x, float y);
	~Vector2();

	float GetX() const { return x; }
	float GetY() const { return y; }
	Vector2& Set(float x, float y);
	Vector2& Set(const Vector2& vector2);
	Vector2& SetX(float x);
	Vector2& SetY(float y);
	bool Equals(float x, float y);
	bool Equals(const Vector2& vector2);

	bool operator == (const Vector2& vector2);
	bool operator != (const Vector2& vector2);
};

#endif