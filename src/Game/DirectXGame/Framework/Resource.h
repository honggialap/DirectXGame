#pragma once
#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include "Graphics.h"
#include "Content/Texture.h"

#include "Audio.h"
#include "Content/Sound.h"

class Resource
{
public:
	pGraphics graphics;
	pAudio audio;

	//pTextures textures;
	//pSounds sounds;
	//pSprites sprites;
	//pAnimations animations;
	//pTilemaps tilemaps;

	Resource(pGraphics graphics, pAudio audio);
	~Resource();

	//bool Load();
	//template <class T> T Get();
};

typedef Resource* pResource;

#endif // !__RESOURCE_H__