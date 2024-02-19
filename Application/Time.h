#ifndef __TIME_H__
#define __TIME_H__

#include "Application.h"
#include "String.h"

struct DateTime
{
	unsigned int year;
	unsigned char month;
	unsigned char day;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;

	DateTime(unsigned int year, unsigned char month, unsigned char day, unsigned char hour, unsigned char minute, unsigned char second) : year(year), month(month), day(day), hour(hour), minute(minute), second(second)
	{

	}
};

class Time
{
private:
	Application* application;
	DateTime currentWorldDateTime;
	String currentWorldDataTimeToString;

public:
	Time(Application* application, DateTime dateTime);
	~Time();

	void Update();

	// World != Real (e.g y-m-d h:m:s)
	const String& GetCurrentWorldDateTimeToString() const { return currentWorldDataTimeToString; }

	Time& SetWorldDateTime(DateTime dateTime);

	// Render
	void Draw();
};

#endif