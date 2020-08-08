#pragma once
#ifndef __STAGE4_BG__
#define __STAGE4_BG__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Stage4_BG : public GameObject
{
public:
	pPlayScene playScene;

	Stage4_BG(pScene scene);
	~Stage4_BG();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif //!__STAGE4_BG__