#pragma once
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "../Include.h"

#include <Windows.h>

#include <string>
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

class Application
{
public:
	pGameWindow gameWindow;

	Application(HINSTANCE hInstance);
	~Application();

	void CreateGameWindow(LPCWSTR windowTitle, int widthResolution, int heightResolution, bool fullscreen);
	bool HandleMessage();
	void Exit();
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

#endif // !__APPLICATION_H__