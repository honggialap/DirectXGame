#pragma once
#ifndef __STAGE3A_BG__
#define __STAGE3A_BG__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Stage3A_BG : public GameObject
{
public:
	pPlayScene playScene;

	Stage3A_BG(pScene scene);
	~Stage3A_BG();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif //!__STAGE3A_BG__