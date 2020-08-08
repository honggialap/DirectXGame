#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class Zombie : public GameObject
{
public:
	pPlayScene playScene;

	Zombie(pScene scene);
	~Zombie();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__ZOMBIE_H__