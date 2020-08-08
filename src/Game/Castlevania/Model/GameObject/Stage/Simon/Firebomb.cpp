#include "Firebomb.h"

Firebomb::Firebomb(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
}

Firebomb::~Firebomb()
{
}

void Firebomb::Load()
{
	GameObject::Load();
}

void Firebomb::Unload()
{
	GameObject::Unload();
}

void Firebomb::Start()
{
}

void Firebomb::Update(float elapsedMs)
{
}

void Firebomb::Render()
{
}

void Firebomb::Collided(pCollision& collision)
{
}

void Firebomb::SpawnedHandler(pGameObject gameObject)
{
}

void Firebomb::DestroyedHandler(pGameObject gameObject)
{
}
