#include "Title_BG.h"

Title_BG::Title_BG(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Title\\Title_BG.xml";
}

Title_BG::~Title_BG()
{
}

void Title_BG::Load()
{
	GameObject::Load();
}

void Title_BG::Unload()
{
	GameObject::Unload();
}

void Title_BG::Start()
{
	start = true;
}

void Title_BG::Update(float elapsedMs)
{
	if (!start) Start();
}

void Title_BG::Render()
{
	GetSpriteRenderer()->Render("title");
}

void Title_BG::Collided(pCollision& collision)
{
}

void Title_BG::SpawnedHandler(pGameObject gameObject)
{
}

void Title_BG::DestroyedHandler(pGameObject gameObject)
{
}