#include "Tourch.h"

Tourch::Tourch(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Prop\\Tourch.xml";
}

Tourch::~Tourch()
{
}

void Tourch::Load()
{
	GameObject::Load();
}

void Tourch::Unload()
{
	GameObject::Unload();
}

void Tourch::Start()
{
	start = true;
	GetPhysics()->Enable();
	GetPhysics()->SetCollider(10, 20, 0, 0);

	GetAnimator()->Play("idle", true);
}

void Tourch::Update(float elapsedMs)
{
	if (!start) Start();
	GetPhysics()->Update(elapsedMs);
	GetAnimator()->Update(elapsedMs);
}

void Tourch::Render()
{
	GetPhysics()->RenderBoundingBox();
	GetAnimator()->Render();
}

void Tourch::Collided(pCollision& collision)
{
}

void Tourch::SpawnedHandler(pGameObject gameObject)
{
}

void Tourch::DestroyedHandler(pGameObject gameObject)
{
}
