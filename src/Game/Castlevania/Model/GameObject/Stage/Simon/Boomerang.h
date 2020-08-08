#pragma once
#ifndef __BOOMERANG_H__
#define __BOOMERANG_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Boomerang : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Boomerang(pScene scene);
	~Boomerang();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__BOOMERANG_H__