#include "SkeletonBone.h"

SkeletonBone::SkeletonBone(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

SkeletonBone::~SkeletonBone()
{
	playScene = nullptr;
}

void SkeletonBone::Load()
{
	GameObject::Load();
}

void SkeletonBone::Unload()
{
	GameObject::Unload();
}

void SkeletonBone::Start()
{
	start = true;
}

void SkeletonBone::Update(float elapsedMs)
{
	if (!start)	Start();
}

void SkeletonBone::Render()
{
}

void SkeletonBone::Collided(pCollision& collision)
{
}

void SkeletonBone::SpawnedHandler(pGameObject gameObject)
{
}

void SkeletonBone::DestroyedHandler(pGameObject gameObject)
{
}
