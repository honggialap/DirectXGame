#include "Stage2B.h"

Stage2B::Stage2B(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
}

Stage2B::~Stage2B()
{
}

void Stage2B::Load()
{
	GameObject::Load();
}

void Stage2B::Unload()
{
	GameObject::Unload();
}

void Stage2B::Start()
{
}

void Stage2B::Update(float elapsedMs)
{
}

void Stage2B::Render()
{
}

void Stage2B::Collided(pCollision& collision)
{
}

void Stage2B::SpawnedHandler(pGameObject gameObject)
{
}

void Stage2B::DestroyedHandler(pGameObject gameObject)
{
}
