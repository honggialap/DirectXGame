#pragma once

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Win32.h"
#include "GameWindow.h"

class Application
{
	//Singleton
private:
	static Application* __instance;
	Application();
public:
	static Application* GetInstance();
	~Application();


	//Win32 API
private:
	HINSTANCE hInstance;
	GameWindow gameWindow;

public:
	HINSTANCE GetAppInstance() { return hInstance; }
	GameWindow GetGameWindow() { return gameWindow; }
	
	HWND CreateGameWindow();
	bool HandleMessage();
	static LRESULT CALLBACK WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	
	//Framework component
public:
	void Initialize(HINSTANCE hInstance);
	void Shutdown();
};

typedef Application* pApplication;

#endif // !__APPLICATION_H__