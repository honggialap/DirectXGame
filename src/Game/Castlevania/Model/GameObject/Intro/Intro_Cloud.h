#pragma once
#ifndef __INTRO_CLOUD__
#define __INTRO_CLOUD__

#include "../../../Include.h"
#include "../../../Castlevania.h"

class Intro_Cloud : public GameObject
{
public:
	pPlayScene playScene;

	Intro_Cloud(pScene scene);
	~Intro_Cloud();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);

	const float defaultSpeed = 0.02f;
};

#endif //!__INTRO_CLOUD__