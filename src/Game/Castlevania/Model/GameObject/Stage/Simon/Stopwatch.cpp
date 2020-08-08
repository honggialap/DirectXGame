#include "Stopwatch.h"

Stopwatch::Stopwatch(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
}

Stopwatch::~Stopwatch()
{
}

void Stopwatch::Load()
{
	GameObject::Load();
}

void Stopwatch::Unload()
{
	GameObject::Unload();
}

void Stopwatch::Start()
{
}

void Stopwatch::Update(float elapsedMs)
{
}

void Stopwatch::Render()
{
}

void Stopwatch::Collided(pCollision& collision)
{
}

void Stopwatch::SpawnedHandler(pGameObject gameObject)
{
}

void Stopwatch::DestroyedHandler(pGameObject gameObject)
{
}
