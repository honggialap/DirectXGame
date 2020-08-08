#pragma once
#ifndef __TEXT_1000_H__
#define __TEXT_1000_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class Text1000Effect : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Text1000Effect(pScene scene);
	~Text1000Effect();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__TEXT_1000_H__