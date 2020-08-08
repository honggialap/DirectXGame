#include "Platform.h"

Platform::Platform(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Prop\\Platform.xml";
}

Platform::~Platform()
{
}

void Platform::Load()
{
	GameObject::Load();
}

void Platform::Unload()
{
	GameObject::Unload();
}

void Platform::Start()
{
	start = true;
	GetPhysics()->Enable();
	GetPhysics()->SetCollider(10, 20, 0, 0);
}

void Platform::Update(float elapsedMs)
{
	if (!start) Start();
	GetPhysics()->Update(elapsedMs);
}

void Platform::Render()
{
	GetPhysics()->RenderBoundingBox();
}

void Platform::Collided(pCollision& collision)
{
}

void Platform::SpawnedHandler(pGameObject gameObject)
{
}

void Platform::DestroyedHandler(pGameObject gameObject)
{
}
