#ifndef __MOVING_PLATFORM_H__
#define __MOVING_PLATFORM_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class MovingPlatform : public GameObject
{
protected:
	pPlayScene playScene;

public:
	MovingPlatform(pScene scene);
	~MovingPlatform();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__MOVING_PLATFORM_H__