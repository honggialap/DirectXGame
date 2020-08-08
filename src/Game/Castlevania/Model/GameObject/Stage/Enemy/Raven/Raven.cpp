#include "Raven.h"

Raven::Raven(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

Raven::~Raven()
{
	playScene = nullptr;
}

void Raven::Load()
{
	GameObject::Load();
}

void Raven::Unload()
{
	GameObject::Unload();
}

void Raven::Start()
{
	start = true;
}

void Raven::Update(float elapsedMs)
{
	if (!start)	Start();
}

void Raven::Render()
{
}

void Raven::Collided(pCollision& collision)
{
}

void Raven::SpawnedHandler(pGameObject gameObject)
{
}

void Raven::DestroyedHandler(pGameObject gameObject)
{
}
