#include "PorkChop.h"

PorkChop::PorkChop(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Item\\PorkChop.xml";
}

PorkChop::~PorkChop()
{
	playScene = nullptr;
}

void PorkChop::Load()
{
	GameObject::Load();
}

void PorkChop::Unload()
{
	GameObject::Unload();
}

void PorkChop::Start()
{
	start = true;
}

void PorkChop::Update(float elapsedMs)
{
	if (!start)	Start();
}

void PorkChop::Render()
{
	GetSpriteRenderer()->Render("porkChop");
}

void PorkChop::Collided(pCollision& collision)
{
}

void PorkChop::SpawnedHandler(pGameObject gameObject)
{
}

void PorkChop::DestroyedHandler(pGameObject gameObject)
{
}
