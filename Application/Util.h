#ifndef __UTIL_H__
#define __UTIL_H__

namespace Util
{
	enum class KeyCode
	{
		LeftArrow = 0x25,
		UpArrow = 0x26,
		RightArrow = 0x27,
		DownArrow = 0x28,
		Enter = 13,
		Esc = 27,
		Space = 32,
		Alpha0 = 48,
		Alpha1 = 49,
		Alpha2 = 50,
		Alpha3 = 51,
		Alpha4 = 52,
		Alpha5 = 53,
		Alpha6 = 54,
		Alpha7 = 55,
		Alpha8 = 56,
		Alpha9 = 57,
		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,
		a = 97,
		b = 98,
		c = 99,
		d = 100,
		e = 101,
		f = 102,
		g = 103,
		h = 104,
		i = 105,
		j = 106,
		k = 107,
		l = 108,
		m = 109,
		n = 110,
		o = 111,
		p = 112,
		q = 113,
		r = 114,
		s = 115,
		t = 116,
		u = 117,
		v = 118,
		w = 119,
		x = 120,
		y = 121,
		z = 122
	};

	enum class Color
	{
		Black = 0,
		DarkBlue = 1,
		DarkGreen = 2,
		DarkSky = 3,
		DarkRed = 4,
		DarkPurple = 5,
		DarkYellow = 6,
		Grey = 7,
		DarkGrey = 8,
		Blue = 9,
		Green = 10,
		Sky = 11,
		Red = 12,
		Purple = 13,
		Yellow = 14,
		White = 15
	};

	void Gotoxy(short x, short y);
	int Input();
	bool GetKeyDown(KeyCode keyCode);
	void Wait(unsigned long long milliseconds);
	void SetColor(Color color);
}

#endif