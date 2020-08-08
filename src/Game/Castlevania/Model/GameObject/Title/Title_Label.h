#pragma once
#ifndef __TITLE_LABEL__
#define __TITLE_LABEL__

#include "../../../Include.h"
#include "../../../Castlevania.h"

class Title_Label : public GameObject
{
public:
	pPlayScene playScene;

	Title_Label(pScene scene);
	~Title_Label();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);

	enum class State
	{
		Begin, StartGame
	};
	State state;
	void SetState(State state);
};

#endif //!__TITLE_LABEL__