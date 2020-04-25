#pragma once
#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "../../Include.h"

#include <unordered_map>

#include "../Graphics.h"

class Texture
{
public:
	LPDIRECT3DTEXTURE9 texture;
	D3DXIMAGE_INFO info;
	D3DCOLOR transparentColor;

	Texture();
	~Texture();
};

class Textures
{
public:
	pGraphics graphics;

	unordered_map<string, pTexture> textures;

	Textures(pGraphics graphics);
	~Textures();

	void Add(string id, LPCWSTR filePath, D3DCOLOR transparentColor);
	pTexture Get(string id);
	void Clear();
};

#endif // !__TEXTURE_H__