#pragma once
#ifndef __TITLE_H__
#define __TITLE_H__

#include "../../../Include.h"
#include "../../../Castlevania.h"
#include "Title_Bat.h"
#include "Title_Label.h"

class Title : public GameObject
{
protected:
	pPlayScene playScene;
	pController controller;

public:
	Title(pScene scene);
	~Title();

	virtual void Load();
	virtual void Unload();

	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);

	enum class State
	{
		Begin, StartGame
	};
	State state;
	void SetState(State state);

	pTitle_Label label;
	pTitle_Bat bat;

	float titleTimer;
};

#endif // !__TITLE_H__