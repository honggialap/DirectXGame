#include "StairEnd.h"

StairEnd::StairEnd(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Prop\\StairEnd.xml";
}

StairEnd::~StairEnd()
{
}

void StairEnd::Load()
{
	GameObject::Load();
}

void StairEnd::Unload()
{
	GameObject::Unload();
}

void StairEnd::Start()
{
	start = true;
	GetPhysics()->Enable();
	GetPhysics()->SetCollider(10, 20, 0, 0);
}

void StairEnd::Update(float elapsedMs)
{
	if (!start) Start();
	GetPhysics()->Update(elapsedMs);
}

void StairEnd::Render()
{
	GetPhysics()->RenderBoundingBox();
}

void StairEnd::Collided(pCollision& collision)
{
}

void StairEnd::SpawnedHandler(pGameObject gameObject)
{
}

void StairEnd::DestroyedHandler(pGameObject gameObject)
{
}
