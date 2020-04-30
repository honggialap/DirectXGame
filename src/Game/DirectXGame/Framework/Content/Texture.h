#pragma once
#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "../../Include.h"
#include "../Graphics.h"

class Texture
{
public:
	string textureID;
	LPDIRECT3DTEXTURE9 texture;
	D3DXIMAGE_INFO info;
	D3DCOLOR transparentColor;

	Texture();
	~Texture();
};

class Textures
{
public:
	pResource resource;
	pGraphics graphics;

	unordered_map<string, pTexture> textures;

	Textures(pResource resource, pGraphics graphics);
	~Textures();

	void Add(string textureID, LPCWSTR filePath, D3DCOLOR transparentColor);
	pTexture Get(string textureID);
	void Clear();
};

class TextureRegion
{
public:
	string textureRegionID;
	string textureID;
	RECT sourceRect;

	TextureRegion();
	~TextureRegion();
};

#endif // !__TEXTURE_H__