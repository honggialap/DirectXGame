#pragma once
#ifndef __AUDIO_H__
#define __AUDIO_H__

#include "../Include.h"
#include "Application.h"

class AudioDevice
{
public:
	static const int SOUND_BUFFER_SIZE = 128;

	LPDIRECTSOUND8 directSound;
	LPDIRECTSOUNDBUFFER primaryBuffer;
	LPDIRECTSOUNDBUFFER8 secondaryBuffer[SOUND_BUFFER_SIZE];

	AudioDevice();
	~AudioDevice();
};

class Audio
{
public:
	pAudioDevice audioDevice;

	Audio();
	~Audio();

	void CreateAudioDevice(pGameWindow gameWindow);
	void Play();
};

#endif // !__AUDIO_H__