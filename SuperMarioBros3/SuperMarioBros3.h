#pragma once
#ifndef __SUPER_MARIO_BROS_3_H__
#define __SUPER_MARIO_BROS_3_H__

#pragma region INCLUDE
#include "Engine/Game.h"
#pragma endregion


#pragma region ACTOR ID
/* Controller */
#define ACT_GAMEMASTER			10001

/* Character */
#define ACT_MARIO				20101
#define ACT_MARIO_TAIL			20102
#define ACT_MARIO_FIREBALL		20103

#define ACT_GOOMBA				20201
#define ACT_GOOMBA_MICRO		20202

#define ACT_KOOPA				20301
#define ACT_KOOPA_SENSOR		20302

#define ACT_PIRANHA				20401
#define ACT_PIRANHA_SENSOR		20402

#define ACT_VENUS				20501
#define ACT_VENUS_SENSOR		20502
#define ACT_FIREBALL			20503

/* Item */
#define ACT_COIN				30100
#define ACT_EXTRALIFE_MUSHROOM	30200
#define ACT_SUPER_MUSHROOM		30300
#define ACT_SUPER_LEAF			30400
#define ACT_FIRE_FLOWER			30500
#define ACT_SUPER_STAR			30600

/* Prop */
#define ACT_PLATFORM			40100
#define ACT_BRICK				40200
#define ACT_BLOCK				40300

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