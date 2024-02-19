#include <Windows.h>
#include "SoundManager.h"

#pragma comment(lib, "winmm.lib")

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{

}

void SoundManager::PlayBgm(bool loop)
{
	// Origin Path : E:\\UserData\\Music\\NewLand Melodic Artist\\Flag Destroy\\Flag Destroy.mp3
	mciSendString(TEXT("open \"E:\\UserData\\Music\\NewLand Music Artist\\Flag Destroy\\Flag Destroy.mp3\" type mpegvideo alias bgm"), nullptr, 0, nullptr);
	mciSendString(loop ? L"play bgm from 0 repeat" : L"play bgm", nullptr, 0, nullptr);
}

void SoundManager::StopBgm()
{
	mciSendString(L"close bgm", nullptr, 0, nullptr);
}