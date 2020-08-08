#pragma once
#ifndef __TEXT_100_H__
#define __TEXT_100_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class Text100Effect : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Text100Effect(pScene scene);
	~Text100Effect();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__TEXT_100_H__