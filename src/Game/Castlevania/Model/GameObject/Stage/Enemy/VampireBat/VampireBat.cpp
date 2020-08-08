#include "VampireBat.h"

VampireBat::VampireBat(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

VampireBat::~VampireBat()
{
	playScene = nullptr;
}

void VampireBat::Load()
{
	GameObject::Load();
}

void VampireBat::Unload()
{
	GameObject::Unload();
}

void VampireBat::Start()
{
	start = true;
}

void VampireBat::Update(float elapsedMs)
{
	if (!start)	Start();
}

void VampireBat::Render()
{
}

void VampireBat::Collided(pCollision& collision)
{
}

void VampireBat::SpawnedHandler(pGameObject gameObject)
{
}

void VampireBat::DestroyedHandler(pGameObject gameObject)
{
}
