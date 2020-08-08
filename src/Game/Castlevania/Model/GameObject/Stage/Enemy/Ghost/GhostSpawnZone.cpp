#include "GhostSpawnZone.h"

GhostSpawnZone::GhostSpawnZone(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

GhostSpawnZone::~GhostSpawnZone()
{
	playScene = nullptr;
}

void GhostSpawnZone::Load()
{
	GameObject::Load();
}

void GhostSpawnZone::Unload()
{
	GameObject::Unload();
}

void GhostSpawnZone::Start()
{
	start = true;
}

void GhostSpawnZone::Update(float elapsedMs)
{
	if (!start)	Start();
}

void GhostSpawnZone::Render()
{
}

void GhostSpawnZone::Collided(pCollision& collision)
{
}

void GhostSpawnZone::SpawnedHandler(pGameObject gameObject)
{
}

void GhostSpawnZone::DestroyedHandler(pGameObject gameObject)
{
}
