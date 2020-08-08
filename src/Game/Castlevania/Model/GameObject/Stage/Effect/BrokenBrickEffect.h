#pragma once
#ifndef __BROKEN_BRICK_EFFECT_H__
#define __BROKEN_BRICK_EFFECT_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class BrokenBrickEffect : public GameObject
{
public:
	pPlayScene playScene;

	BrokenBrickEffect(pScene scene);
	~BrokenBrickEffect();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__BROKEN_BRICK_EFFECT_H__