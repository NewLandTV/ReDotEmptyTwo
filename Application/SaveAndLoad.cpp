#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <direct.h>
#include "SaveAndLoad.h"
#include "Math.h"

void SaveAndLoad::MakeDataPath()
{
	char buffer[1024];
	char* ptr = buffer;

	strcpy_s(buffer, 1024, savePath.GetData());

	buffer[1023] = '\0';

	while (*ptr)
	{
		if (*ptr == '/')
		{
			*ptr = '\0';

			_mkdir(buffer);

			*ptr = '/';
		}

		ptr++;
	}
}

SaveAndLoad::SaveAndLoad(Application* application) : application(application), savePath(String("C:/NewLand/ReDotEmptyTwo/Datas/").Append(application->GetVersion()->ToString().Append(".rdet")))
{

}

SaveAndLoad::~SaveAndLoad()
{

}

SaveAndLoad& SaveAndLoad::EncodeData(String* data)
{
	for (int i = 0; i < data->GetLength(); i++)
	{
		data->GetData()[i] ^= -1;
	}

	return *this;
}

SaveAndLoad& SaveAndLoad::DecodeData(String* data)
{
	for (int i = 0; i < data->GetLength(); i++)
	{
		data->GetData()[i] ^= -1;
	}

	return *this;
}

bool SaveAndLoad::Save(const Data* data)
{
	FILE* fp;

	fopen_s(&fp, savePath.GetData(), "w");

	if (fp == nullptr)
	{
		MakeDataPath();
		fopen_s(&fp, savePath.GetData(), "w");

		if (fp == nullptr)
		{
			return false;
		}
	}

	// Save datas
	// Player position
	String saveData = String(String::empty).Append(Math::FloorToInt(data->GetPlayerPosition()->GetX())).Append("|").Append(Math::FloorToInt(data->GetPlayerPosition()->GetY()));

	EncodeData(&saveData);
	fprintf(fp, "%s\n", saveData.GetData());

	// Player status
	saveData.Set(String::empty).Append(data->GetPlayerCurrentLevel()).Append("|").Append(data->GetPlayerMaxLevel()).Append("|").Append(data->GetPlayerCurrentHealth()).Append("|").Append(data->GetPlayerMaxHealth()).Append("|").Append(data->GetPlayerCurrentHungry()).Append("|").Append(data->GetPlayerMaxHungry()).Append("|").Append(data->GetPlayerCurrentThirst()).Append("|").Append(data->GetPlayerMaxThirst());

	EncodeData(&saveData);
	fprintf(fp, "%s\n", saveData.GetData());

	// Player name
	saveData = data->GetPlayerName();

	EncodeData(&saveData);
	fprintf(fp, "%s\n", saveData.GetData());

	// Inventory total items
	saveData.Set(String::empty).Append(data->GetInventoryTotalItems()).Append("|");

	EncodeData(&saveData);
	fprintf(fp, "%s\n", saveData.GetData());

	// Inventory items
	saveData.Set(String::empty);

	for (int i = 0; i < data->GetInventoryTotalItems(); i++)
	{
		saveData.Append(data->GetInventoryItemIndexByIndex(i)).Append("|").Append(data->GetInventoryItemCountByIndex(i)).Append("|");
	}

	EncodeData(&saveData);
	fprintf(fp, "%s\n", saveData.GetData());

	// World time
	saveData.Set(data->GetTimeToString());

	EncodeData(&saveData);
	fprintf(fp, "%s\n", saveData.GetData());
	fclose(fp);

	return true;
}

bool SaveAndLoad::Load(Data* data)
{
	FILE* fp;

	fopen_s(&fp, savePath.GetData(), "r");

	if (fp == nullptr || fseek(fp, 0, SEEK_END) != 0 || ftell(fp) <= 0)
	{
		return false;
	}

	fseek(fp, 0, SEEK_SET);

	// Load datas
	// Player position
	char playerPosition[22];

	fgets(playerPosition, 21, fp);

	String playerPositionData = playerPosition;

	DecodeData(&playerPositionData);

	// Player status
	char playerStatus[78];

	fgets(playerStatus, 77, fp);

	String playerStatusData = playerStatus;

	DecodeData(&playerStatusData);

	// Player name
	char playerName[12];

	fgets(playerName, 11, fp);

	playerName[strlen(playerName) - 1] = '\0';

	String playerNameData = playerName;

	DecodeData(&playerNameData);

	// Inventory total items
	char inventoryTotalItems[12];

	fgets(inventoryTotalItems, 11, fp);

	String inventoryTotalItemsData = inventoryTotalItems;

	DecodeData(&inventoryTotalItemsData);

	// Inventory items
	char inventoryItem[61];

	fgets(inventoryItem, 60, fp);

	String inventoryItemData = inventoryItem;

	DecodeData(&inventoryItemData);

	// World time
	char worldTime[26];

	fgets(worldTime, 25, fp);

	worldTime[strlen(worldTime) - 1] = '\0';

	String worldTimeData = worldTime;

	DecodeData(&worldTimeData);
	fclose(fp);

	// Apply datas
	char* context = nullptr;
	char* ptr = strtok_s(playerPositionData.GetData(), "|", &context);
	int playerPositionX = atoi(ptr);

	ptr = strtok_s(nullptr, "|", &context);

	int playerPositionY = atoi(ptr);

	data->SetPlayerPosition(Vector2(playerPositionX, playerPositionY));

	ptr = strtok_s(playerStatusData.GetData(), "|", &context);

	data->SetPlayerCurrentLevel(atoi(ptr));

	ptr = strtok_s(nullptr, "|", &context);

	data->SetPlayerMaxLevel(atoi(ptr));

	ptr = strtok_s(nullptr, "|", &context);

	data->SetPlayerCurrentHealth(atoi(ptr));

	ptr = strtok_s(nullptr, "|", &context);

	data->SetPlayerMaxHealth(atoi(ptr));

	ptr = strtok_s(nullptr, "|", &context);

	data->SetPlayerCurrentHungry(atoi(ptr));

	ptr = strtok_s(nullptr, "|", &context);

	data->SetPlayerMaxHungry(atoi(ptr));

	ptr = strtok_s(nullptr, "|", &context);

	data->SetPlayerCurrentThirst(atoi(ptr));

	ptr = strtok_s(nullptr, "|", &context);

	data->SetPlayerMaxThirst(atoi(ptr));
	data->SetPlayerName(playerNameData.GetData());

	ptr = strtok_s(inventoryTotalItemsData.GetData(), "|", &context);

	unsigned int totalItems = atoi(ptr);

	ptr = strtok_s(inventoryItemData.GetData(), "|", &context);

	for (int i = 0; i < totalItems; i++)
	{
		unsigned int itemIndex = atoi(ptr);

		ptr = strtok_s(nullptr, "|", &context);

		data->AddItemByItemIndex(itemIndex, atoi(ptr));

		ptr = strtok_s(nullptr, "|", &context);
	}

	DateTime dateTime = DateTime(0, 0, 0, 0, 0, 0);

	ptr = strtok_s(worldTimeData.GetData(), "- :", &context);
	dateTime.year = atoi(ptr);
	ptr = strtok_s(nullptr, "- :", &context);
	dateTime.month = atoi(ptr);
	ptr = strtok_s(nullptr, "- :", &context);
	dateTime.day = atoi(ptr);
	ptr = strtok_s(nullptr, "- :", &context);
	dateTime.hour = atoi(ptr);
	ptr = strtok_s(nullptr, "- :", &context);
	dateTime.minute = atoi(ptr);
	ptr = strtok_s(nullptr, "- :", &context);
	dateTime.second = atoi(ptr);

	data->SetTime(dateTime);

	return true;
}