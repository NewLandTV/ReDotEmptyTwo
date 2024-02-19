#include "Item.h"

Item::Item() : name(String::empty), description(String::empty), count(0)
{

}

Item::Item(const String& name, const String& description) : name(name), description(description), count(0)
{

}

Item::Item(const String& name, const String& description, unsigned int count) : name(name), description(description), count(count)
{

}

Item::Item(const Item& item) : name(item.name), description(item.description), count(item.count)
{

}

Item::~Item()
{

}

Item& Item::Set(const String& name, const String& description, unsigned int count)
{
	this->name = name;
	this->description = description;
	this->count = count;

	return *this;
}

Item& Item::Set(const Item& item)
{
	name = item.name;
	description = item.description;
	count = item.count;

	return *this;
}

Item& Item::SetName(const String& name)
{
	this->name = name;

	return *this;
}

Item& Item::SetDescription(const String& description)
{
	this->description = description;

	return *this;
}

Item& Item::SetCount(unsigned int count)
{
	this->count = count;

	return *this;
}