#include "Audio.h"

AudioDevice::AudioDevice()
{
}

AudioDevice::~AudioDevice()
{
}

Audio::Audio()
{
	audioDevice = new AudioDevice();
}

Audio::~Audio()
{
	if (audioDevice != nullptr)
	{
		delete audioDevice;
		audioDevice = nullptr;
	}
}

void Audio::CreateAudioDevice(pGameWindow gameWindow)
{
}

void Audio::Play()
{
}


