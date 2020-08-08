#pragma once
#ifndef __FIREBOMB_H__
#define __FIREBOMB_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Firebomb : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Firebomb(pScene scene);
	~Firebomb();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__FIREBOMB_H__