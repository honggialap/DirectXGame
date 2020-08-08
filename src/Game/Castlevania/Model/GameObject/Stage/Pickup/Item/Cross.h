#pragma once
#ifndef __CROSS_H__
#define __CROSS_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class Cross : public GameObject
{
public:
	pPlayScene playScene;

	Cross(pScene scene);
	~Cross();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__CROSS_H__