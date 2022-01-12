#pragma once
#ifndef __GOOMBA_SAMPLE_H__
#define __GOOMBA_SAMPLE_H__

#pragma region INCLUDE
#include "../Engine/GameObject.h"
#pragma endregion

#pragma region DEFINE
/* SPRITE ID */
#define BBOX				9990

#define SPR_GOOMBA1			1001
#define SPR_GOOMBA2			1002
#define SPR_GOOMBA3			1003
#define SPR_GOOMBA_WING1	1004
#define SPR_GOOMBA_WING2	1005

/* ANIMATION ID */
#define ANI_GOOMBA_WALK		1001
#define ANI_GOOMBA_WING		1002
#pragma endregion

class CGoombaSample : public CGameObject
{
public:
	CGoombaSample(
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
typedef CGoombaSample* pGoombaSample;

#endif // !__GOOMBA_SAMPLE_H__
