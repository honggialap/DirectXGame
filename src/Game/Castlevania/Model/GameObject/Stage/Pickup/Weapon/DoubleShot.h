#pragma once
#ifndef __DOUBLE_SHOT_H__
#define __DOUBLE_SHOT_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class DoubleShot : public GameObject
{
public:
	pPlayScene playScene;

	DoubleShot(pScene scene);
	~DoubleShot();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__DOUBLE_SHOT_H__