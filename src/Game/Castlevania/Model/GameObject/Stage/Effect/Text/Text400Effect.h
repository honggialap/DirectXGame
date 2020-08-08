#pragma once
#ifndef __TEXT_400_H__
#define __TEXT_400_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class Text400Effect : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Text400Effect(pScene scene);
	~Text400Effect();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__TEXT_400_H__