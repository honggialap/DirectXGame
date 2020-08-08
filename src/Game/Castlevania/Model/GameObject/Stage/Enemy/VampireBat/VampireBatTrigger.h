#pragma once
#ifndef __VAMPIRE_BAT_TRIGGER_H__
#define __VAMPIRE_BAT_TRIGGER_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class VampireBatTrigger : public GameObject
{
public:
	pPlayScene playScene;

	VampireBatTrigger(pScene scene);
	~VampireBatTrigger();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__VAMPIRE_BAT_TRIGGER_H__