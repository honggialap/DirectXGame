#pragma once
#ifndef __SMALL_HEART_H__
#define __SMALL_HEART_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class SmallHeart : public GameObject
{
public:
	pPlayScene playScene;

	SmallHeart(pScene scene);
	~SmallHeart();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__SMALL_HEART_H__