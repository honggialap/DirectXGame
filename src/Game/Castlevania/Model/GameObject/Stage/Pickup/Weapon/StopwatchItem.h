#pragma once
#ifndef __STOPWATCH_ITEM_H__
#define __STOPWATCH_ITEM_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class StopwatchItem : public GameObject
{
public:
	pPlayScene playScene;

	StopwatchItem(pScene scene);
	~StopwatchItem();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__STOPWATCH_ITEM_H__