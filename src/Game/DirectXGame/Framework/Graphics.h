#pragma once
#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <d3d9.h>
#include <d3dx9.h>

#include "Application.h"
#include "Ultilities.h"

class GraphicsDevice
{
public:
	LPDIRECT3D9 direct3D;
	LPDIRECT3DDEVICE9 device;
	D3DPRESENT_PARAMETERS presentParameters;
	LPDIRECT3DSURFACE9 backBuffer;
	LPD3DXSPRITE spriteHandler;

	GraphicsDevice();
	~GraphicsDevice();
};

typedef GraphicsDevice* pGraphicsDevice;

class Graphics
{
public:
	pGraphicsDevice graphicsDevice;

	Graphics();
	~Graphics();
	void CreateGraphicsDevice(pGameWindow gameWindow);

	void Draw();
};

typedef Graphics* pGraphics;

#endif // !__GRAPHICS_H__
