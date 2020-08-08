#pragma once
#ifndef __SKELETON_BONE_H__
#define __SKELETON_BONE_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class SkeletonBone : public GameObject
{
public:
	pPlayScene playScene;

	SkeletonBone(pScene scene);
	~SkeletonBone();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__SKELETON_BONE_H__