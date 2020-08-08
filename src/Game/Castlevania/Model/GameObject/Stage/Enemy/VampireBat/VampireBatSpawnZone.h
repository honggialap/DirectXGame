#pragma once
#ifndef __VAMPIRE_BAT_SPAWN_ZONE_H__
#define __VAMPIRE_BAT_SPAWN_ZONE_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class VampireBatSpawnZone : public GameObject
{
public:
	pPlayScene playScene;

	VampireBatSpawnZone(pScene scene);
	~VampireBatSpawnZone();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__VAMPIRE_BAT_SPAWN_ZONE_H__