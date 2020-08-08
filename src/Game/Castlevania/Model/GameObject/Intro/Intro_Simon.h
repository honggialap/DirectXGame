#pragma once
#ifndef __INTRO_SIMON__
#define __INTRO_SIMON__

#include "../../../Include.h"
#include "../../../Castlevania.h"

class Intro_Simon : public GameObject
{
public:
	pPlayScene playScene;

	Intro_Simon(pScene scene);
	~Intro_Simon();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);

	enum State
	{
		Walk, Intro
	};
	State state;
	float defaultSpeed;
	float countdown;

	void SetState(State state);
};

#endif //!__INTRO_SIMON__