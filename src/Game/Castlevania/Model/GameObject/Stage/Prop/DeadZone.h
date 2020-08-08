#ifndef __DEAD_ZONE_H__
#define __DEAD_ZONE_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class DeadZone : public GameObject
{
protected:
	pPlayScene playScene;

public:
	DeadZone(pScene scene);
	~DeadZone();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__DEAD_ZONE_H__