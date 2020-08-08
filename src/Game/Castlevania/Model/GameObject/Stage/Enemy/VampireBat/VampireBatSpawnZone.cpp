#include "VampireBatSpawnZone.h"

VampireBatSpawnZone::VampireBatSpawnZone(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

VampireBatSpawnZone::~VampireBatSpawnZone()
{
	playScene = nullptr;
}

void VampireBatSpawnZone::Load()
{
	GameObject::Load();
}

void VampireBatSpawnZone::Unload()
{
	GameObject::Unload();
}

void VampireBatSpawnZone::Start()
{
	start = true;
}

void VampireBatSpawnZone::Update(float elapsedMs)
{
	if (!start)	Start();
}

void VampireBatSpawnZone::Render()
{
}

void VampireBatSpawnZone::Collided(pCollision& collision)
{
}

void VampireBatSpawnZone::SpawnedHandler(pGameObject gameObject)
{
}

void VampireBatSpawnZone::DestroyedHandler(pGameObject gameObject)
{
}
