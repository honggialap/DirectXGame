#pragma once
#ifndef __MONEY_BAG_1000_H__
#define __MONEY_BAG_1000_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class MoneyBag1000 : public GameObject
{
public:
	pPlayScene playScene;

	MoneyBag1000(pScene scene);
	~MoneyBag1000();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__MONEY_BAG_1000_H__