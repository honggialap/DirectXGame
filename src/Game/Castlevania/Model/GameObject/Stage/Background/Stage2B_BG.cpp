#include "Stage2B_BG.h"

Stage2B_BG::Stage2B_BG(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Background\\Stage2B_BG.xml";
}

Stage2B_BG::~Stage2B_BG()
{
	playScene = nullptr;
}

void Stage2B_BG::Load()
{
	GameObject::Load();
}

void Stage2B_BG::Unload()
{
	GameObject::Unload();
}

void Stage2B_BG::Start()
{
	start = true;
}

void Stage2B_BG::Update(float elapsedMs)
{
	if (!start) Start();
}

void Stage2B_BG::Render()
{
	GetTilemap()->Render();
}

void Stage2B_BG::Collided(pCollision& collision)
{
}

void Stage2B_BG::SpawnedHandler(pGameObject gameObject)
{
}

void Stage2B_BG::DestroyedHandler(pGameObject gameObject)
{
}