#ifndef __VERSION_H__
#define __VERSION_H__

#include "String.h"

class Version
{
private:
	unsigned int major;
	unsigned int minor;
	unsigned int build;

public:
	Version();
	Version(unsigned int major, unsigned minor, unsigned build);
	Version(const Version& version);
	~Version();

	unsigned int GetMajor() const { return major; }
	unsigned int GetMinor() const { return minor; }
	unsigned int GetBuild() const { return build; }
	String ToString() const;
	Version& Set(unsigned int major, unsigned int minor, unsigned int build);
	Version& Set(char* str);
	Version& Set(const String& str);
	Version& Set(const Version& version);
	bool Equals(unsigned int major, unsigned int minor, unsigned int build) const;
	bool Equals(char* str);
	bool Equals(const String& str);
	bool Equals(const Version& version) const;

	Version& operator = (char* str);
	Version& operator = (const String& str);
	Version& operator = (const Version& version);
	bool operator == (char* str);
	bool operator == (const String& str);
	bool operator == (const Version& version);
	bool operator != (char* str);
	bool operator != (const String& str);
};

#endif