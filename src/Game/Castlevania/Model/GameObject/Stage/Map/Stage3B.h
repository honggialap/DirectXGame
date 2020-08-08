#pragma once
#ifndef __STAGE3B_H__
#define __STAGE3B_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Stage3B : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Stage3B(pScene scene);
	~Stage3B();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__STAGE3B_H__