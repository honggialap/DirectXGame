#pragma once
#ifndef __LARGE_HEART_H__
#define __LARGE_HEART_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class LargeHeart : public GameObject
{
public:
	pPlayScene playScene;

	LargeHeart(pScene scene);
	~LargeHeart();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__LARGE_HEART_H__