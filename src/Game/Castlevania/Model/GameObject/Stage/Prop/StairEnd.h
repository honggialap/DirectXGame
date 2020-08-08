#ifndef __STAIR_END_H__
#define __STAIR_END_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class StairEnd : public GameObject
{
protected:
	pPlayScene playScene;

public:
	StairEnd(pScene scene);
	~StairEnd();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__STAIR_END_H__