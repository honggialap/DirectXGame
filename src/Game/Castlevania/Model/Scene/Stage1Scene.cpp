#include "Stage1Scene.h"

Stage1Scene::Stage1Scene(pGame game) : Scene::Scene(game)
{
}

void Stage1Scene::Load()
{
	xml_document sceneDataDoc;
	xml_parse_result result = sceneDataDoc.load_file(sceneData.c_str());
	xml_node gameObjectsNode = sceneDataDoc.child("Scene").child("GameObjects");
	for (xml_node gameObjectNode = gameObjectsNode.child("GameObject");
		gameObjectNode;
		gameObjectNode = gameObjectNode.next_sibling("GameObject"))
	{
		string gameObjectType = gameObjectNode.attribute("type").as_string();
		if (gameObjectType == "Simon")
		{
			pSimon simon = new Simon(game, this);
			simon->Load(gameObjectNode);
			gameObjects->Add(simon);
		}
	}
}

void Stage1Scene::Unload()
{
}

void Stage1Scene::Spawn(string gameObjectId)
{
}

void Stage1Scene::Despawn(string gameObjectId)
{
}

void Stage1Scene::Update(pGameTime gameTime)
{
	//gameObjects->SortByUpdateOrder();
	for (size_t i = 0; i < gameObjects->gameObjects.size(); i++)
	{
		gameObjects->gameObjects[i]->Update(gameTime);
	}
}

void Stage1Scene::Render()
{
	//gameObjects->SortByRenderOrder();
	for (size_t i = 0; i < gameObjects->gameObjects.size(); i++)
	{
		gameObjects->gameObjects[i]->Render();
	}
}
