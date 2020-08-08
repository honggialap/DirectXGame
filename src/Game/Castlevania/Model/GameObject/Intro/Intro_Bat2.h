#pragma once
#ifndef __INTRO_BAT2__
#define __INTRO_BAT2__

#include "../../../Include.h"
#include "../../../Castlevania.h"

class Intro_Bat2 : public GameObject
{
public:
	pPlayScene playScene;

	Intro_Bat2(pScene scene);
	~Intro_Bat2();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);

	bool initial;
	float maxY;
	float vx, vy, g;
	float defaultSpeed;
};

#endif //!__INTRO_BAT2__