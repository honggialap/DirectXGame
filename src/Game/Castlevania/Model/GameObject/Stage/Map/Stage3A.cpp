#include "Stage3A.h"

Stage3A::Stage3A(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
}

Stage3A::~Stage3A()
{
}

void Stage3A::Load()
{
	GameObject::Load();
}

void Stage3A::Unload()
{
	GameObject::Unload();
}

void Stage3A::Start()
{
}

void Stage3A::Update(float elapsedMs)
{
}

void Stage3A::Render()
{
}

void Stage3A::Collided(pCollision& collision)
{
}

void Stage3A::SpawnedHandler(pGameObject gameObject)
{
}

void Stage3A::DestroyedHandler(pGameObject gameObject)
{
}
