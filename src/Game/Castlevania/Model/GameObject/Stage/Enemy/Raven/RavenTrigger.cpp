#include "RavenTrigger.h"

RavenTrigger::RavenTrigger(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

RavenTrigger::~RavenTrigger()
{
	playScene = nullptr;
}

void RavenTrigger::Load()
{
	GameObject::Load();
}

void RavenTrigger::Unload()
{
	GameObject::Unload();
}

void RavenTrigger::Start()
{
	start = true;
}

void RavenTrigger::Update(float elapsedMs)
{
	if (!start)	Start();
}

void RavenTrigger::Render()
{
}

void RavenTrigger::Collided(pCollision& collision)
{
}

void RavenTrigger::SpawnedHandler(pGameObject gameObject)
{
}

void RavenTrigger::DestroyedHandler(pGameObject gameObject)
{
}
