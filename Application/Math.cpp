#include "Math.h"

int Math::DivideEx(int a, int b)
{
	int temp = 1;
	int result = 0;

	while (b <= a)
	{
		b <<= 1;
		temp <<= 1;
	}

	while (temp > 1)
	{
		b >>= 1;
		temp >>= 1;

		if (a >= b)
		{
			a -= b;
			result += temp;
		}
	}

	return result;
}

int Math::FloorToInt(float value)
{
	return (int)value;
}

int Math::RoundToInt(float value)
{
	return (int)value + (value >= 0 ? 0.5f : -0.5f);
}