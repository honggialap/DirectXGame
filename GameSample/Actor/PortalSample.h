#pragma once
#ifndef __PORTAL_SAMPLE_H__
#define __PORTAL_SAMPLE_H__

#pragma region INCLUDE
#include "../Engine/GameObject.h"
#pragma endregion

#pragma region DEFINE
/* SPRITE ID */
#define BBOX			9990
#pragma endregion

class CPortalSample : public CGameObject
{
public:
	CPortalSample(
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
typedef CPortalSample* pPortalSample;

#endif // !__PORTAL_SAMPLE_H__
