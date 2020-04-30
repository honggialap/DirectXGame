#include "Texture.h"

#pragma region Texture

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

#pragma endregion

#pragma region Textures

Textures::Textures(pResource resource, pGraphics graphics)
{
	this->resource = resource;
	this->graphics = graphics;
}

Textures::~Textures()
{
	this->Clear();
	this->graphics = nullptr;
}

void Textures::Add(string textureID, LPCWSTR filePath, D3DCOLOR transparentColor)
{
	unordered_map<string, pTexture>::const_iterator got = textures.find(textureID);
	if (got == textures.end())
	{
		pTexture texture = new Texture();
		texture->textureID = textureID;
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

		textures[textureID] = texture;

		DebugOut(L"[INFO] Texture loaded Ok: id = %s \n", ToLPCWSTR(textureID));
	}
}

pTexture Textures::Get(string textureID)
{
	return textures[textureID];
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

#pragma endregion

#pragma region TextureRegion

TextureRegion::TextureRegion()
{
	sourceRect = {};
}

TextureRegion::~TextureRegion()
{
}

#pragma endregion