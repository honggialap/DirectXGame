#include "Texture.h"

Texture::Texture()
{
	texture = NULL;
	info = {};
	transparentColor = {};
}

Texture::~Texture()
{
	if (texture != NULL) texture->Release();
	texture = NULL;
}

Textures::Textures(pGraphics graphics)
{
	this->graphics = graphics;
}

Textures::~Textures()
{
	this->Clear();
	this->graphics = nullptr;
}

void Textures::Add(string id, LPCWSTR filePath, D3DCOLOR transparentColor)
{
	unordered_map<string, pTexture>::const_iterator got = textures.find(id);
	if (got == textures.end())
	{
		pTexture texture = new Texture();
		texture->transparentColor = transparentColor;
		
		HRESULT result = D3DXGetImageInfoFromFile(filePath, &texture->info);
		if (result != D3D_OK)
		{
			delete texture;
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
			texture->transparentColor,
			&texture->info,
			NULL,
			&texture->texture);
		if (result != D3D_OK)
		{
			delete texture;
			OutputDebugString(L"[ERROR] CreateTextureFromFile failed\n");
			return;
		}

		textures[id] = texture;

		DebugOut(L"[INFO] Texture loaded Ok: id=%d, %s\n", id, filePath);
	}
	else
		return;
}

pTexture Textures::Get(string id)
{
	return textures[id];
}

void Textures::Clear()
{
	for (auto i : textures)
	{
		delete i.second;
		i.second = nullptr;
	}

	textures.clear();
}

