#pragma once
#ifndef __STAGE2B_H__
#define __STAGE2B_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Stage2B : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Stage2B(pScene scene);
	~Stage2B();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__STAGE2B_H__