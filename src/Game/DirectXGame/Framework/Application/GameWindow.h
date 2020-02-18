#pragma once

#ifndef __GAME_WINDOW_H__
#define __GAME_WINDOW_H__

#include "Application.h"

class GameWindow
{
private:
	HWND hWnd;
	//WString title;
	bool fullscreen;
	int width;
	int height;

public:
	HWND GetWindow() { return hWnd; }
	//WString GetTitle() { return title; }
	bool IsFullscreen() { return fullscreen; }
	int GetWidth() { return width; }
	int GetHeight() { return height; }

	friend class Application;
};

#endif // !__GAME_WINDOW_H__