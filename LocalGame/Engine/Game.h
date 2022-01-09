#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#pragma region INCLUDE
#include "Application.h"
#include "Time.h"
#include "pugixml.hpp"
#pragma endregion

/// <summary>
/// Handling game loop.
/// </summary>
class CGame
{
private:
	/* Framework */
	pApplication _application;
	pTime _time;

	/* Stats */
	unsigned int _framePerSecond = 0;

public:
	CGame();
	~CGame();

	/* Game loop */
	void Load(HINSTANCE hInstance, std::string gameDataPath);
	void Run();
};
typedef CGame* pGame;

#endif // !__GAME_H__