#pragma once
#ifndef __EXTRA_LIFE_H__
#define __EXTRA_LIFE_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class ExtraLife : public GameObject
{
public:
	pPlayScene playScene;

	ExtraLife(pScene scene);
	~ExtraLife();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__EXTRA_LIFE_H__