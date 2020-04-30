#pragma once
#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "../Include.h"

#include "../Framework/Resource.h"
#include "../Framework/Content/Texture.h"
#include "Component.h"
#include "GameObject.h"
#include "View/Renderer.h"

class Sprite : public Component
{
public:

	string spriteID;
	bool visible;
	//unsigned int layer;

	pTexture texture;
	RECT sourceRect;

	D3DXVECTOR2 offset;
	bool flipHorizontal;
	bool flipVertical;

	Sprite();
	~Sprite();

	void Render();
};

class Sprites
{
public:
	pResource resource;

	unordered_map<string, pSprite> sprites;

	Sprites(pResource resource);
	~Sprites();

	void Add(string spriteID, string textureRegionID, float offsetX, float offsetY);
	pSprite Get(string spriteID);
	void Clear();
};

class SpriteAtlas
{
public:
	pResource resource;

	unordered_map<string, pTextureRegion> spriteAtlas;

	SpriteAtlas(pResource resource);
	~SpriteAtlas();

	void Add(string textureRegionID, string textureID, int left, int top, int right, int bottom);
	pTextureRegion Get(string textureRegionID);
	void Clear();
};

#endif // !__SPRITE_H__
