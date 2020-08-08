#include "VampireBatTrigger.h"

VampireBatTrigger::VampireBatTrigger(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

VampireBatTrigger::~VampireBatTrigger()
{
	playScene = nullptr;
}

void VampireBatTrigger::Load()
{
	GameObject::Load();
}

void VampireBatTrigger::Unload()
{
	GameObject::Unload();
}

void VampireBatTrigger::Start()
{
	start = true;
}

void VampireBatTrigger::Update(float elapsedMs)
{
	if (!start)	Start();
}

void VampireBatTrigger::Render()
{
}

void VampireBatTrigger::Collided(pCollision& collision)
{
}

void VampireBatTrigger::SpawnedHandler(pGameObject gameObject)
{
}

void VampireBatTrigger::DestroyedHandler(pGameObject gameObject)
{
}
