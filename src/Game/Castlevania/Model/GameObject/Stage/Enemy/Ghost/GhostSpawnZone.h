#pragma once
#ifndef __GHOST_SPAWN_ZONE_H__
#define __GHOST_SPAWN_ZONE_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class GhostSpawnZone : public GameObject
{
public:
	pPlayScene playScene;

	GhostSpawnZone(pScene scene);
	~GhostSpawnZone();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__GHOST_SPAWN_ZONE_H__