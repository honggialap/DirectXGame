#include "DeadZone.h"

DeadZone::DeadZone(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Prop\\DeadZone.xml";
}

DeadZone::~DeadZone()
{
}

void DeadZone::Load()
{
	GameObject::Load();
}

void DeadZone::Unload()
{
	GameObject::Unload();
}

void DeadZone::Start()
{
	start = true;
	GetPhysics()->Enable();
	GetPhysics()->SetCollider(10, 20, 0, 0);
}

void DeadZone::Update(float elapsedMs)
{
	if (!start) Start();
	GetPhysics()->Update(elapsedMs);
}

void DeadZone::Render()
{
	GetPhysics()->RenderBoundingBox();
}

void DeadZone::Collided(pCollision& collision)
{
}

void DeadZone::SpawnedHandler(pGameObject gameObject)
{
}

void DeadZone::DestroyedHandler(pGameObject gameObject)
{
}
