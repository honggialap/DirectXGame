#include "Sprite.h"

Sprite::Sprite()
{
	componentType = ComponentType::Sprite;
	flipHorizontal = false;
	flipVertical = false;
	sourceRect = {};
	texture = nullptr;
}

Sprite::~Sprite()
{
}

void Sprite::Render()
{
	gameObject->game->graphics->Draw(this);
}

Sprites::Sprites()
{
}

Sprites::~Sprites()
{
}

void Sprites::Add(string id, pTexture texture, int left, int top, int right, int bottom, float offsetX, float offsetY)
{
	unordered_map<string, pSprite>::const_iterator got = sprites.find(id);
	if (got == sprites.end())
	{
		pSprite sprite = new Sprite();
		sprite->id = id;
		sprite->texture = texture;
		sprite->sourceRect.left = left;
		sprite->sourceRect.top = top;
		sprite->sourceRect.right = right;
		sprite->sourceRect.bottom = bottom;
		sprite->flipHorizontal = false;
		sprite->flipVertical = false;
		sprite->offset = D3DXVECTOR2(offsetX, offsetY);

		sprites[id] = sprite;

		DebugOut(L"[INFO] Sprite loaded Ok: id = %s \n", ToLPCWSTR(id));
	}
}

pSprite Sprites::Get(string id)
{
	return sprites[id];
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
