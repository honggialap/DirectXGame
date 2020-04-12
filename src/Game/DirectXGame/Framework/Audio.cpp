#include "Audio.h"

Audio::Audio()
{
	audioDevice = new AudioDevice();
}

Audio::~Audio()
{
	delete audioDevice;
	audioDevice = nullptr;
}

void Audio::CreateAudioDevice(pGameWindow gameWindow)
{
}

void Audio::Play()
{
}
