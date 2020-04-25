#include "Sound.h"

Sounds::Sounds(pAudio audio)
{
	this->audio = audio;
}

Sounds::~Sounds()
{
	this->Clear();
	this->audio = nullptr;
}

void Sounds::Add()
{
}

pSound Sounds::Get()
{
	return pSound();
}

void Sounds::Clear()
{
}

Sound::Sound()
{
}

Sound::~Sound()
{
}
