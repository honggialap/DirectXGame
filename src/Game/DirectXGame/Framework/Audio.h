#pragma once
#ifndef __AUDIO_H__
#define __AUDIO_H__

#include "../Include.h"
#include "Application.h"

struct AudioDevice
{
	//static const int SOUND_BUFFER_SIZE = 128;
	//
	//LPDIRECTSOUND8 directSound;
	//LPDIRECTSOUNDBUFFER primaryBuffer;
	//LPDIRECTSOUNDBUFFER8 secondaryBuffer[SOUND_BUFFER_SIZE];
};

class Audio
{
public:
	Audio();
	~Audio();

	pAudioDevice audioDevice;
	void CreateAudioDevice(pGameWindow gameWindow);

	void Play();
};

#endif // !__AUDIO_H__