#include "Skeleton.h"

Skeleton::Skeleton(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

Skeleton::~Skeleton()
{
	playScene = nullptr;
}

void Skeleton::Load()
{
	GameObject::Load();
}

void Skeleton::Unload()
{
	GameObject::Unload();
}

void Skeleton::Start()
{
	start = true;
}

void Skeleton::Update(float elapsedMs)
{
	if (!start)	Start();
}

void Skeleton::Render()
{
}

void Skeleton::Collided(pCollision& collision)
{
}

void Skeleton::SpawnedHandler(pGameObject gameObject)
{
}

void Skeleton::DestroyedHandler(pGameObject gameObject)
{
}
