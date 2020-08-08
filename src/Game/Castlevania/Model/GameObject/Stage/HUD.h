#pragma once
#ifndef __HUD_H__
#define __HUD_H__

#include "../../../Include.h"
#include "../../../Castlevania.h"

class HUD : public GameObject
{
protected:
	pPlayScene playScene;

public:
	HUD(pScene scene);
	~HUD();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__INTRO_H__