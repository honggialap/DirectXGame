#include "Stage3A_BG.h"

Stage3A_BG::Stage3A_BG(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Background\\Stage3A_BG.xml";
}

Stage3A_BG::~Stage3A_BG()
{
	playScene = nullptr;
}

void Stage3A_BG::Load()
{
	GameObject::Load();
}

void Stage3A_BG::Unload()
{
	GameObject::Unload();
}

void Stage3A_BG::Start()
{
	start = true;
}

void Stage3A_BG::Update(float elapsedMs)
{
	if (!start)	Start();
}

void Stage3A_BG::Render()
{
	GetTilemap()->Render();
}

void Stage3A_BG::Collided(pCollision& collision)
{
}

void Stage3A_BG::SpawnedHandler(pGameObject gameObject)
{
}

void Stage3A_BG::DestroyedHandler(pGameObject gameObject)
{
}