#include "Sound.h"

SoundBank::SoundBank(pAudio audio)
{
	this->audio = audio;
}

SoundBank::~SoundBank()
{
}

void SoundBank::Add()
{
}

pSound SoundBank::Get()
{
	return pSound();
}
