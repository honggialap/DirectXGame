#pragma once
#ifndef __STAGE1_H__
#define __STAGE1_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Stage1 : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Stage1(pScene scene);
	~Stage1();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__STAGE1_H__