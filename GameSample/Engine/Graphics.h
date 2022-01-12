#pragma once
#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#pragma region INCLUDE
#include <d3d10.h>
#include <d3dx10.h>
#include <unordered_map>
#pragma endregion


/// <summary>
/// Handling texture.
/// </summary>
struct CTexture
{
	ID3D10Texture2D*			_texture	= NULL;
	ID3D10ShaderResourceView*	_srview		= NULL;

	int	_width	= 0;
	int	_height	= 0;

	CTexture(ID3D10Texture2D* texture, ID3D10ShaderResourceView* srview);
	~CTexture();
};
typedef CTexture* pTexture;


/// <summary>
/// Handling Direct3D and texture database.
/// </summary>
class CGraphics
{
	/* Direct 3D */
private:
	ID3D10Device* _device						= NULL;
	IDXGISwapChain* _swapChain					= NULL;
	ID3D10RenderTargetView* _renderTargetView	= NULL;
	ID3D10BlendState* _blendStateAlpha			= NULL;
	ID3D10SamplerState* _pointSamplerState		= NULL;
	ID3DX10Sprite* _spriteHandler				= NULL;

	unsigned int _backBufferWidth	= 0;
	unsigned int _backBufferHeight	= 0;

public:
	ID3D10Device* GetDevice() { return _device; }
	IDXGISwapChain* GetSwapChain() { return _swapChain; }
	ID3D10RenderTargetView* GetRenderTargetView() { return _renderTargetView; }
	ID3D10BlendState* GetBlendStateAlpha() { return _blendStateAlpha; }
	ID3DX10Sprite* GetSpriteHandler() { return _spriteHandler; }

	unsigned int GetBackBufferWidth() { return _backBufferWidth; }
	unsigned int GetBackBufferHeight() { return _backBufferHeight; }

	void Initialize(HWND hWnd);
	void Shutdown();

	/* Texture Database */
private:
	std::unordered_map<unsigned int, pTexture> _textures;

public:
	void LoadTexture(unsigned int id, std::wstring texturePath);
	pTexture GetTexture(unsigned int id);
};
typedef CGraphics* pGraphics;

#endif // !__GRAPHICS_H__