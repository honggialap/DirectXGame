#pragma once
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "../Include.h"

struct GameWindow
{
	HINSTANCE hInstance;
	HWND hWnd;
	LPCWSTR windowTitle;
	bool fullscreen;
	int width;
	int height;
};

class Application
{
public:
	Application(HINSTANCE hInstance);
	~Application();

	pGameWindow gameWindow;
	void CreateGameWindow(LPCWSTR windowTitle, int widthResolution, int heightResolution, bool fullscreen);

	bool HandleMessage();
	void Exit();
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

#endif // !__APPLICATION_H__