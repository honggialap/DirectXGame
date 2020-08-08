#pragma once
#ifndef __STAGE2A_H__
#define __STAGE2A_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Stage2A : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Stage2A(pScene scene);
	~Stage2A();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__STAGE2A_H__