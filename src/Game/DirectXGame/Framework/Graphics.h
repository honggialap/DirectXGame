#pragma once
#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include "../Include.h"
#include "Application.h"
#include "../Logic/Component/Sprite.h"

struct GraphicsDevice
{
	LPDIRECT3D9 direct3D;
	LPDIRECT3DDEVICE9 device;
	D3DPRESENT_PARAMETERS presentParameters;
	LPDIRECT3DSURFACE9 backBuffer;
	LPD3DXSPRITE spriteHandler;
};

class Graphics
{
public:
	Graphics();
	~Graphics();
	
	pGraphicsDevice graphicsDevice;
	void CreateGraphicsDevice(pGameWindow gameWindow);

	void Draw(float x, float y, pSprite sprite,
		bool flipX, bool flipY, int alpha);
};

#endif // !__GRAPHICS_H__