#pragma once
#ifndef __HIT_EFFECT_H__
#define __HIT_EFFECT_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class HitEffect : public GameObject
{
public:
	pPlayScene playScene;

	HitEffect(pScene scene);
	~HitEffect();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__HIT_EFFECT_H__