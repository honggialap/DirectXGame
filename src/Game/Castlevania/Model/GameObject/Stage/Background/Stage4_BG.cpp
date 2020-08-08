#include "Stage4_BG.h"

Stage4_BG::Stage4_BG(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Background\\Stage4_BG.xml";
}

Stage4_BG::~Stage4_BG()
{
	playScene = nullptr;
}

void Stage4_BG::Load()
{
	GameObject::Load();
}

void Stage4_BG::Unload()
{
	GameObject::Unload();
}

void Stage4_BG::Start()
{
	start = true;
}

void Stage4_BG::Update(float elapsedMs)
{
	if (!start) Start();
}

void Stage4_BG::Render()
{
	GetTilemap()->Render();
}

void Stage4_BG::Collided(pCollision& collision)
{
}

void Stage4_BG::SpawnedHandler(pGameObject gameObject)
{
}

void Stage4_BG::DestroyedHandler(pGameObject gameObject)
{
}