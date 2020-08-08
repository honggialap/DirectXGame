#include "BreakableBrick.h"

BreakableBrick::BreakableBrick(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Prop\\BreakableBrick.xml";
}

BreakableBrick::~BreakableBrick()
{
}

void BreakableBrick::Load()
{
	GameObject::Load();
}

void BreakableBrick::Unload()
{
	GameObject::Unload();
}

void BreakableBrick::Start()
{
	start = true;
	GetPhysics()->Enable();
	GetPhysics()->SetCollider(10, 20, 0, 0);
}

void BreakableBrick::Update(float elapsedMs)
{
	if (!start) Start();
	GetPhysics()->Update(elapsedMs);
}

void BreakableBrick::Render()
{
	GetPhysics()->RenderBoundingBox();
	GetSpriteRenderer()->Render("breakableBrick");
}

void BreakableBrick::Collided(pCollision& collision)
{
}

void BreakableBrick::SpawnedHandler(pGameObject gameObject)
{
}

void BreakableBrick::DestroyedHandler(pGameObject gameObject)
{
}
