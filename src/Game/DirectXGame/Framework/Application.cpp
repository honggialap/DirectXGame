#include "Application.h"

#pragma region GameWindow

GameWindow::GameWindow()
{
	hInstance = NULL;
	hWnd = NULL;
	windowTitle = NULL;
	fullscreen = {};
	width = {};
	height = {};
}

GameWindow::~GameWindow()
{
}

#pragma endregion

#pragma region Application

Application::Application(HINSTANCE hInstance)
{
	this->gameWindow = new GameWindow();
	gameWindow->hInstance = hInstance;
}

Application::~Application()
{
	if (gameWindow != nullptr)
	{
		delete gameWindow;
		gameWindow = nullptr;
	}
}

void Application::CreateGameWindow(LPCWSTR windowTitle, int widthResolution, int heightResolution, bool fullscreen)
{
	gameWindow->windowTitle = windowTitle;
	gameWindow->fullscreen = fullscreen;
	gameWindow->width = widthResolution;
	gameWindow->height = heightResolution;

	// Register the window class.
	const wchar_t CLASS_NAME[] = L"Game Window";

	WNDCLASSEX wcex = { };
	wcex.cbClsExtra = 0;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.cbWndExtra = 0;
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.hCursor = NULL;
	wcex.hIcon = NULL;
	wcex.hIconSm = NULL;
	wcex.hInstance = gameWindow->hInstance;
	wcex.lpfnWndProc = WinProc;
	wcex.lpszClassName = CLASS_NAME;
	wcex.lpszMenuName = NULL;
	wcex.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&wcex);

	// Create the window
	DWORD windowStyle;
	int windowWidth = 0;
	int windowHeight = 0;

	if (gameWindow->fullscreen == true)
	{
		windowStyle = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
		windowWidth = widthResolution;
		windowHeight = heightResolution;
	}
	else
	{
		windowStyle = WS_OVERLAPPEDWINDOW;
		//add border size
		windowWidth = widthResolution + 16;
		windowHeight = heightResolution + 39;
	}

	HWND hWnd = CreateWindowEx(
		0,										// Optional window styles.
		CLASS_NAME,								// Window class
		gameWindow->windowTitle,				// Window text
		windowStyle,							// Window style
		CW_USEDEFAULT, CW_USEDEFAULT,			// Position
		windowWidth, windowHeight,				// Size
		NULL,									// Parent window    
		NULL,									// Menu
		gameWindow->hInstance,								// Instance handle
		NULL									// Additional application data
	);

	if (hWnd == NULL)
	{
		OutputDebugString(L"[ERROR] Create game window failed.\n");
	}
	else
	{
		gameWindow->hWnd = hWnd;
		OutputDebugString(L"[INFO] Create game window successed.\n");

		ShowWindow(gameWindow->hWnd, SW_SHOWNORMAL);
		UpdateWindow(gameWindow->hWnd);
	}
}

bool Application::HandleMessage()
{
	MSG msg = {};
	bool done = false;

	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{

		if (msg.message == WM_QUIT)
			done = true;

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return done;
}

void Application::Exit()
{
	SendMessage(gameWindow->hWnd, WM_QUIT, 0, 0);
}

LRESULT Application::WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

#pragma endregion