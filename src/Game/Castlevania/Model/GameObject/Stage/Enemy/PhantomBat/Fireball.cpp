#include "Fireball.h"

Fireball::Fireball(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

Fireball::~Fireball()
{
	playScene = nullptr;
}

void Fireball::Load()
{
	GameObject::Load();
}

void Fireball::Unload()
{
	GameObject::Unload();
}

void Fireball::Start()
{
	start = true;
}

void Fireball::Update(float elapsedMs)
{
	if (!start)	Start();
}

void Fireball::Render()
{
}

void Fireball::Collided(pCollision& collision)
{
}

void Fireball::SpawnedHandler(pGameObject gameObject)
{
}

void Fireball::DestroyedHandler(pGameObject gameObject)
{
}
