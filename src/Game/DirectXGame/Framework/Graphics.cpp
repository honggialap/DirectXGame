#include "Graphics.h"

Graphics::Graphics()
{
	graphicsDevice = new GraphicsDevice();
	graphicsDevice->direct3D = NULL;
	graphicsDevice->device = NULL;
	graphicsDevice->presentParameters = {};
	graphicsDevice->backBuffer = NULL;
	graphicsDevice->spriteHandler = NULL;
}

Graphics::~Graphics()
{
	if (graphicsDevice->spriteHandler != NULL) graphicsDevice->spriteHandler->Release();
	graphicsDevice->spriteHandler = NULL;

	if (graphicsDevice->backBuffer != NULL) graphicsDevice->backBuffer->Release();
	graphicsDevice->backBuffer = NULL;

	if (graphicsDevice->device != NULL) graphicsDevice->device->Release();
	graphicsDevice->device = NULL;

	if (graphicsDevice->direct3D != NULL) graphicsDevice->direct3D->Release();
	graphicsDevice->direct3D = NULL;

	if (graphicsDevice != nullptr)
	{
		delete graphicsDevice;
		graphicsDevice = nullptr;
	}
}

void Graphics::CreateGraphicsDevice(pGameWindow gameWindow)
{
	//create Direct3D object
	graphicsDevice->direct3D = Direct3DCreate9(D3D_SDK_VERSION);

	//instanciate Present Parameters
	ZeroMemory(&(graphicsDevice->presentParameters), sizeof(graphicsDevice->presentParameters));
	if(gameWindow->fullscreen == true)
		graphicsDevice->presentParameters.Windowed = FALSE;
	else
		graphicsDevice->presentParameters.Windowed = TRUE;
	graphicsDevice->presentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	graphicsDevice->presentParameters.BackBufferFormat = D3DFMT_X8R8G8B8;
	graphicsDevice->presentParameters.BackBufferCount = 1;
	graphicsDevice->presentParameters.BackBufferWidth = gameWindow->width;
	graphicsDevice->presentParameters.BackBufferHeight = gameWindow->height;

	//create Direct3D Device object
	graphicsDevice->direct3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		gameWindow->hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&graphicsDevice->presentParameters,
		&graphicsDevice->device);
	if (graphicsDevice->device == NULL)
	{
		OutputDebugString(L"[ERROR] Create graphics device failed.\n");
	}

	//Create back buffer
	graphicsDevice->device->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &graphicsDevice->backBuffer);

	//Create sprite helper
	D3DXCreateSprite(graphicsDevice->device, &graphicsDevice->spriteHandler);

	OutputDebugString(L"[INFO] Create graphics device successed.\n");
}

void Graphics::Draw(float x, float y, pSprite sprite,
	bool flipX, bool flipY, int alpha)
{
	D3DXMATRIX mat;
	
	float ix = 1;
	if (flipX) ix = -1;

	float iy = 1;
	if (flipY) iy = -1;

	D3DXMatrixScaling(&mat, ix, iy, 0);
	graphicsDevice->spriteHandler->SetTransform(&mat);
	x *= ix;
	y *= iy;

	D3DXVECTOR3 renderPosition(x, y, 0);
	graphicsDevice->spriteHandler->Draw(
		(sprite->texture->texture),
		&(sprite->sourceRect),
		&(sprite->center),
		&renderPosition,
		D3DCOLOR_ARGB(
			alpha,
			sprite->texture->r,
			sprite->texture->g,
			sprite->texture->b));
	D3DXMatrixScaling(&mat, ix, iy, 0);
}