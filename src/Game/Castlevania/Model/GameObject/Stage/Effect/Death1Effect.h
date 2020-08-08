#pragma once
#ifndef __DEATH_1_EEFECT_H__
#define __DEATH_1_EEFECT_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Death1Effect : public GameObject
{
public:
	pPlayScene playScene;

	Death1Effect(pScene scene);
	~Death1Effect();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__DEATH_1_EEFECT_H__