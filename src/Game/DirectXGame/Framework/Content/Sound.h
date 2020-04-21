#pragma once
#ifndef __SOUND_H__
#define __SOUND_H__

#include "../Audio.h"

#include <unordered_map>

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

	unordered_map<int, pSound> sounds;

	Sounds(pAudio audio);
	~Sounds();
	
	//void Add
	//pAudio Get
	void Clear();
};

typedef Sounds* pSounds;

#endif // !__SOUND_H__
