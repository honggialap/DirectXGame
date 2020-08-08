#ifndef __CANDLE_H__
#define __CANDLE_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Candle : public GameObject
{
protected:
	pPlayScene playScene;

public:
	Candle(pScene scene);
	~Candle();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__CANDLE_H__