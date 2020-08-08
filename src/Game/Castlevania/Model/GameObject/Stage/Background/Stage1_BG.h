#pragma once
#ifndef __STAGE1_BG__
#define __STAGE1_BG__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Stage1_BG : public GameObject
{
public:
	pPlayScene playScene;

	Stage1_BG(pScene scene);
	~Stage1_BG();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif //!__STAGE1_BG__