#pragma once
#ifndef __SUPER_MARIO_BROS_3_H__
#define __SUPER_MARIO_BROS_3_H__

#pragma region INCLUDE
#include "Engine/Game.h"
#pragma endregion

#pragma region ACTOR ID
/* Controller */
/* Character */

#define ACT_MARIO				20101
#define ACT_MARIO_TAIL			20102
#define ACT_MARIO_FIREBALL		20103

/* Item */
/* Prop */

#define ACT_PLATFORM			40101

/* Misc */
/* Title */
/* World Map */
#pragma endregion

class CSuperMarioBros3 : public CGame
{
public:
	pGameObject Create(
		pScene scene,
		unsigned int actor, std::string name, std::string source,
		float posX, float posY, int gridX, int gridY,
		unsigned int layer
	);
};
typedef CSuperMarioBros3* pSuperMarioBros3;

#endif // !__SUPER_MARIO_BROS_3_H__
