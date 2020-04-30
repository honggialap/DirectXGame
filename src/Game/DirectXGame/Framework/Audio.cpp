#include "Audio.h"

#pragma region AudioDevice

AudioDevice::AudioDevice()
{
}

AudioDevice::~AudioDevice()
{
}

#pragma endregion

#pragma region Audio

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

#pragma endregion