#pragma once
#ifndef __ZOMBIE_SPAWN_ZONE_H__
#define __ZOMBIE_SPAWN_ZONE_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class ZombieSpawnZone : public GameObject
{
public:
	pPlayScene playScene;

	ZombieSpawnZone(pScene scene);
	~ZombieSpawnZone();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__ZOMBIE_SPAWN_ZONE_H__