#pragma once
#ifndef __DAGGER_H__
#define __DAGGER_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Dagger : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Dagger(pScene scene);
	~Dagger();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__DAGGER_H__