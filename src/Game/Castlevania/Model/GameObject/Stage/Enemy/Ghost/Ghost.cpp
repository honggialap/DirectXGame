#include "Ghost.h"

Ghost::Ghost(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

Ghost::~Ghost()
{
	playScene = nullptr;
}

void Ghost::Load()
{
	GameObject::Load();
}

void Ghost::Unload()
{
	GameObject::Unload();
}

void Ghost::Start()
{
	start = true;
}

void Ghost::Update(float elapsedMs)
{
	if (!start)	Start();
}

void Ghost::Render()
{
}

void Ghost::Collided(pCollision& collision)
{
}

void Ghost::SpawnedHandler(pGameObject gameObject)
{
}

void Ghost::DestroyedHandler(pGameObject gameObject)
{
}
