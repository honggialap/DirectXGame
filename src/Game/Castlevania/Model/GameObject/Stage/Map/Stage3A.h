#pragma once
#ifndef __STAGE3A_H__
#define __STAGE3A_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Stage3A : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Stage3A(pScene scene);
	~Stage3A();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__STAGE3A_H__