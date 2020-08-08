#pragma once
#ifndef __TRIPLE_SHOT_H__
#define __TRIPLE_SHOT_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class TripleShot : public GameObject
{
public:
	pPlayScene playScene;

	TripleShot(pScene scene);
	~TripleShot();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__TRIPLE_SHOT_H__