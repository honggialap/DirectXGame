#include "GameMaster.h"

GameMaster::GameMaster(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	controller = dynamic_cast<pLocalPlayer>(playScene->players[0])->controller;
	source = "Castlevania\\Data\\GameObject\\GameMaster.xml";
}

GameMaster::~GameMaster()
{
	playScene = nullptr;
	controller = nullptr;
}

void GameMaster::Load()
{
	GameObject::Load();
	LoadStats();
}

void GameMaster::Unload()
{
	SaveStats();
	GameObject::Unload();
}

void GameMaster::Start()
{
	Unload();
}

void GameMaster::Update(float elapsedMs)
{
	switch (stage)
	{
	case Title:
		break;
	case Intro:
	case Stage1:
		if (controller->IsButtonPressed(Controller::Select))
		{
			stage = Stage::Stage2A;
			scene->SwitchScene("stage2A");
		}
		break;
	case Stage2A:
		if (controller->IsButtonPressed(Controller::Select))
		{
			stage = Stage::Stage2B;
			scene->SwitchScene("stage2B");
		}
		break;
	case Stage2B:
		if (controller->IsButtonPressed(Controller::Select))
		{
			stage = Stage::Stage3A;
			scene->SwitchScene("stage3A");
		}
		break;
	case Stage3A:
		if (controller->IsButtonPressed(Controller::Select))
		{
			stage = Stage::Stage3B;
			scene->SwitchScene("stage3B");
		}
		break;
	case Stage3B:
		if (controller->IsButtonPressed(Controller::Select))
		{
			stage = Stage::Stage4;
			scene->SwitchScene("stage4");
		}
		break;
	case Stage4:
		if (controller->IsButtonPressed(Controller::Select))
		{
			stage = Stage::Title;
			scene->SwitchScene("title");
		}
		break;
	}
}

void GameMaster::Render()
{
}

void GameMaster::Collided(pCollision& collision)
{
}

void GameMaster::SpawnedHandler(pGameObject gameObject)
{
	//title
	if (dynamic_cast<pTitle_Bat>(gameObject))
	{
		titleBat = dynamic_cast<pTitle_Bat>(gameObject);
	}
	else if (dynamic_cast<pTitle_BG>(gameObject))
	{
		titleBG = dynamic_cast<pTitle_BG>(gameObject);
	}
	else if (dynamic_cast<pTitle_Label>(gameObject))
	{
		titleLabel = dynamic_cast<pTitle_Label>(gameObject);
	}
}

void GameMaster::DestroyedHandler(pGameObject gameObject)
{
}

void GameMaster::SetStage(Stage stage)
{
	this->stage = stage;
	switch (stage)
	{
	case GameMaster::Title:
		titleTimer = 1500;
		runTitleTimer = false;
		break;
	case GameMaster::Intro:
		break;
	case GameMaster::Stage1:
		break;
	case GameMaster::Stage2A:
		break;
	case GameMaster::Stage2B:
		break;
	case GameMaster::Stage3A:
		break;
	case GameMaster::Stage3B:
		break;
	case GameMaster::Stage4:
		break;
	default:
		break;
	}
}

void GameMaster::SaveStats()
{
	xml_document gameStatsDoc;
	gameStatsDoc.load_file(source.c_str());

	xml_node save = gameStatsDoc.child("Prefab").child("GameStats").child("Save");
	
	save.attribute("stage").set_value((int)stage);
	
	gameStatsDoc.save_file(source.c_str());
}

void GameMaster::LoadStats()
{
	xml_document gameStatsDoc;
	gameStatsDoc.load_file(source.c_str());

	xml_node save = gameStatsDoc.child("Prefab").child("GameStats").child("Save");
	
	SetStage((Stage)save.attribute("stage").as_int());
}

void GameMaster::ResetStats()
{
	xml_document gameStatsDoc;
	gameStatsDoc.load_file(source.c_str());

	xml_node save = gameStatsDoc.child("Prefab").child("GameStats").child("Save");
	xml_node load = gameStatsDoc.child("Prefab").child("GaemStats").child("Default");

	save.attribute("stage").set_value(load.attribute("stage").as_int());
	gameStatsDoc.save_file(source.c_str());
}

