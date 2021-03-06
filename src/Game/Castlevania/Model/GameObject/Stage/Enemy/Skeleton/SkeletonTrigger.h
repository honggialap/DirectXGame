#pragma once
#ifndef __SKELETON_TRIGGER_H__
#define __SKELETON_TRIGGER_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class SkeletonTrigger : public GameObject
{
public:
	pPlayScene playScene;

	SkeletonTrigger(pScene scene);
	~SkeletonTrigger();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__SKELETON_TRIGGER_H__