#include <iostream>
#include <cstring>
#include "String.h"
#include "Math.h"

const String String::empty = "";

String::String() : data(nullptr), length(0)
{

}

String::String(char c)
{
	length = 1;

	data = new char[2];

	data[0] = c;
}

String::String(const char* str)
{
	length = strlen(str);

	data = new char[length + 1];

	strcpy_s(data, length + 1, str);
}

String::String(const String& str)
{
	length = str.length;

	data = new char[length + 1];

	strcpy_s(data, length + 1, str.data);
}

String::~String()
{
	if (data != nullptr)
	{
		delete[] data;
	}
}

bool String::Equals(const char* str) const
{
	return strcmp(data, str) == 0;
}

bool String::Equals(const String& str) const
{
	return strcmp(data, str.data) == 0;
}

String& String::Set(char c)
{
	length = 1;

	if (data != nullptr)
	{
		delete[] data;
	}

	data = new char[2];

	data[0] = c;

	return *this;
}

String& String::Set(const char* str)
{
	length = strlen(str);

	if (data != nullptr)
	{
		delete[] data;
	}

	data = new char[length + 1];

	strcpy_s(data, length + 1, str);

	return *this;
}

String& String::Set(const String& str)
{
	length = str.length;

	if (data != nullptr)
	{
		delete[] data;
	}

	data = new char[length + 1];

	strcpy_s(data, length + 1, str.data);

	return *this;
}

String& String::Append(int i)
{
	int value = i;
	int tempLength;
	char* tempValue;

	if (value == 0)
	{
		tempLength = 1;
	}
	else
	{
		for (tempLength = 0; value; tempLength++)
		{
			value = Math::DivideEx(value, 10);
		}
	}

	tempValue = new char[tempLength + 1];

	sprintf_s(tempValue, tempLength + 1, "%d", i);

	length += tempLength;

	String temp = data;

	if (data != nullptr)
	{
		delete[] data;
	}

	data = new char[length + 1];

	strcpy_s(data, length + 1, temp.data);
	strcat_s(data, length + 1, tempValue);

	delete[] tempValue;

	return *this;
}

String& String::Append(unsigned int uint)
{
	unsigned int value = uint;
	int tempLength;
	char* tempValue;

	if (value == 0)
	{
		tempLength = 1;
	}
	else
	{
		for (tempLength = 0; value; tempLength++)
		{
			value = Math::DivideEx(value, 10);
		}
	}

	tempValue = new char[tempLength + 1];

	sprintf_s(tempValue, tempLength + 1, "%d", uint);

	length += tempLength;

	String temp = data;

	if (data != nullptr)
	{
		delete[] data;
	}

	data = new char[length + 1];

	strcpy_s(data, length + 1, temp.data);
	strcat_s(data, length + 1, tempValue);

	delete[] tempValue;

	return *this;
}

String& String::Append(char c)
{
	length++;

	String temp = data;

	if (data != nullptr)
	{
		delete[] data;
	}

	data = new char[length + 1];

	strcpy_s(data, length + 1, temp.data);

	data[length - 1] = c;
	data[length] = '\0';

	return *this;
}

String& String::Append(const char* str)
{
	length += strlen(str);

	String temp = data;

	if (data != nullptr)
	{
		delete[] data;
	}

	data = new char[length + 1];

	strcpy_s(data, length + 1, temp.data);
	strcat_s(data, length + 1, str);

	return *this;
}

String& String::Append(const String& str)
{
	length += str.length;

	String temp = data;

	if (data != nullptr)
	{
		delete[] data;
	}

	data = new char[length + 1];

	strcpy_s(data, length + 1, temp.data);
	strcat_s(data, length + 1, str.data);

	return *this;
}

String& String::Clear()
{
	length = 0;

	if (data != nullptr)
	{
		delete[] data;
	}

	return *this;
}

const String& String::operator + (char c)
{
	String result = data;

	result.Append(c);

	return result;
}

const String& String::operator + (const char* str)
{
	String result = data;

	result.Append(str);

	return result;
}

const String& String::operator + (const String& str)
{
	String result = data;

	result.Append(str);

	return result;
}

String& String::operator += (int i)
{
	Append(i);

	return *this;
}

String& String::operator += (unsigned int uint)
{
	Append(uint);

	return *this;
}

String& String::operator += (char c)
{
	Append(c);

	return *this;
}

String& String::operator += (const char* str)
{
	Append(str);

	return *this;
}

String& String::operator += (const String& str)
{
	Append(str);

	return *this;
}

String& String::operator = (char c)
{
	length = 1;

	if (data != nullptr)
	{
		delete[] data;
	}

	data = new char[2];

	data[0] = c;

	return *this;
}

String& String::operator = (const char* str)
{
	length = strlen(str);

	if (data != nullptr)
	{
		delete[] data;
	}

	data = new char[length + 1];

	strcpy_s(data, length + 1, str);

	return *this;
}

String& String::operator = (const String& str)
{
	length = str.length;

	if (data != nullptr)
	{
		delete[] data;
	}

	data = new char[length + 1];

	strcpy_s(data, length + 1, str.data);

	return *this;
}

bool String::operator == (const char* str)
{
	return strcmp(data, str) == 0;
}

bool String::operator == (const String& str)
{
	return strcmp(data, str.data) == 0;
}

bool String::operator != (const char* str)
{
	return strcmp(data, str) != 0;
}

bool String::operator != (const String& str)
{
	return strcmp(data, str.data) != 0;
}