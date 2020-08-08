#pragma once
#ifndef __FIREBALL_H__
#define __FIREBALL_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class Fireball : public GameObject
{
public:
	pPlayScene playScene;

	Fireball(pScene scene);
	~Fireball();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__FIREBALL_H__