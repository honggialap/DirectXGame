#pragma once
#ifndef __PORK_CHOP_H__
#define __PORK_CHOP_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class PorkChop : public GameObject
{
public:
	pPlayScene playScene;

	PorkChop(pScene scene);
	~PorkChop();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__PORK_CHOP_H__