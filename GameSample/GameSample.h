#pragma once
#ifndef __GAME_SAMPLE_H__
#define __GAME_SAMPLE_H__

#pragma region INCLUDE
#include "Engine/Game.h"
#pragma endregion

#pragma region DEFINE
/* ACTOR ID*/
#define ACT_GAMEMASTER_SAMPLE	1001
#define ACT_MARIO_SAMPLE		2001
#define ACT_GOOMBA_SAMPLE		3001
#define ACT_COIN_SAMPLE			4001
#define ACT_BRICK_SAMPLE		5001
#define ACT_PORTAL_SAMPLE		6001
#pragma endregion

class CGameSample : public CGame
{
public:
	pGameObject Create(
		pScene scene,
		unsigned int actor, std::string name, std::string source,
		float posX, float posY, int gridX, int gridY,
		unsigned int layer
	);
};

#endif // !__GAME_SAMPLE_H__
