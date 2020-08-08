#pragma once
#ifndef __INTRO_BG__
#define __INTRO_BG__

#include "../../../Include.h"
#include "../../../Castlevania.h"

class Intro_BG : public GameObject
{
public:
	pPlayScene playScene;

	Intro_BG(pScene scene);
	~Intro_BG();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif //!__INTRO_BG__