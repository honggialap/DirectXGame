#pragma once
#ifndef __AXE_ITEM_H__
#define __AXE_ITEM_H__

#include "../../../../../Include.h"
#include "../../../../../Castlevania.h"

class AxeItem : public GameObject
{
public:
	pPlayScene playScene;

	AxeItem(pScene scene);
	~AxeItem();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif // !__AXE_ITEM_H__