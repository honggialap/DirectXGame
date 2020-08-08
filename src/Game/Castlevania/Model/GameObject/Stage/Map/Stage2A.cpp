#include "Stage2A.h"

Stage2A::Stage2A(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
}

Stage2A::~Stage2A()
{
}

void Stage2A::Load()
{
	GameObject::Load();
}

void Stage2A::Unload()
{
	GameObject::Unload();
}

void Stage2A::Start()
{
}

void Stage2A::Update(float elapsedMs)
{
}

void Stage2A::Render()
{
}

void Stage2A::Collided(pCollision& collision)
{
}

void Stage2A::SpawnedHandler(pGameObject gameObject)
{
}

void Stage2A::DestroyedHandler(pGameObject gameObject)
{
}
