#pragma once
#ifndef __VAMPIRE_KILLER_H__
#define __VAMPIRE_KILLER_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class VampireKiller : public GameObject
{
protected:
	pPlayScene playScene;

public:
	VampireKiller(pScene scene);
	~VampireKiller();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__VAMPIRE_KILLER_H__