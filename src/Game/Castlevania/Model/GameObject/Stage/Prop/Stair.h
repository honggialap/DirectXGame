#ifndef __STAIR_H__
#define __STAIR_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Stair : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Stair(pScene scene);
	~Stair();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__STAIR_H__