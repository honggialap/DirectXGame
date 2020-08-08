#ifndef __DOOR_H__
#define __DOOR_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Door : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Door(pScene scene);
	~Door();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__DOOR_H__