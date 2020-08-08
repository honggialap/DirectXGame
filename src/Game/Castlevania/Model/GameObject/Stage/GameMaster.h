#pragma once
#ifndef __GAME_MASTER_H__
#define __GAME_MASTER_H__

#include "../../../Include.h"
#include "../../../Castlevania.h"

class GameMaster : public GameObject
{
public:
	pPlayScene playScene;
	pController controller;

	GameMaster(pScene scene);
	~GameMaster();

	void Load();
	void Unload();
	void Start();

	void Update(float elapsedMs);
	void Render();
	virtual void Collided(pCollision& collision);

	virtual void SpawnedHandler(pGameObject gameObject);
	virtual void DestroyedHandler(pGameObject gameObject);

	void LoadStats();
	void SaveStats();
	void ResetStats();

	enum Stage
	{
		Title, Intro,
		Stage1, Stage2A, Stage2B,
		Stage3A, Stage3B, Stage4
	};
	Stage stage;
	void SetStage(Stage stage);
	bool pause;

	//title
	float titleTimer;
	bool runTitleTimer;
	pTitle_Bat titleBat;
	pTitle_BG titleBG;
	pTitle_Label titleLabel;

	//intro



};

#endif //!__GAME_MASTER_H__