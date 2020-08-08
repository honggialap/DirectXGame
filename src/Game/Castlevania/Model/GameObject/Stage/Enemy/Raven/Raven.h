#pragma once
#ifndef __RAVEN_H__
#define __RAVEN_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class Raven : public GameObject
{
public:
	pPlayScene playScene;

	Raven(pScene scene);
	~Raven();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__RAVEN_H__