#include "SkeletonTrigger.h"

SkeletonTrigger::SkeletonTrigger(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

SkeletonTrigger::~SkeletonTrigger()
{
	playScene = nullptr;
}

void SkeletonTrigger::Load()
{
	GameObject::Load();
}

void SkeletonTrigger::Unload()
{
	GameObject::Unload();
}

void SkeletonTrigger::Start()
{
	start = true;
}

void SkeletonTrigger::Update(float elapsedMs)
{
	if (!start)	Start();
}

void SkeletonTrigger::Render()
{
}

void SkeletonTrigger::Collided(pCollision& collision)
{
}

void SkeletonTrigger::SpawnedHandler(pGameObject gameObject)
{
}

void SkeletonTrigger::DestroyedHandler(pGameObject gameObject)
{
}
