#pragma once

#ifndef __AUDIO_H__
#define __AUDIO_H__

#include "DirectSound.h"

class Audio
{
	//Singleton
private:
	static Audio* __instance;
	Audio();
public:
	static Audio* GetInstance();
	~Audio();


	//DirectSound API
private:

public:

	//Framework component
public:
	void Initialize();
	void Shutdown();
};

typedef Audio* pAudio;

#endif // !__AUDIO_H__