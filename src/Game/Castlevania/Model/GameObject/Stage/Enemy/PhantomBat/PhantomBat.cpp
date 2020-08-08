#include "PhantomBat.h"

PhantomBat::PhantomBat(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

PhantomBat::~PhantomBat()
{
	playScene = nullptr;
}

void PhantomBat::Load()
{
	GameObject::Load();
}

void PhantomBat::Unload()
{
	GameObject::Unload();
}

void PhantomBat::Start()
{
	start = true;
}

void PhantomBat::Update(float elapsedMs)
{
	if (!start)	Start();
}

void PhantomBat::Render()
{
}

void PhantomBat::Collided(pCollision& collision)
{
}

void PhantomBat::SpawnedHandler(pGameObject gameObject)
{
}

void PhantomBat::DestroyedHandler(pGameObject gameObject)
{
}
