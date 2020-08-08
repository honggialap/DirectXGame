#pragma once
#ifndef __HUNCHBACK_H__
#define __HUNCHBACK_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class Hunchback : public GameObject
{
public:
	pPlayScene playScene;

	Hunchback(pScene scene);
	~Hunchback();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__HUNCHBACK_H__