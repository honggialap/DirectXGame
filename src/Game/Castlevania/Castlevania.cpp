#include "Castlevania.h"

Castlevania::Castlevania(HINSTANCE hInstance) : Game::Game(hInstance)
{
	source = "Castlevania\\Data\\GameData.xml";
}

Castlevania::~Castlevania()
{
}

void Castlevania::LoadScene(string sceneID)
{
	auto scene = new PlayScene(this);
	scene->source = scenes[sceneID];
	currentScene = scene;
	currentScene->Load();
}
