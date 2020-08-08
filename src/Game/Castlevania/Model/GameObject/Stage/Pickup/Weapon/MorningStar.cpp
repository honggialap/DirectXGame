#include "MorningStar.h"

MorningStar::MorningStar(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Weapon\\MorningStar.xml";
}

MorningStar::~MorningStar()
{
	playScene = nullptr;
}

void MorningStar::Load()
{
	GameObject::Load();
}

void MorningStar::Unload()
{
	GameObject::Unload();
}

void MorningStar::Start()
{
	start = true;
}

void MorningStar::Update(float elapsedMs)
{
	if (!start)	Start();
}

void MorningStar::Render()
{
	GetSpriteRenderer()->Render("morningStar");
}

void MorningStar::Collided(pCollision& collision)
{
}

void MorningStar::SpawnedHandler(pGameObject gameObject)
{
}

void MorningStar::DestroyedHandler(pGameObject gameObject)
{
}
