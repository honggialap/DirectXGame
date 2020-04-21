#include "Scene.h"

Scene::Scene(pGame game)
{
	this->game = game;
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
