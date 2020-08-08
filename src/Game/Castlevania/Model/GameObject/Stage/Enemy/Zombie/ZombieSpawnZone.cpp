#include "ZombieSpawnZone.h"

ZombieSpawnZone::ZombieSpawnZone(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

ZombieSpawnZone::~ZombieSpawnZone()
{
	playScene = nullptr;
}

void ZombieSpawnZone::Load()
{
	GameObject::Load();
}

void ZombieSpawnZone::Unload()
{
	GameObject::Unload();
}

void ZombieSpawnZone::Start()
{
	start = true;
}

void ZombieSpawnZone::Update(float elapsedMs)
{
	if (!start)	Start();
}

void ZombieSpawnZone::Render()
{
}

void ZombieSpawnZone::Collided(pCollision& collision)
{
}

void ZombieSpawnZone::SpawnedHandler(pGameObject gameObject)
{
}

void ZombieSpawnZone::DestroyedHandler(pGameObject gameObject)
{
}
