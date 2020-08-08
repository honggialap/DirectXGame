#pragma once
#ifndef __MONEY_BAG_700_H__
#define __MONEY_BAG_700_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class MoneyBag700 : public GameObject
{
public:
	pPlayScene playScene;

	MoneyBag700(pScene scene);
	~MoneyBag700();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__MONEY_BAG_700_H__