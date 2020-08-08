#include "Zombie.h"

Zombie::Zombie(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

Zombie::~Zombie()
{
	playScene = nullptr;
}

void Zombie::Load()
{
	GameObject::Load();
}

void Zombie::Unload()
{
	GameObject::Unload();
}

void Zombie::Start()
{
	start = true;
}

void Zombie::Update(float elapsedMs)
{
	if (!start)	Start();
}

void Zombie::Render()
{
}

void Zombie::Collided(pCollision& collision)
{
}

void Zombie::SpawnedHandler(pGameObject gameObject)
{
}

void Zombie::DestroyedHandler(pGameObject gameObject)
{
}
