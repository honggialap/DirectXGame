#include "Scene.h"

Scene::Scene(pGame game)
{
	this->game = game;
	done = false;
	exit = false;
}

Scene::~Scene()
{
	this->game = nullptr;
}

void Scene::Load()
{
}

void Scene::Update(pGameTime gameTime)
{
}

void Scene::Render()
{
}

Scenes::Scenes(pGame game)
{
	this->game = game;
	this->currentScene = nullptr;
}

Scenes::~Scenes()
{
	this->game = nullptr;
}

void Scenes::NextScene()
{
	currentScene = scenes[currentScene->nextScene];
}

void Scenes::Clear()
{
	//current scene -> unload
	//game objects -> clear
}
