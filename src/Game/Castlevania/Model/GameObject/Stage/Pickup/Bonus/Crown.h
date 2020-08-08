#pragma once
#ifndef __CROWN_H__
#define __CROWN_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class Crown : public GameObject
{
public:
	pPlayScene playScene;

	Crown(pScene scene);
	~Crown();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__CROWN_H__