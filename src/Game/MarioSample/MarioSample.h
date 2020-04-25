#pragma once
#ifndef __MARIO_SAMPLE_H__
#define __MARIO_SAMPLE_H__

#include "../DirectXGame/Game.h"

class MarioSample : public Game
{
public:
	MarioSample(HINSTANCE hInstance);
	void Load(LPCWSTR dataFilePath);
};
#endif // !__MARIO_SAMPLE_H__
