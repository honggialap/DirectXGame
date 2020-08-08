#include "Texture.h"

Texture::Texture(int r, int g, int b)
{
	texture = {};
	info = {};
	this->r = r;
	this->g = g;
	this->b = b;
}

Texture::~Texture()
{
	texture->Release();
}

Textures::Textures(pGraphics graphics)
{
	this->graphics = graphics;
}

Textures::~Textures()
{
	for (auto texture : textures)
	{
		delete texture.second;
		texture.second = nullptr;
	}
	textures.clear();
	
	this->graphics = nullptr;
}

void Textures::Add(string textureID, LPCWSTR filePath, int r, int g, int b)
{
	unordered_map<string, pTexture>::const_iterator got = textures.find(textureID);
	if (got == textures.end())
	{
		auto texture = new Texture(r, g, b);
		D3DCOLOR transparentColor = D3DCOLOR_XRGB(r, g, b);
		textures[textureID] = texture;

		HRESULT result = D3DXGetImageInfoFromFile(filePath, &texture->info);
		if (result != D3D_OK)
		{
			DebugOut(L"[ERROR] GetImageInfoFromFile failed: %s\n", filePath);
			return;
		}

		result = D3DXCreateTextureFromFileEx(
			graphics->graphicsDevice->device,
			filePath,
			texture->info.Width,
			texture->info.Height,
			1,
			D3DUSAGE_DYNAMIC,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			transparentColor,
			&texture->info,
			NULL,
			&texture->texture);
		if (result != D3D_OK)
		{
			OutputDebugString(L"[ERROR] CreateTextureFromFile failed\n");
			return;
		}

		DebugOut(L"[INFO] Texture loaded: id = %s \n", ToLPCWSTR(textureID));
	}
}

pTexture Textures::Get(string textureID)
{
	return textures[textureID];
}
