#pragma once
#ifndef __GHOST_TRIGGER_H_
#define __GHOST_TRIGGER_H_

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class GhostTrigger : public GameObject
{
public:
	pPlayScene playScene;

	GhostTrigger(pScene scene);
	~GhostTrigger();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__GHOST_TRIGGER_H_