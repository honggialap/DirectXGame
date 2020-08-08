#pragma once
#ifndef __SIMON_H__
#define __SIMON_H__

#include "../../../../Include.h"
#include "../../../../Castlevania.h"

class Simon : public GameObject
{
public:
	pPlayScene playScene;
	pController controller;

	Simon(pScene scene);
	~Simon();

	void Load();
	void Unload();

	void Start();
	void Update(float elapsedMs);
	void Render();

	virtual void Collided(pCollision& collision);
	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);

	virtual void SaveStats();
	virtual void LoadStats();
	virtual void ResetStats();

public:
	enum State
	{
		Idle, Walk,
		Ascend, Decend,
		Crouch, Jump,
		Attack, SubAttack,
		CrouchAttack,
		Damaged, Dead,
		PowerUp,
	};
	State state;

	enum Facing
	{
		Left, Right
	};
	Facing facing;
	bool grounded;

	void SetState(State state);
	int GetState() { return state; }
};

#endif //!__SIMON_H__