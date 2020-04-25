#pragma once
#ifndef __SOUND_H__
#define __SOUND_H__

#include "../../Include.h"

#include <unordered_map>

#include "../Audio.h"

class Sound 
{
public:
	Sound();
	~Sound();
};

typedef Sound* pSound;

class Sounds
{
public:
	pAudio audio;

	unordered_map<string, pSound> sounds;

	Sounds(pAudio audio);
	~Sounds();
	
	void Add();
	pSound Get();
	void Clear();
};

typedef Sounds* pSounds;

#endif // !__SOUND_H__
