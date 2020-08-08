#pragma once
#ifndef __MONEY_BAG_100_H__
#define __MONEY_BAG_100_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class MoneyBag100 : public GameObject
{
public:
	pPlayScene playScene;

	MoneyBag100(pScene scene);
	~MoneyBag100();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__MONEY_BAG_100_H__