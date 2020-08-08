#include "Stage4.h"

Stage4::Stage4(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
}

Stage4::~Stage4()
{
}

void Stage4::Load()
{
	GameObject::Load();
}

void Stage4::Unload()
{
	GameObject::Unload();
}

void Stage4::Start()
{
}

void Stage4::Update(float elapsedMs)
{
}

void Stage4::Render()
{
}

void Stage4::Collided(pCollision& collision)
{
}

void Stage4::SpawnedHandler(pGameObject gameObject)
{
}

void Stage4::DestroyedHandler(pGameObject gameObject)
{
}
