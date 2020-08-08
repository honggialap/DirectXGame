#pragma once
#ifndef __BLACK_KNIGHT_H__
#define __BLACK_KNIGHT_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class BlackKnight : public GameObject
{
public:
	pPlayScene playScene;

	BlackKnight(pScene scene);
	~BlackKnight();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__BLACK_KNIGHT_H__