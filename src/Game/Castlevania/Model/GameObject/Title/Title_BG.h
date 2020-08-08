#pragma once
#ifndef __TITLE_BG__
#define __TITLE_BG__

#include "../../../Include.h"
#include "../../../Castlevania.h"

class Title_BG : public GameObject
{
public:
	pPlayScene playScene;

	Title_BG(pScene scene);
	~Title_BG();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);
};

#endif //!__TITLE_BG__