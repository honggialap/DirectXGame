#include "Application.h"

Application* Application::__instance = nullptr;

Application* Application::GetInstance()
{
	if (__instance == nullptr) 
		__instance = new Application();

	return __instance;
}

Application::Application()
{
	hInstance = NULL;
	hWnd = NULL;
}

Application::~Application()
{

}

void Application::Initialize(HINSTANCE hInstance)
{
	this->hInstance = hInstance;
}

void Application::Shutdown()
{

}

HWND Application::CreateGameWindow()
{
    // Register the window class.

    const wchar_t CLASS_NAME[] = L"Game Window";
    const wchar_t WINDOW_TITLE[] = L"Game";

    WNDCLASSEX wcex = { };
    
    wcex.cbClsExtra = 0;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.cbWndExtra = 0;
    wcex.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
    wcex.hCursor = NULL;
    wcex.hIcon = NULL;
    wcex.hIconSm = NULL;
    wcex.hInstance = hInstance;
    wcex.lpfnWndProc = WinProc;
    wcex.lpszClassName = CLASS_NAME;
    //wcex.lpszMenuName
    //wcex.style

    RegisterClassEx(&wcex);


    // Create the window.
    hWnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        WINDOW_TITLE,    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hWnd == NULL)
    {
        return 0;
    }

    ShowWindow(hWnd, SW_SHOWNORMAL);
    UpdateWindow(hWnd);

	return hWnd;
}

bool Application::HandleMessage()
{
    MSG msg = {};
    bool done = false;

    if(PeekMessage(&msg, hWnd, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_DESTROY)
            done = true;

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return done;
}

LRESULT CALLBACK Application::WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}