#include "Axe.h"

Axe::Axe(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
}

Axe::~Axe()
{
}

void Axe::Load()
{
	GameObject::Load();
}

void Axe::Unload()
{
	GameObject::Unload();
}

void Axe::Start()
{
}

void Axe::Update(float elapsedMs)
{
}

void Axe::Render()
{
}

void Axe::Collided(pCollision& collision)
{
}

void Axe::SpawnedHandler(pGameObject gameObject)
{
}

void Axe::DestroyedHandler(pGameObject gameObject)
{
}
