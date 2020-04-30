#include "Sprite.h"

#pragma region Sprite

Sprite::Sprite()
{
	componentType = ComponentType::SpriteRenderer;
	flipHorizontal = false;
	flipVertical = false;
	sourceRect = {};
	texture = nullptr;
	visible = false;
}

Sprite::~Sprite()
{
}

void Sprite::Render()
{
	if (visible) gameObject->game->graphics->Draw(this);
}

#pragma endregion

#pragma region Sprites

Sprites::Sprites(pResource resource)
{
	this->resource = resource;
}

Sprites::~Sprites()
{
}

void Sprites::Add(string spriteID, string textureRegionID, float offsetX, float offsetY)
{
	unordered_map<string, pSprite>::const_iterator got = sprites.find(spriteID);
	if (got == sprites.end())
	{
		pSprite sprite = new Sprite();

		sprite->spriteID = spriteID;
		sprite->texture = resource->textures->Get(resource->spriteAtlas->Get(textureRegionID)->textureID);
		sprite->sourceRect = resource->spriteAtlas->Get(textureRegionID)->sourceRect;
		sprite->offset = D3DXVECTOR2(offsetX, offsetY);

		sprites[spriteID] = sprite;
	
		DebugOut(L"[INFO] Sprite loaded Ok: id = %s \n", ToLPCWSTR(spriteID));
	}
}

pSprite Sprites::Get(string spriteID)
{
	return sprites[spriteID];
}

void Sprites::Clear()
{
	for (auto i : sprites)
	{
		delete i.second;
		i.second = nullptr;
	}

	sprites.clear();
}

#pragma endregion

#pragma region SpriteAtlas

SpriteAtlas::SpriteAtlas(pResource resource)
{
	this->resource = resource;
}

SpriteAtlas::~SpriteAtlas()
{
}

void SpriteAtlas::Add(string textureRegionID, string textureID, int left, int top, int right, int bottom)
{
	unordered_map<string, pTextureRegion>::const_iterator got = spriteAtlas.find(textureRegionID);
	if (got == spriteAtlas.end())
	{
		pTextureRegion textureRegion = new TextureRegion();

		textureRegion->textureRegionID = textureRegionID;
		textureRegion->textureID = textureID;

		textureRegion->sourceRect.left = left;
		textureRegion->sourceRect.top = top;
		textureRegion->sourceRect.right = right;
		textureRegion->sourceRect.bottom = bottom;

		spriteAtlas[textureRegionID] = textureRegion;

		DebugOut(L"[INFO] Sprite atlas loaded Ok: id = %s \n", ToLPCWSTR(textureRegionID));
	}
}

pTextureRegion SpriteAtlas::Get(string textureRegionID)
{
	return spriteAtlas[textureRegionID];
}

void SpriteAtlas::Clear()
{
	for (auto i : spriteAtlas)
	{
		delete i.second;
		i.second = nullptr;
	}

	spriteAtlas.clear();
}

#pragma endregion