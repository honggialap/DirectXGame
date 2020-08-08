#pragma once
#ifndef __FIREBOMB_ITEM_H__
#define __FIREBOMB_ITEM_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class FirebombItem : public GameObject
{
public:
	pPlayScene playScene;

	FirebombItem(pScene scene);
	~FirebombItem();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__FIREBOMB_ITEM_H__