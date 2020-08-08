#pragma once
#ifndef __POTION_H__
#define __POTION_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class Potion : public GameObject
{
public:
	pPlayScene playScene;

	Potion(pScene scene);
	~Potion();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__POTION_H__