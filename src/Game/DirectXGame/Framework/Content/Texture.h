#pragma once
#ifndef __TEXTURE_H__
#define __TEXTURE_H__

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

typedef Texture* pTexture;

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

typedef Textures* pTextures;

#endif // !__TEXTURE_H__