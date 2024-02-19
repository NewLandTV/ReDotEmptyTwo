#ifndef __ITEM_H__
#define __ITEM_H__

#include "String.h"

class Item
{
private:
	String name;
	String description;
	unsigned int count;

public:
	Item();
	Item(const String& name, const String& description);
	Item(const String& name, const String& description, unsigned int count);
	Item(const Item& item);
	~Item();

	Item& Set(const String& name, const String& description, unsigned int count);
	Item& Set(const Item& item);

	// Getter
	const String& GetName() const { return name; }
	const String& GetDescription() const { return description; }
	unsigned int GetCount() const { return count; }

	// Setter
	Item& SetName(const String& name);
	Item& SetDescription(const String& description);
	Item& SetCount(unsigned int count);
};

#endif