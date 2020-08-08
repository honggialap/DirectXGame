#include "Demo.h"

Demo::Demo(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
}

Demo::~Demo()
{
}

void Demo::Load()
{
	GameObject::Load();
}

void Demo::Unload()
{
	GameObject::Unload();
}

void Demo::Start()
{
}

void Demo::Update(float elapsedMs)
{
}

void Demo::Render()
{
}

void Demo::Collided(pCollision& collision)
{
}

void Demo::SpawnedHandler(pGameObject gameObject)
{
}

void Demo::DestroyedHandler(pGameObject gameObject)
{
}
