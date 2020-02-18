#pragma once

#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>

#include "Framework/Application/Application.h"
#include "Framework/Time/Time.h"
//#include "Framework/Graphics/Graphics.h"
//#include "Framework/Audio/Audio.h"
//#include "Framework/Input/Input.h"

class Game
{
protected:
	pApplication application;
	pTime time;
	//pGraphics graphics;
	//pAudio audio;
	//pInput input;

public:
	Game();
	~Game();

	void Initialize(HINSTANCE hInstance);
	void Shutdown();

	void Run();
	void Update();
	void Render();
};

#endif //!__GAME_H__