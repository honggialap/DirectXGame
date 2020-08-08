#pragma once
#ifndef __STAGE4_H__
#define __STAGE4_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Stage4 : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Stage4(pScene scene);
	~Stage4();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__STAGE4_H__