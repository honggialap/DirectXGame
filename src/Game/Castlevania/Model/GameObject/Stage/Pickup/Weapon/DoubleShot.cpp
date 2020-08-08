#include "DoubleShot.h"

DoubleShot::DoubleShot(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Weapon\\DoubleShot.xml";
}

DoubleShot::~DoubleShot()
{
	playScene = nullptr;
}

void DoubleShot::Load()
{
	GameObject::Load();
}

void DoubleShot::Unload()
{
	GameObject::Unload();
}

void DoubleShot::Start()
{
	start = true;
}

void DoubleShot::Update(float elapsedMs)
{
	if (!start)	Start();
}

void DoubleShot::Render()
{
	GetSpriteRenderer()->Render("doubleShot");
}

void DoubleShot::Collided(pCollision& collision)
{
}

void DoubleShot::SpawnedHandler(pGameObject gameObject)
{
}

void DoubleShot::DestroyedHandler(pGameObject gameObject)
{
}
