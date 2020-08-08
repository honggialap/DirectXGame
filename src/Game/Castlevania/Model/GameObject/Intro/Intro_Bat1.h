#pragma once
#ifndef __INTRO_BAT1__
#define __INTRO_BAT1__

#include "../../../Include.h"
#include "../../../Castlevania.h"

class Intro_Bat1 : public GameObject
{
public:
	pPlayScene playScene;

	Intro_Bat1(pScene scene);
	~Intro_Bat1();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);

	float defaultSpeed = 0.075f;
};

#endif //!__INTRO_BAT1__