#ifndef __STRING_H__
#define __STRING_H__

class String
{
private:
	char* data;
	unsigned int length;

public:
	static const String empty;

	String();
	String(char c);
	String(const char* str);
	String(const String& str);
	~String();

	char* GetData() const { return data; }
	unsigned int GetLength() const { return length; }
	bool Equals(const char* str) const;
	bool Equals(const String& str) const;
	String& Set(char c);
	String& Set(const char* str);
	String& Set(const String& str);
	String& Append(int i);
	String& Append(unsigned int uint);
	String& Append(unsigned char c);
	String& Append(char c);
	String& Append(const char* str);
	String& Append(const String& str);
	String& Clear();

	const String& operator + (char c);
	const String& operator + (const char* str);
	const String& operator + (const String& str);
	String& operator += (int i);
	String& operator += (unsigned int uint);
	String& operator += (unsigned char c);
	String& operator += (char c);
	String& operator += (const char* str);
	String& operator += (const String& str);
	String& operator = (char c);
	String& operator = (const char* str);
	String& operator = (const String& str);
	bool operator == (const char* str);
	bool operator == (const String& str);
	bool operator != (const char* str);
	bool operator != (const String& str);
};

#endif