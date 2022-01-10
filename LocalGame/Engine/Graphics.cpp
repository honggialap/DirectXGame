#include "Graphics.h"
#include "Debug.h"


CTexture::CTexture(ID3D10Texture2D* texture, ID3D10ShaderResourceView* srview)
{
	_texture = texture;
	_srview = srview;

	D3D10_TEXTURE2D_DESC desc;
	_texture->GetDesc(&desc);
	_width = desc.Width;
	_height = desc.Height;
}


CTexture::~CTexture()
{
	if (_srview != NULL) _srview->Release();
	if (_texture != NULL) _texture->Release();
}


/// <summary>
/// 
/// </summary>
/// <param name="hWnd"></param>
void CGraphics::Initialize(HWND hWnd)
{
	/* Back buffer */
	RECT rect;
	GetClientRect(hWnd, &rect);
	_backBufferWidth = rect.right + 1;
	_backBufferHeight = rect.bottom + 1;


	/* Swap chain */
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = _backBufferWidth;
	swapChainDesc.BufferDesc.Height = _backBufferHeight;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = hWnd;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.Windowed = TRUE;

	HRESULT hr = D3D10CreateDeviceAndSwapChain(NULL,
		D3D10_DRIVER_TYPE_REFERENCE,
		NULL,
		0,
		D3D10_SDK_VERSION,
		&swapChainDesc,
		&_swapChain,
		&_device);

	if (hr != S_OK)
	{
		DebugOut(L"[ERROR] D3D10CreateDeviceAndSwapChain has failed.\n");
		return;
	}


	/* Get backbuffer from swap chain*/
	ID3D10Texture2D* pBackBuffer;
	hr = _swapChain->GetBuffer(0, __uuidof(ID3D10Texture2D), (LPVOID*)&pBackBuffer);
	if (hr != S_OK)
	{
		DebugOut(L"[ERROR] pSwapChain->GetBuffer has failed.\n");
		return;
	}

	
	/* Render target view */
	hr = _device->CreateRenderTargetView(pBackBuffer, NULL, &_renderTargetView);
	pBackBuffer->Release();
	if (hr != S_OK)
	{
		DebugOut(L"[ERROR] CreateRenderTargetView has failed.\n");
		return;
	}

	
	/* Viewport */
	D3D10_VIEWPORT viewPort;
	viewPort.Width = _backBufferWidth;
	viewPort.Height = _backBufferHeight;
	viewPort.MinDepth = 0.0f;
	viewPort.MaxDepth = 1.0f;
	viewPort.TopLeftX = 0;
	viewPort.TopLeftY = 0;
	_device->RSSetViewports(1, &viewPort);


	/* Sampler State */
	D3D10_SAMPLER_DESC desc;
	desc.Filter = D3D10_FILTER_MIN_MAG_POINT_MIP_LINEAR;
	desc.AddressU = D3D10_TEXTURE_ADDRESS_CLAMP;
	desc.AddressV = D3D10_TEXTURE_ADDRESS_CLAMP;
	desc.AddressW = D3D10_TEXTURE_ADDRESS_CLAMP;
	desc.MipLODBias = 0;
	desc.MaxAnisotropy = 1;
	desc.ComparisonFunc = D3D10_COMPARISON_NEVER;
	desc.BorderColor[0] = 1.0f;
	desc.BorderColor[1] = 1.0f;
	desc.BorderColor[2] = 1.0f;
	desc.BorderColor[3] = 1.0f;
	desc.MinLOD = -FLT_MAX;
	desc.MaxLOD = FLT_MAX;
	_device->CreateSamplerState(&desc, &this->_pointSamplerState);
	_device->VSSetSamplers(0, 1, &_pointSamplerState);
	_device->GSSetSamplers(0, 1, &_pointSamplerState);
	_device->PSSetSamplers(0, 1, &_pointSamplerState);


	/* Sprite handlder */
	hr = D3DX10CreateSprite(_device, 0, &_spriteHandler);
	if (hr != S_OK)
	{
		DebugOut(L"[ERROR] D3DX10CreateSprite has failed.\n");
		return;
	}


	/* Projection matrix */
	D3DXMATRIX matProjection;
	D3DXMatrixOrthoOffCenterLH(&matProjection,
		(float)viewPort.TopLeftX,
		(float)viewPort.Width,
		(float)viewPort.TopLeftY,
		(float)viewPort.Height,
		0.1f,
		10);
	hr = _spriteHandler->SetProjectionTransform(&matProjection);

	/* Blend state */
	D3D10_BLEND_DESC StateDesc;
	ZeroMemory(&StateDesc, sizeof(D3D10_BLEND_DESC));
	StateDesc.AlphaToCoverageEnable = FALSE;
	StateDesc.BlendEnable[0] = TRUE;
	StateDesc.SrcBlend = D3D10_BLEND_SRC_ALPHA;
	StateDesc.DestBlend = D3D10_BLEND_INV_SRC_ALPHA;
	StateDesc.BlendOp = D3D10_BLEND_OP_ADD;
	StateDesc.SrcBlendAlpha = D3D10_BLEND_ZERO;
	StateDesc.DestBlendAlpha = D3D10_BLEND_ZERO;
	StateDesc.BlendOpAlpha = D3D10_BLEND_OP_ADD;
	StateDesc.RenderTargetWriteMask[0] = D3D10_COLOR_WRITE_ENABLE_ALL;
	_device->CreateBlendState(&StateDesc, &this->_blendStateAlpha);

	DebugOut(L"[INFO] InitDirectX has been successful\n");

	return;
}


/// <summary>
/// 
/// </summary>
void CGraphics::Shutdown()
{
	_blendStateAlpha->Release();
	_spriteHandler->Release();
	_renderTargetView->Release();
	_swapChain->Release();
	_device->Release();
}


/// <summary>
/// 
/// </summary>
/// <param name="id"></param>
/// <param name="texturePath"></param>
void CGraphics::LoadTexture(unsigned int id, std::wstring texturePath)
{
	if (GetTexture(id) == nullptr)
	{
		ID3D10Resource* resource = NULL;
		ID3D10Texture2D* tex = NULL;

		/* Image information */
		D3DX10_IMAGE_INFO imageInfo;
		HRESULT hr = D3DX10GetImageInfoFromFile(texturePath.c_str(), NULL, &imageInfo, NULL);
		if (FAILED(hr))
		{
			DebugOut(L"[ERROR] D3DX10GetImageInfoFromFile failed for  file: %s with error: %d\n", texturePath.c_str(), hr);
			return;
		}

		D3DX10_IMAGE_LOAD_INFO info;
		ZeroMemory(&info, sizeof(D3DX10_IMAGE_LOAD_INFO));
		info.Width = imageInfo.Width;
		info.Height = imageInfo.Height;
		info.Depth = imageInfo.Depth;
		info.FirstMipLevel = 0;
		info.MipLevels = 1;
		info.Usage = D3D10_USAGE_DEFAULT;
		info.BindFlags = D3DX10_DEFAULT;
		info.CpuAccessFlags = D3DX10_DEFAULT;
		info.MiscFlags = D3DX10_DEFAULT;
		info.Format = imageInfo.Format;
		info.Filter = D3DX10_FILTER_NONE;
		info.MipFilter = D3DX10_DEFAULT;
		info.pSrcInfo = &imageInfo;

		// Loads the texture into a temporary ID3D10Resource object
		hr = D3DX10CreateTextureFromFile(_device,
			texturePath.c_str(),
			&info,
			NULL,
			&resource,
			NULL);

		// Make sure the texture was loaded successfully
		if (FAILED(hr))
		{
			DebugOut((wchar_t*)L"[ERROR] Failed to load texture file: %s with error: %d\n", texturePath.c_str(), hr);
			return;
		}

		// Translates the ID3D10Resource object into a ID3D10Texture2D object
		resource->QueryInterface(__uuidof(ID3D10Texture2D), (LPVOID*)&tex);
		resource->Release();

		if (!tex) {
			DebugOut((wchar_t*)L"[ERROR] Failed to convert from ID3D10Resource to ID3D10Texture2D \n");
			return;
		}

		//
		// Create the Share Resource View for this texture 
		// 	   
		// Get the texture details
		D3D10_TEXTURE2D_DESC desc;
		tex->GetDesc(&desc);

		// Create a shader resource view of the texture
		D3D10_SHADER_RESOURCE_VIEW_DESC SRVDesc;

		// Clear out the shader resource view description structure
		ZeroMemory(&SRVDesc, sizeof(SRVDesc));

		// Set the texture format
		SRVDesc.Format = desc.Format;

		// Set the type of resource
		SRVDesc.ViewDimension = D3D10_SRV_DIMENSION_TEXTURE2D;
		SRVDesc.Texture2D.MipLevels = desc.MipLevels;

		ID3D10ShaderResourceView* gSpriteTextureRV = NULL;

		_device->CreateShaderResourceView(tex, &SRVDesc, &gSpriteTextureRV);

		DebugOut(L"[INFO] Texture loaded Ok from file: %s \n", texturePath.c_str());

		_textures[id] = new CTexture(tex, gSpriteTextureRV);
	}
}


/// <summary>
/// 
/// </summary>
/// <param name="id"></param>
/// <returns></returns>
pTexture CGraphics::GetTexture(unsigned int id)
{
	if (_textures.find(id) != _textures.end())
		return _textures[id];
	else
		return nullptr;
}
