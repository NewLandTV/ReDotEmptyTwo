#ifndef __SAVEANDLOAD_H__
#define __SAVEANDLOAD_H__

#include "Application.h"
#include "Data.h"

class SaveAndLoad
{
private:
	Application* application;
	const String savePath;

	void MakeDataPath();

public:
	SaveAndLoad(Application* application);
	~SaveAndLoad();

	SaveAndLoad& EncodeData(String* data);
	SaveAndLoad& DecodeData(String* data);

	bool Save(const Data* data);
	bool Load(Data* data);
};

#endif