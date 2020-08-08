#pragma once
#ifndef __BOOMERANG_ITEM_H__
#define __BOOMERANG_ITEM_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class BoomerangItem : public GameObject
{
public:
	pPlayScene playScene;

	BoomerangItem(pScene scene);
	~BoomerangItem();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__BOOMERANG_ITEM_H__