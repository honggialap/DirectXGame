#include "Application.h"
#include "Debug.h"

/// <summary>
/// Create game window.
/// </summary>
/// <param name="hInstance">- Window process handler, pass by WinMain.</param>
/// <param name="title">- Window title.</param>
/// <param name="width">- Window width, border included.</param>
/// <param name="height">- Window height, border included.</param>
/// <returns>If create success return window handler, else return NULL</returns>
HWND CApplication::CreateGameWindow(HINSTANCE hInstance, std::wstring title, unsigned int width, unsigned int height)
{
	_hInstance = hInstance;

	/* Register Window Class */
	WNDCLASSEX wcex;
	wcex = {};
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.hInstance = hInstance;
	wcex.lpfnWndProc = (WNDPROC)WinProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"GameWindow";
	wcex.hIconSm = NULL;
	RegisterClassEx(&wcex);

	/* Create Window */
	_hWnd = CreateWindowEx
	(
		0,
		L"GameWindow",
		title.c_str(),
		WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT,
		width, height,
		NULL, NULL,
		hInstance,
		NULL
	);

	if (!_hWnd)
	{
		DebugOut(L"[FRAMEWORK] Application - Create game window failed.\n");

		return NULL;
	}
	else
	{
		DebugOut(L"[FRAMEWORK] Application - Create game window successed.\n");

		ShowWindow(_hWnd, SW_SHOWNORMAL);
		UpdateWindow(_hWnd);
		return _hWnd;
	}
}


/// <summary>
/// Send Exit code to Window Message Loop.
/// </summary>
void CApplication::Exit()
{
	DebugOut(L"[FRAMEWORK] Application - Exit message called.\n");

	SendMessage(_hWnd, WM_DESTROY, 0, 0);
}


/// <summary>
/// Modified Window Message Loop for real-time application.
/// </summary>
/// <returns>Return true if Exit message is called.</returns>
bool CApplication::HandleMessage()
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


/// <summary>
/// Window Procedure callback function.
/// </summary>
LRESULT CApplication::WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;

	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}
}
