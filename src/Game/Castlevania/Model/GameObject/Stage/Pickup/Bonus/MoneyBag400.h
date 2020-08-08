#pragma once
#ifndef __MONEY_BAG_400_H__
#define __MONEY_BAG_400_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class MoneyBag400 : public GameObject
{
public:
	pPlayScene playScene;

	MoneyBag400(pScene scene);
	~MoneyBag400();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__MONEY_BAG_400_H__