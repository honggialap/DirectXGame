#pragma once
#ifndef __MOAI_H__
#define __MOAI_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class Moai : public GameObject
{
public:
	pPlayScene playScene;

	Moai(pScene scene);
	~Moai();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__MOAI_H__