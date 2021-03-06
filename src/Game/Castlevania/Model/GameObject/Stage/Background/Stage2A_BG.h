#pragma once
#ifndef __STAGE2A_BG__
#define __STAGE2A_BG__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Stage2A_BG : public GameObject
{
public:
	pPlayScene playScene;

	Stage2A_BG(pScene scene);
	~Stage2A_BG();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif //!__STAGE2A_BG__