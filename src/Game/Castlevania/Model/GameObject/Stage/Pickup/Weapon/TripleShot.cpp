#include "TripleShot.h"

TripleShot::TripleShot(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Weapon\\TripleShot.xml";
}

TripleShot::~TripleShot()
{
	playScene = nullptr;
}

void TripleShot::Load()
{
	GameObject::Load();
}

void TripleShot::Unload()
{
	GameObject::Unload();
}

void TripleShot::Start()
{
	start = true;
}

void TripleShot::Update(float elapsedMs)
{
	if (!start)	Start();
}

void TripleShot::Render()
{
	GetSpriteRenderer()->Render("tripleShot");
}

void TripleShot::Collided(pCollision& collision)
{
}

void TripleShot::SpawnedHandler(pGameObject gameObject)
{
}

void TripleShot::DestroyedHandler(pGameObject gameObject)
{
}
