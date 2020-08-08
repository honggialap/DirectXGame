#include "Boomerang.h"

Boomerang::Boomerang(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
}

Boomerang::~Boomerang()
{
}

void Boomerang::Load()
{
	GameObject::Load();
}

void Boomerang::Unload()
{
	GameObject::Unload();
}

void Boomerang::Start()
{
}

void Boomerang::Update(float elapsedMs)
{
}

void Boomerang::Render()
{
}

void Boomerang::Collided(pCollision& collision)
{
}

void Boomerang::SpawnedHandler(pGameObject gameObject)
{
}

void Boomerang::DestroyedHandler(pGameObject gameObject)
{
}
