#pragma once
#ifndef __TITLE_BAT__
#define __TITLE_BAT__

#include "../../../Include.h"
#include "../../../Castlevania.h"

class Title_Bat : public GameObject
{
public:
	pPlayScene playScene;

	Title_Bat(pScene scene);
	~Title_Bat();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);

	float countdown;
	enum class State 
	{
		Begin, Loop, Pause
	};
	State state;
	void SetState(State state);
};

#endif //!__TITLE_BAT__