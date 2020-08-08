#pragma once
#ifndef __MAGIC_CRYSTAL_H__
#define __MAGIC_CRYSTAL_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class MagicCrystal : public GameObject
{
public:
	pPlayScene playScene;

	MagicCrystal(pScene scene);
	~MagicCrystal();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__MAGIC_CRYSTAL_H__