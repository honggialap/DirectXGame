#include "Stage3B.h"

Stage3B::Stage3B(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
}

Stage3B::~Stage3B()
{
}

void Stage3B::Load()
{
	GameObject::Load();
}

void Stage3B::Unload()
{
	GameObject::Unload();
}

void Stage3B::Start()
{
}

void Stage3B::Update(float elapsedMs)
{
}

void Stage3B::Render()
{
}

void Stage3B::Collided(pCollision& collision)
{
}

void Stage3B::SpawnedHandler(pGameObject gameObject)
{
}

void Stage3B::DestroyedHandler(pGameObject gameObject)
{
}
