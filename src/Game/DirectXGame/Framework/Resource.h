#pragma once
#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include "../Include.h"

#include <iostream>

#include "../Library/pugixml/pugixml.hpp"
using namespace pugi;

#include "../Game.h"
#include "Graphics.h"
#include "Audio.h"
#include "Content/Texture.h"
#include "Content/Sound.h"
#include "../Logic/Scene.h"
#include "../Logic/GameObject.h"
#include "../Logic/Sprite.h"
//#include "../Logic/Animation.h"
//#include "../Logic/Tilemap.h"

class Resource
{
public:
	pGraphics graphics;
	pAudio audio;

	pTextures textures;
	pSounds sounds;

	pSprites sprites;
	//pAnimations animations;
	//pTilemaps tilemaps;

	Resource(pGraphics graphics, pAudio audio);
	~Resource();

	//bool Load();
	void LoadData(pGameSettings gameSettings, LPCWSTR filePath);
	void LoadContent(LPCWSTR filePath);
	void LoadScene(pScene scene, LPCWSTR filePath);
	void LoadGameObject(pScene scene, LPCWSTR filePath);

	void LoadScenes(pScenes scenes, LPCWSTR filePath);
};

typedef Resource* pResource;

#endif // !__RESOURCE_H__