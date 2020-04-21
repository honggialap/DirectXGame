#include "GameObject.h"

GameObject::GameObject(pGame game, pScene scene)
{
	this->game = game;
	this->scene = scene;
}

GameObject::~GameObject()
{
	this->scene = nullptr;
	this->game = nullptr;
}

GameObjects::GameObjects(pGame game, pScene scene)
{
	this->game = game;
	this->scene = scene;
}

GameObjects::~GameObjects()
{
	this->scene = nullptr;
	this->game = nullptr;
}

void GameObjects::Add()
{

}

void GameObjects::Get()
{

}

void GameObjects::Remove()
{

}

void GameObjects::Clear()
{

}
