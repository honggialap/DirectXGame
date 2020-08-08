#pragma once
#ifndef __SOUND_H__
#define __SOUND_H__

#include "../../Include.h"
#include "../Audio.h"

struct SoundClip 
{
};

class SoundBank
{
private:
	pAudio audio;
	unordered_map<string, pSound> soundBank;

public:
	SoundBank(pAudio audio);
	~SoundBank();
	
	void Add();
	pSound Get();
};

#endif // !__SOUND_H__
