#pragma once
#ifndef __COIN_SAMPLE_H__
#define __COIN_SAMPLE_H__

#pragma region INCLUDE
#include "../Engine/GameObject.h"
#pragma endregion

#pragma region DEFINE
/* SPRITE ID */
#define BBOX			9990

#define SPR_COIN1		1001
#define SPR_COIN2		1002
#define SPR_COIN3		1003
#define SPR_COIN4		1004
#define SPR_COIN5		1005
#define SPR_COIN6		1006

/* ANIMATION ID */
#define ANI_COIN		1001
#pragma endregion

class CCoinSample : public CGameObject
{
public:
	CCoinSample(
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
typedef CCoinSample* pCoinSample;

#endif // !__COIN_SAMPLE_H__
