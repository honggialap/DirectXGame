#pragma once
#ifndef __MARIO_SAMPLE_H__
#define __MARIO_SAMPLE_H__

#pragma region INCLUDE
#include "../Engine/GameObject.h"
#pragma endregion

#pragma region DEFINE
/* SPRITE ID */
#define BBOX					9990

#define SPR_MARIO_IDLE_LEFT		1001
#define SPR_MARIO_WALK_LEFT		1002
#define SPR_MARIO_JUMP_LEFT		1003

#define SPR_MARIO_IDLE_RIGHT	1101
#define SPR_MARIO_WALK_RIGHT	1102
#define SPR_MARIO_JUMP_RIGHT	1103

/* ANIMATION ID */
#define ANI_MARIO_WALK_LEFT		1001
#define ANI_MARIO_WALK_RIGHT	1101
#pragma endregion

class CMarioSample : public CGameObject
{
public:
	CMarioSample(
		pGame game, pScene scene,
		unsigned int id, std::string name, std::string source,
		float x, float y, int gx, int gy, unsigned int layer
	) : CGameObject(game, scene, id, name, source, x, y, gx, gy, layer) {};

	virtual void Load();
	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};
typedef CMarioSample* pMarioSample;

#endif // !__MARIO_SAMPLE_H__
