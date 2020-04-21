#pragma once
#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include <iostream>

#include "../Library/pugixml/pugixml.hpp"
using namespace pugi;

class GameSettings;
typedef GameSettings* pGameSettings;

#include "../Game.h"

#include "../Logic/Scene.h"

#include "Graphics.h"
#include "Content/Texture.h"

//#include "Audio.h"
//#include "Content/Sound.h"

//#include "../Logic/Sprite.h"
//#include "../Logic/Animation.h"
//#include "../Logic/Tilemap.h"


class Resource
{
public:
	pGraphics graphics;
	//pAudio audio;

	pTextures textures;
	//pSounds sounds;
	//pSprites sprites;
	//pAnimations animations;
	//pTilemaps tilemaps;

	Resource(pGraphics graphics); // ,pAudio audio);
	~Resource();

	//bool Load();
	void LoadGameData(pGameSettings gameSettings, LPCWSTR filePath);
	void LoadGameContent(LPCWSTR filePath);
	void LoadScenes(pScenes scenes, LPCWSTR filePath);
};

typedef Resource* pResource;

#endif // !__RESOURCE_H__