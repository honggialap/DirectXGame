#include "GhostTrigger.h"

GhostTrigger::GhostTrigger(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

GhostTrigger::~GhostTrigger()
{
	playScene = nullptr;
}

void GhostTrigger::Load()
{
	GameObject::Load();
}

void GhostTrigger::Unload()
{
	GameObject::Unload();
}

void GhostTrigger::Start()
{
	start = true;
}

void GhostTrigger::Update(float elapsedMs)
{
	if (!start)	Start();
}

void GhostTrigger::Render()
{
}

void GhostTrigger::Collided(pCollision& collision)
{
}

void GhostTrigger::SpawnedHandler(pGameObject gameObject)
{
}

void GhostTrigger::DestroyedHandler(pGameObject gameObject)
{
}
