#include <conio.h>
#include <Windows.h>
#include "Util.h"

void Util::Gotoxy(short x, short y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}

int Util::Input()
{
	return _kbhit() ? _getch() : -2;
}

bool Util::GetKeyDown(KeyCode keyCode)
{
	return GetAsyncKeyState((int)keyCode) & 0x8000;
}

void Util::Wait(unsigned long long milliseconds)
{
	MSG message;

	unsigned long long time0 = GetTickCount64();
	unsigned long long time1;
	unsigned long long different;

	while (true)
	{
		time1 = GetTickCount64();

		if (time0 <= time1)
		{
			different = time1 - time0;
		}
		else
		{
			different = 0xffffffffffffffff - time0 + time1;
		}

		if (different > milliseconds)
		{
			break;
		}

		while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);

			DispatchMessage(&message);
		}

		Sleep(1);
	}
}

void Util::SetColor(Color color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (unsigned short)color);
}