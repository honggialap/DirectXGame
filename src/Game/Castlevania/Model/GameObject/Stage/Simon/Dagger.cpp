#include "Dagger.h"

Dagger::Dagger(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
}

Dagger::~Dagger()
{
}

void Dagger::Load()
{
	GameObject::Load();
}

void Dagger::Unload()
{
	GameObject::Unload();
}

void Dagger::Start()
{
}

void Dagger::Update(float elapsedMs)
{
}

void Dagger::Render()
{
}

void Dagger::Collided(pCollision& collision)
{
}

void Dagger::SpawnedHandler(pGameObject gameObject)
{
}

void Dagger::DestroyedHandler(pGameObject gameObject)
{
}
