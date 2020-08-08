#pragma once
#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "../../Include.h"
#include "../Graphics.h"

struct Texture
{
	LPDIRECT3DTEXTURE9 texture;
	D3DXIMAGE_INFO info; 
	int r, g, b;

	Texture(int r, int g, int b);
	~Texture();
};

class Textures
{
private:
	pGraphics graphics;
	unordered_map<string, pTexture> textures;

public:
	Textures(pGraphics graphics);
	~Textures();

	void Add(string textureID, LPCWSTR filePath, int r, int g, int b);
	pTexture Get(string textureID);
};

#endif // !__TEXTURE_H__