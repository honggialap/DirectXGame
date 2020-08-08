#include "Stage2A_BG.h"

Stage2A_BG::Stage2A_BG(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Background\\Stage2A_BG.xml";
}

Stage2A_BG::~Stage2A_BG()
{
	playScene = nullptr;
}

void Stage2A_BG::Load()
{
	GameObject::Load();
}

void Stage2A_BG::Unload()
{
	GameObject::Unload();
}

void Stage2A_BG::Start()
{
	start = true;
}

void Stage2A_BG::Update(float elapsedMs)
{
	if (!start)	Start();
}

void Stage2A_BG::Render()
{
	GetTilemap()->Render();
}

void Stage2A_BG::Collided(pCollision& collision)
{
}

void Stage2A_BG::SpawnedHandler(pGameObject gameObject)
{
}

void Stage2A_BG::DestroyedHandler(pGameObject gameObject)
{
}