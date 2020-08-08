#include "VampireKiller.h"

VampireKiller::VampireKiller(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
}

VampireKiller::~VampireKiller()
{
}

void VampireKiller::Load()
{
	GameObject::Load();
}

void VampireKiller::Unload()
{
	GameObject::Unload();
}

void VampireKiller::Start()
{
}

void VampireKiller::Update(float elapsedMs)
{
}

void VampireKiller::Render()
{
}

void VampireKiller::Collided(pCollision& collision)
{
}

void VampireKiller::SpawnedHandler(pGameObject gameObject)
{
}

void VampireKiller::DestroyedHandler(pGameObject gameObject)
{
}
