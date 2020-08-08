#include "Stair.h"

Stair::Stair(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Prop\\Stair.xml";
}

Stair::~Stair()
{
}

void Stair::Load()
{
	GameObject::Load();
}

void Stair::Unload()
{
	GameObject::Unload();
}

void Stair::Start()
{
	start = true;
}

void Stair::Update(float elapsedMs)
{
	if (!start) Start();
}

void Stair::Render()
{
}

void Stair::Collided(pCollision& collision)
{
}

void Stair::SpawnedHandler(pGameObject gameObject)
{
}

void Stair::DestroyedHandler(pGameObject gameObject)
{
}
