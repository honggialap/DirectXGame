#pragma once
#ifndef __SPRITE_H__
#define __SPRITE_H__

#pragma region INCLUDE
#include "Game.h"
#include "Graphics.h"
#pragma endregion

class CSprite
{
private:
	int _left	= 0;
	int _top	= 0;
	int _right	= 0;
	int _bottom	= 0;

	pTexture _texture;
	D3DX10_SPRITE _sprite;
	D3DXMATRIX _matScaling;

public:
	CSprite(int left, int top, int right, int bottom, pTexture texture);
	void Render(float x, float y, bool isUI);
};
typedef CSprite* pSprite;

#endif // !__SPRITE_H__
