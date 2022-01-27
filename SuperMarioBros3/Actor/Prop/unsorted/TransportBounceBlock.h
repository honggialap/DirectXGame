#pragma once
#ifndef __TRANSPORT_BOUNCE_BLOCK_H__
#define __TRANSPORT_BOUNCE_BLOCK_H__

#pragma region INCLUDE
#include "../../Engine/GameObject.h"
#pragma endregion

#pragma region DEFINE
/* SPRITE ID */
/* ANIMATION ID */
/* SOUNDCLIP ID */
#pragma endregion

class CTransportBounceBlock : public CGameObject
{
public:
	CTransportBounceBlock(
		pGame game, pScene scene,
		unsigned int id, std::string name, std::string source,
		float x, float y, int gx, int gy, unsigned int layer
	) : CGameObject(game, scene, id, name, source, x, y, gx, gy, layer) {};

public:
	virtual void Load();
	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual int IsCollidable();
	virtual int IsBlocking();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};
typedef CTransportBounceBlock* pTransportBounceBlock;

#endif // !__TRANSPORT_BOUNCE_BLOCK_H__