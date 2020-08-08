#ifndef __TOURCH_H__
#define __TOURCH_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Tourch : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Tourch(pScene scene);
	~Tourch();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__TOURCH_H__