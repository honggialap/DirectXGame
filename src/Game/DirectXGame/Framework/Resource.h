#pragma once
#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include "Graphics.h"
#include "Content/Texture.h"

//#include "Audio.h"
//#include "Content/Sound.h"

class Resource
{
public:
	pGraphics graphics;
	//pAudio audio;

	//pTextures
	//pSprites
	//pAnimations
	//pTilemaps

	Resource(pGraphics graphics); //pAudio audio
	~Resource();
};

typedef Resource* pResource;

#endif // !__RESOURCE_H__
