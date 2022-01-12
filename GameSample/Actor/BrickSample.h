#pragma once
#ifndef __BRICK_SAMPLE_H__
#define __BRICK_SAMPLE_H__

#pragma region INCLUDE
#include "../Engine/GameObject.h"
#pragma endregion

#pragma region DEFINE
/* SPRITE ID */
#define BBOX			9990

#define SPR_BRICK1		1001
#define SPR_BRICK2		1002
#define SPR_BRICK3		1003
#define SPR_BRICK4		1004

/* ANIMATION ID */
#define ANI_BRICK		1001
#pragma endregion

class CBrickSample : public CGameObject
{
public:
	CBrickSample(
		pGame game, pScene scene,
		unsigned int id, std::string name, std::string source,
		float x, float y, int gx, int gy, unsigned int layer
	) : CGameObject(game, scene, id, name, source, x, y, gx, gy, layer) {};

public:
	virtual void Load();
	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	/* BODY */
	bool _renderBody = false;
	float BODY_WIDTH = 0;
	float BODY_HEIGHT = 0;
	float BODY_OFFSETX = 0;
	float BODY_OFFSETY = 0;

	virtual int IsCollidable();
	virtual int IsBlocking();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};
typedef CBrickSample* pBrickSample;

#endif // !__BRICK_SAMPLE_H__
