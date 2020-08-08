#pragma once
#ifndef __STOPWATCH_H__
#define __STOPWATCH_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Stopwatch : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Stopwatch(pScene scene);
	~Stopwatch();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__STOPWATCH_H__