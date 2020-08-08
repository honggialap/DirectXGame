#include "ExtraLife.h"

ExtraLife::ExtraLife(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Item\\ExtraLife.xml";
}

ExtraLife::~ExtraLife()
{
	playScene = nullptr;
}

void ExtraLife::Load()
{
	GameObject::Load();
}

void ExtraLife::Unload()
{
	GameObject::Unload();
}

void ExtraLife::Start()
{
	start = true;
}

void ExtraLife::Update(float elapsedMs)
{
	if (!start)	Start();
}

void ExtraLife::Render()
{
	GetSpriteRenderer()->Render("extraLife");
}

void ExtraLife::Collided(pCollision& collision)
{
}

void ExtraLife::SpawnedHandler(pGameObject gameObject)
{
}

void ExtraLife::DestroyedHandler(pGameObject gameObject)
{
}
