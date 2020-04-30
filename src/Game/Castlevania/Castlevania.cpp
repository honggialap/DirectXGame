#include "Castlevania.h"

Castlevania::Castlevania(HINSTANCE hInstance) : Game::Game(hInstance)
{
}

Castlevania::~Castlevania()
{
}

void Castlevania::Load(LPCWSTR dataFilePath)
{
	Game::Load(dataFilePath);
	LoadScenes(dataFilePath);
	resource->LoadContent(dataFilePath);
}

void Castlevania::LoadPrefabs(LPCWSTR dataFilePath)
{
	xml_document gameDataDoc;
	xml_parse_result result = gameDataDoc.load_file(dataFilePath);
	string source = gameDataDoc.child("GameData").child("GameContent").attribute("source").as_string();

	xml_document gameContentDoc;
	result = gameContentDoc.load_file(source.c_str());

	
}

void Castlevania::LoadScenes(LPCWSTR dataFilePath)
{
	xml_document gameDataDoc;
	xml_parse_result result = gameDataDoc.load_file(dataFilePath);
	xml_node scenesNode = gameDataDoc.child("GameData").child("Scenes");
	for (xml_node sceneNode = scenesNode.child("Scene");
		sceneNode;
		sceneNode = sceneNode.next_sibling("Scene"))
	{
		string sceneType = sceneNode.attribute("type").as_string();
		if (sceneType == "Stage1Scene")
		{
			pStage1Scene scene = new Stage1Scene(this);
			scene->id = sceneNode.attribute("id").as_string();
			scene->sceneData = sceneNode.attribute("source").as_string();
			scenes->Add(scene->id, scene);
		}
	}
}
