#include "Sprite.h"

SpriteRenderer::SpriteRenderer(pGameObject gameObject) : Component::Component(gameObject)
{
	type = Component::Type::SpriteRenderer;
	resource = gameObject->scene->game->resource;
	graphics = gameObject->scene->game->graphics;
	camera = gameObject->scene->cameras[0];

	alpha = 255;
	flipSprite = FlipSprite::None;
	flipOffset = FlipOffset::None;
}

SpriteRenderer::~SpriteRenderer()
{
	for (auto sprite : sprites)
	{
		delete sprite.second;
		sprite.second = nullptr;
	}
	sprites.clear();

	camera = nullptr;
	graphics = nullptr;
	resource = nullptr;
}

void SpriteRenderer::AddPalette(int pallateNo, string textureID)
{
	palettes[pallateNo] = resource->textures->Get(textureID);
}

void SpriteRenderer::Add(string spriteID, bool paletting, int paletteNo,
	int left, int top, int right, int bottom, 
	int offsetX, int offsetY)
{
	unordered_map<string, pSprite>::const_iterator got = sprites.find(spriteID);
	if (got == sprites.end())
	{
		sprites[spriteID] = new Sprite();

		sprites[spriteID]->paletting = paletting;
		sprites[spriteID]->texture = palettes[paletteNo];

		sprites[spriteID]->sourceRect.left = left;
		sprites[spriteID]->sourceRect.top = top;
		sprites[spriteID]->sourceRect.right = right;
		sprites[spriteID]->sourceRect.bottom = bottom;

		sprites[spriteID]->size.x = sprites[spriteID]->sourceRect.right
			- sprites[spriteID]->sourceRect.left + 1;
		sprites[spriteID]->size.y = sprites[spriteID]->sourceRect.bottom
			- sprites[spriteID]->sourceRect.top + 1;
		sprites[spriteID]->size.z = 0;

		sprites[spriteID]->center.x = sprites[spriteID]->size.x / 2;
		sprites[spriteID]->center.y = sprites[spriteID]->size.y / 2;
		sprites[spriteID]->center.z = 0;

		sprites[spriteID]->offset.x = offsetX;
		sprites[spriteID]->offset.y = offsetY;
		sprites[spriteID]->offset.z = 0;
	}
}

pSprite SpriteRenderer::Get(string spriteID)
{
	return sprites[spriteID];
}

void SpriteRenderer::Render(string spriteID, int additionX, int additionY)
{
	if (!UI)
	{
		if (sprites[spriteID]->paletting)
			sprites[spriteID]->texture = palettes[paletteNo];

		bool flipX = false;
		bool flipY = false;
		switch (flipSprite)
		{
		case FlipSprite::None:
			flipX = false;
			flipY = false;
			break;
		case FlipSprite::Horizontal:
			flipX = true;
			flipY = false;
			break;
		case FlipSprite::Vertical:
			flipX = false;
			flipY = true;
			break;
		case FlipSprite::Both:
			flipX = true;
			flipY = true;
			break;
		}

		D3DXVECTOR3 renderOrigin;
		renderOrigin.x = camera->x
			- (camera->viewport->GetWidth() / 2)
			- (camera->viewport->left);
		renderOrigin.y = camera->y
			+ (camera->viewport->GetHeight() / 2)
			+ (camera->viewport->top);
		renderOrigin.z = 0;

		D3DXVECTOR3 renderPosition;
		renderPosition.x = gameObject->x - renderOrigin.x;
		renderPosition.y = gameObject->y - renderOrigin.y;
		renderPosition.z = 0;

		switch (flipOffset)
		{
		case FlipOffset::None:
			renderPosition.x += sprites[spriteID]->offset.x;
			renderPosition.y += sprites[spriteID]->offset.y;
			break;
		case FlipOffset::Horizontal:
			renderPosition.x -= sprites[spriteID]->offset.x;
			renderPosition.y += sprites[spriteID]->offset.y;
			break;
		case FlipOffset::Vertical:
			renderPosition.x += sprites[spriteID]->offset.x;
			renderPosition.y -= sprites[spriteID]->offset.y;
			break;
		case FlipOffset::Both:
			renderPosition.x -= sprites[spriteID]->offset.x;
			renderPosition.y -= sprites[spriteID]->offset.y;
			break;
		}
		renderPosition.x += additionX;
		renderPosition.y += additionY;
		renderPosition.y *= -1;

		graphics->Draw(renderPosition.x, renderPosition.y, sprites[spriteID], flipX, flipY, alpha);
	}
	else graphics->Draw(additionX, additionX, sprites[spriteID], false, false, alpha);
}
