#include "Hunchback.h"

Hunchback::Hunchback(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

Hunchback::~Hunchback()
{
	playScene = nullptr;
}

void Hunchback::Load()
{
	GameObject::Load();
}

void Hunchback::Unload()
{
	GameObject::Unload();
}

void Hunchback::Start()
{
	start = true;
}

void Hunchback::Update(float elapsedMs)
{
	if (!start)	Start();
}

void Hunchback::Render()
{
}

void Hunchback::Collided(pCollision& collision)
{
}

void Hunchback::SpawnedHandler(pGameObject gameObject)
{
}

void Hunchback::DestroyedHandler(pGameObject gameObject)
{
}
