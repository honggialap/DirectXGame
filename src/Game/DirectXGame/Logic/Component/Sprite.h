#pragma once
#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "../../Include.h"
#include "../../Framework/Resource.h"
#include "../../Framework/Content/Texture.h"
#include "Component.h"
#include "../GameObject.h"

struct Sprite
{
	bool paletting;
	pTexture texture;
	RECT sourceRect;

	D3DXVECTOR3 size;
	D3DXVECTOR3 center;

	D3DXVECTOR3 offset;
};

class SpriteRenderer : public Component
{
public:
	enum class FlipSprite
	{
		None,
		Horizontal,
		Vertical,
		Both
	};
	enum class FlipOffset
	{
		None,
		Horizontal,
		Vertical,
		Both
	};
private:
	pResource resource;
	pGraphics graphics;
	pCamera camera;

	unordered_map<string, pSprite> sprites;
	map<int, pTexture> palettes;
	bool UI;

	int alpha;
	FlipOffset flipOffset;
	FlipSprite flipSprite;
	int paletteNo;

public:
	SpriteRenderer(pGameObject gameObject);
	~SpriteRenderer();

	void SetAlpha(int alpha) { this->alpha = alpha; }
	void SetFlipSprite(FlipSprite flipSprite) { this->flipSprite = flipSprite; }
	void SetFlipOffset(FlipOffset flipOffset) { this->flipOffset = flipOffset; }
	void SetPalette(int paletteNo) { this->paletteNo = paletteNo; }

	void AddPalette(int paletteNo, string textureID);
	void Add(string spriteID, bool paletting, int palleteNo,
		int left, int top, int right, int bottom,
		int offsetX, int offsetY);
	pSprite Get(string spriteID);
	void Render(string spriteID, int additionX = 0, int additionY = 0);
};

#endif // !__SPRITE_H__
