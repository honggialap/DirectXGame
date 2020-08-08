#pragma once
#ifndef __TREASURE_CHEST_H__
#define __TREASURE_CHEST_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class TreasureChest : public GameObject
{
public:
	pPlayScene playScene;

	TreasureChest(pScene scene);
	~TreasureChest();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__TREASURE_CHEST_H__