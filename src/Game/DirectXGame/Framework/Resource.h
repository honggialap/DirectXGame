#pragma once
#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include "../Include.h"
#include "../Game.h"
#include "Graphics.h"
#include "Content/Texture.h"
#include "../Logic/Scene.h"
//#include "../Logic/GameObject.h"
#include "../Logic/Sprite.h"
//#include "../Logic/Animation.h"
//#include "../Logic/Tilemap.h"

class Resource
{
public:
	pGraphics graphics;
	pTextures textures;
	pSpriteAtlas spriteAtlas;
	pSprites sprites;
	//pAnimations animations;
	//pTilemaps tilemaps

	//pPrefabs prefabs;

	Resource(pGraphics graphics);
	~Resource();

	void LoadGameSettings(pGameSettings gameSettings, LPCWSTR filePath);
	void LoadContent(LPCWSTR filePath);
};

#endif // !__RESOURCE_H__