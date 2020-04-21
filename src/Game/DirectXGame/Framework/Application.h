#pragma once
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <Windows.h>
#include <string>

#include "Ultilities.h"

using namespace std;

class GameWindow
{
public:
	HINSTANCE hInstance;
	HWND hWnd;
	LPCWSTR windowTitle;
	bool fullscreen;
	int width;
	int height;

	GameWindow();
	~GameWindow();
};

typedef GameWindow* pGameWindow;

class Application
{
public:
	pGameWindow gameWindow;

	Application(HINSTANCE hInstance);
	~Application();

	void CreateGameWindow(LPCWSTR windowTitle, int widthResolution, int heightResolution, bool fullscreen);
	bool HandleMessage();
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

typedef Application* pApplication;

#endif // !__APPLICATION_H__