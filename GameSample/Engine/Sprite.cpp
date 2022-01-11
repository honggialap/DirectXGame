#include "Sprite.h"
#include "Game.h"
#include "Graphics.h"

CSprite::CSprite(pGameObject gameObject, int left, int top, int width, int height, int offsetX, int offsetY, pTexture texture)
{
	_gameObject = gameObject;
	_left = left;
	_top = top;
	_width = width;
	_height = height;
	_offsetX = offsetX;
	_offsetY = offsetY;
	_texture = texture;

	float texWidth = (float)_texture->_width;
	float texHeight = (float)_texture->_height;

	_sprite.pTexture = _texture->_srview;
	_sprite.TexCoord.x = _left / texWidth;
	_sprite.TexCoord.y = _top / texHeight;
	_sprite.TexSize.x = _width / texWidth;
	_sprite.TexSize.y = _height / texHeight;
	_sprite.ColorModulate = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	_sprite.TextureIndex = 0;

	D3DXMatrixScaling(&_matScaling, (FLOAT)_width, (FLOAT)_height, 1.0f);
}

void CSprite::Render(float x, float y, bool isUI)
{
	auto graphics = _gameObject->GetGame()->GetGraphics();
	
	float cameraX = 0;
	float cameraY = 0;
	_gameObject->GetGame()->GetCamera(cameraX, cameraY);
	cameraX = (FLOAT)floor(cameraX);
	cameraY = (FLOAT)floor(cameraY);

	D3DXMATRIX matTranslation;

	x = (FLOAT)floor(x) + _offsetX;
	y = (FLOAT)floor(y) + _offsetY;

	if (isUI)
		D3DXMatrixTranslation(&matTranslation, x, graphics->GetBackBufferHeight() + y, 0.1f);
	else
		D3DXMatrixTranslation(&matTranslation, x - cameraX, graphics->GetBackBufferHeight() + y - cameraY, 0.1f);

	_sprite.matWorld = (_matScaling * matTranslation);

	graphics->GetSpriteHandler()->DrawSpritesImmediate(&_sprite, 1, 0, 0);
}
