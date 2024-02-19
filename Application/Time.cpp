#include <iostream>
#include "Time.h"
#include "Util.h"

Time::Time(Application* application, DateTime dateTime) : application(application), currentWorldDateTime(dateTime), currentWorldDataTimeToString(String::empty)
{
	Draw();
}

Time::~Time()
{

}

void Time::Update()
{
	currentWorldDataTimeToString.Set(currentWorldDateTime.year).Append("-").Append(currentWorldDateTime.month + 1).Append("-").Append(currentWorldDateTime.day + 1).Append(" ").Append(currentWorldDateTime.hour).Append(":").Append(currentWorldDateTime.minute).Append(":").Append(currentWorldDateTime.second);

	currentWorldDateTime.second++;

	if (currentWorldDateTime.second < 60)
	{
		return;
	}

	currentWorldDateTime.second = 0;
	currentWorldDateTime.minute++;

	if (currentWorldDateTime.minute < 60)
	{
		return;
	}

	currentWorldDateTime.minute = 0;
	currentWorldDateTime.hour++;

	if (currentWorldDateTime.hour < 24)
	{
		return;
	}

	currentWorldDateTime.hour = 0;
	currentWorldDateTime.day++;

	if (currentWorldDateTime.day < 30)
	{
		return;
	}

	currentWorldDateTime.day = 0;
	currentWorldDateTime.month++;

	if (currentWorldDateTime.month < 12)
	{
		return;
	}

	currentWorldDateTime.month = 0;
	currentWorldDateTime.year++;
}

Time& Time::SetWorldDateTime(DateTime dateTime)
{
	currentWorldDateTime = dateTime;

	return *this;
}

void Time::Draw()
{
	char output[26];

	sprintf_s(output, 26, "%-d-%02d-%02d %02d:%02d:%02d", currentWorldDateTime.year, currentWorldDateTime.month + 1, currentWorldDateTime.day + 1, currentWorldDateTime.hour, currentWorldDateTime.minute, currentWorldDateTime.second);

	Util::Gotoxy(application->GetWidth() - strlen(output) - 2, 1);
	Util::SetColor(Util::Color::Sky);
	
	std::cout << output;
}