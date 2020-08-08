#include "Stage1.h"

Stage1::Stage1(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
}

Stage1::~Stage1()
{
}

void Stage1::Load()
{
	GameObject::Load();
}

void Stage1::Unload()
{
	GameObject::Unload();
}

void Stage1::Start()
{
}

void Stage1::Update(float elapsedMs)
{
}

void Stage1::Render()
{
}

void Stage1::Collided(pCollision& collision)
{
}

void Stage1::SpawnedHandler(pGameObject gameObject)
{
}

void Stage1::DestroyedHandler(pGameObject gameObject)
{
}
