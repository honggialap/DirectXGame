#ifndef __BREAKABLE_BRICK_H__
#define __BREAKABLE_BRICK_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class BreakableBrick : public GameObject
{
protected:
	pPlayScene playScene;

public:
	BreakableBrick(pScene scene);
	~BreakableBrick();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__BREAKABLE_BRICK_H__