#include "Door.h"

Door::Door(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Prop\\Door.xml";
}

Door::~Door()
{
}

void Door::Load()
{
	GameObject::Load();
}

void Door::Unload()
{
	GameObject::Unload();
}

void Door::Start()
{
	start = true;
	GetPhysics()->Enable();
	GetPhysics()->SetCollider(10, 20, 0, 0);
	GetAnimator()->Play("open");
}

void Door::Update(float elapsedMs)
{
	if (!start) Start();
	GetPhysics()->Update(elapsedMs);
	GetAnimator()->Update(elapsedMs);
}

void Door::Render()
{
	GetPhysics()->RenderBoundingBox();
	GetAnimator()->Render();
}

void Door::Collided(pCollision& collision)
{
}

void Door::SpawnedHandler(pGameObject gameObject)
{
}

void Door::DestroyedHandler(pGameObject gameObject)
{
}
