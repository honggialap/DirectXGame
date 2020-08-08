#pragma once
#ifndef __SKELETON_H__
#define __SKELETON_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class Skeleton : public GameObject
{
public:
	pPlayScene playScene;

	Skeleton(pScene scene);
	~Skeleton();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__SKELETON_H__