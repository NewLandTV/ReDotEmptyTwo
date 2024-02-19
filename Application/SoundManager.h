#ifndef __SOUNDMANAGER_H__
#define __SOUNDMANAGER_H__

class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	void PlayBgm(bool loop);
	void StopBgm();
};

#endif