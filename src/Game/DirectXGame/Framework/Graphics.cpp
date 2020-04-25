#include "Graphics.h"

GraphicsDevice::GraphicsDevice()
{
	direct3D = NULL;
	device = NULL;
	presentParameters = {};
	backBuffer = NULL;
	spriteHandler = NULL;
}

GraphicsDevice::~GraphicsDevice()
{
	if (spriteHandler != NULL) spriteHandler->Release();
	spriteHandler = NULL;

	if (backBuffer != NULL) backBuffer->Release();
	backBuffer = NULL;

	if (device != NULL) device->Release();
	device = NULL;

	if (direct3D != NULL) direct3D->Release();
	direct3D = NULL;
}

Graphics::Graphics()
{
	graphicsDevice = new GraphicsDevice();
}

Graphics::~Graphics()
{
	delete graphicsDevice;
	graphicsDevice = nullptr;
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

void Graphics::Draw(pSprite sprite)
{
	graphicsDevice->spriteHandler->Draw(
		sprite->texture->texture,
		&(sprite->sourceRect),
		NULL,
		NULL,
		sprite->texture->transparentColor);
}

void Graphics::Draw(pAnimation animation)
{
}