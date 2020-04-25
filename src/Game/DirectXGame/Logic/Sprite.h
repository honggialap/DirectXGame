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

	string id;

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
	unordered_map<string, pSprite> sprites;

	Sprites();
	~Sprites();

	void Add(string id, pTexture texture, int left, int top, int right, int bottom, float offsetX, float offsetY);
	pSprite Get(string id);
	void Clear();
};

#endif // !__SPRITE_H__
