#pragma once
#ifndef __HUNCHBACK_TRIGGER_H__
#define __HUNCHBACK_TRIGGER_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class HunchbackTrigger : public GameObject
{
public:
	pPlayScene playScene;

	HunchbackTrigger(pScene scene);
	~HunchbackTrigger();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__HUNCHBACK_TRIGGER_H__