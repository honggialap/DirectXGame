#pragma once
#ifndef __RAVEN_TRIGGER_H__
#define __RAVEN_TRIGGER_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class RavenTrigger : public GameObject
{
public:
	pPlayScene playScene;

	RavenTrigger(pScene scene);
	~RavenTrigger();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__RAVEN_TRIGGER_H__