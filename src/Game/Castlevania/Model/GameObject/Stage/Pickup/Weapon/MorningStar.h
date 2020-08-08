#pragma once
#ifndef __MORNING_STAR_H__
#define __MORNING_STAR_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class MorningStar : public GameObject
{
public:
	pPlayScene playScene;

	MorningStar(pScene scene);
	~MorningStar();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__MORNING_STAR_H__