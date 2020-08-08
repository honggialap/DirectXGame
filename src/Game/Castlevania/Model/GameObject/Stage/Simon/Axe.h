#pragma once
#ifndef __AXE_H__
#define __AXE_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Axe : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Axe(pScene scene);
	~Axe();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__AXE_H__