#pragma once
#ifndef __GHOST_H_
#define __GHOST_H_

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class Ghost : public GameObject
{
public:
	pPlayScene playScene;

	Ghost(pScene scene);
	~Ghost();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__GHOST_H_