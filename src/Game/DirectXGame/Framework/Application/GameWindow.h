#pragma once

#ifndef __GAME_WINDOW_H__
#define __GAME_WINDOW_H__

#include "Win32.h"
#include <string>

class Application;

class GameWindow
{
private:
	HWND hWnd;
	std::wstring title;
	bool fullscreen;
	int width;
	int height;

public:
	GameWindow();
	~GameWindow();

	HWND GetWindow() { return hWnd; }
	std::wstring GetTitle() { return title; }
	bool IsFullscreen() { return fullscreen; }
	int GetWidth() { return width; }
	int GetHeight() { return height; }

	friend class Application;
};

#endif // !__GAME_WINDOW_H__