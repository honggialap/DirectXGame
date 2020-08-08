#pragma once
#ifndef __STAGE3B_BG__
#define __STAGE3B_BG__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Stage3B_BG : public GameObject
{
public:
	pPlayScene playScene;

	Stage3B_BG(pScene scene);
	~Stage3B_BG();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif //!__STAGE3B_BG__