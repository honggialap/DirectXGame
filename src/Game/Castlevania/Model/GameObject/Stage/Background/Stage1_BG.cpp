#include "Stage1_BG.h"

Stage1_BG::Stage1_BG(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Background\\Stage1_BG.xml";
}

Stage1_BG::~Stage1_BG()
{
	playScene = nullptr;
}

void Stage1_BG::Load()
{
	GameObject::Load();
}

void Stage1_BG::Unload()
{
	GameObject::Unload();
}

void Stage1_BG::Start()
{
	start = true;
}

void Stage1_BG::Update(float elapsedMs)
{
	if (!start) Start();
}

void Stage1_BG::Render()
{
	GetTilemap()->Render();
}

void Stage1_BG::Collided(pCollision& collision)
{
}

void Stage1_BG::SpawnedHandler(pGameObject gameObject)
{
}

void Stage1_BG::DestroyedHandler(pGameObject gameObject)
{
}