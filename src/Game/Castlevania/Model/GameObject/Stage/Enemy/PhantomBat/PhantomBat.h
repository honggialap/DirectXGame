#pragma once
#ifndef __PHANTOM_BAT_H__
#define __PHANTOM_BAT_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class PhantomBat : public GameObject
{
public:
	pPlayScene playScene;

	PhantomBat(pScene scene);
	~PhantomBat();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__PHANTOM_BAT_H__