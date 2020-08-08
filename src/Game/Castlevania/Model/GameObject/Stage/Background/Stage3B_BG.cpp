#include "Stage3B_BG.h"

Stage3B_BG::Stage3B_BG(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Background\\Stage3B_BG.xml";
}

Stage3B_BG::~Stage3B_BG()
{
	playScene = nullptr;
}

void Stage3B_BG::Load()
{
	GameObject::Load();
}

void Stage3B_BG::Unload()
{
	GameObject::Unload();
}

void Stage3B_BG::Start()
{
	start = true;
}

void Stage3B_BG::Update(float elapsedMs)
{
	if (!start) Start();
}

void Stage3B_BG::Render()
{
	GetTilemap()->Render();
}

void Stage3B_BG::Collided(pCollision& collision)
{
}

void Stage3B_BG::SpawnedHandler(pGameObject gameObject)
{
}

void Stage3B_BG::DestroyedHandler(pGameObject gameObject)
{
}