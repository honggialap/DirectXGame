#pragma once
#ifndef __MARIO_SAMPLE_H__
#define __MARIO_SAMPLE_H__

#include "Include.h"

#include "../DirectXGame/Game.h"
#include "Model/DemoScene.h"

class MarioSample : public Game
{
public:
	MarioSample(HINSTANCE hInstance);
	void Load(LPCWSTR dataFilePath);
	void LoadScenes(LPCWSTR dataFilePath);
};
#endif // !__MARIO_SAMPLE_H__
