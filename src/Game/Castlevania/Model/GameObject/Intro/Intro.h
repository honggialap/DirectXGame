#pragma once
#ifndef __INTRO_H__
#define __INTRO_H__

#include "../../../Include.h"
#include "../../../Castlevania.h"

class Intro : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Intro(pScene scene);
	~Intro();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision &collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);

	float introTimer;
};

#endif // !__INTRO_H__