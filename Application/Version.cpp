#include <cstring>
#include <cstdlib>
#include "Version.h"

Version::Version() : major(0), minor(0), build(0)
{

}

Version::Version(unsigned int major, unsigned minor, unsigned build) : major(major), minor(minor), build(build)
{

}

Version::Version(const Version& version) : major(version.major), minor(version.minor), build(version.build)
{

}

Version::~Version()
{

}

String Version::ToString() const
{
	return String(String::empty).Append(major).Append('.').Append(minor).Append('.').Append(build);
}

Version& Version::Set(unsigned int major, unsigned int minor, unsigned int build)
{
	this->major = major;
	this->minor = minor;
	this->build = build;

	return *this;
}

Version& Version::Set(char* str)
{
	char* context = nullptr;
	char* ptr = strtok_s(str, ".", &context);

	major = atoi(ptr);

	ptr = strtok_s(nullptr, ".", &context);

	minor = atoi(ptr);

	ptr = strtok_s(nullptr, ".", &context);

	build = atoi(ptr);

	return *this;
}

Version& Version::Set(const String& str)
{
	char* context = nullptr;
	char* ptr = strtok_s(str.GetData(), ".", &context);

	major = atoi(ptr);

	ptr = strtok_s(nullptr, ".", &context);

	minor = atoi(ptr);

	ptr = strtok_s(nullptr, ".", &context);

	build = atoi(ptr);

	return *this;
}

Version& Version::Set(const Version& version)
{
	major = version.major;
	minor = version.minor;
	build = version.build;

	return *this;
}

bool Version::Equals(unsigned int major, unsigned int minor, unsigned int build) const
{
	return this->major == major && this->minor == minor && this->build == build;
}

bool Version::Equals(char* str)
{
	char* context = nullptr;
	char* ptr = strtok_s(str, ".", &context);

	if (major != atoi(ptr))
	{
		return false;
	}

	ptr = strtok_s(nullptr, ".", &context);

	if (minor != atoi(ptr))
	{
		return false;
	}

	ptr = strtok_s(nullptr, ".", &context);

	return build == atoi(ptr);
}

bool Version::Equals(const String& str)
{
	char* context = nullptr;
	char* ptr = strtok_s(str.GetData(), ".", &context);

	if (major != atoi(ptr))
	{
		return false;
	}

	ptr = strtok_s(nullptr, ".", &context);

	if (minor != atoi(ptr))
	{
		return false;
	}

	ptr = strtok_s(nullptr, ".", &context);

	return build == atoi(ptr);
}

bool Version::Equals(const Version& version) const
{
	return major == version.major && minor == version.minor && build == version.build;
}

Version& Version::operator = (char* str)
{
	Set(str);

	return *this;
}

Version& Version::operator = (const String& str)
{
	Set(str);

	return *this;
}

Version& Version::operator = (const Version& version)
{
	Set(version);

	return *this;
}

bool Version::operator == (char* str)
{
	return Equals(str);
}

bool Version::operator == (const String& str)
{
	return Equals(str);
}

bool Version::operator == (const Version& version)
{
	return major == version.major && minor == version.minor && build == version.build;
}

bool Version::operator != (char* str)
{
	return !Equals(str);
}

bool Version::operator != (const String& str)
{
	return !Equals(str);
}