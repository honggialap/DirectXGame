#include "MarioSample.h"

MarioSample::MarioSample(HINSTANCE hInstance) : Game::Game(hInstance)
{
}

void MarioSample::LoadScenes(LPCWSTR dataFilePath)
{
	xml_document gameDataDoc;
	xml_parse_result result = gameDataDoc.load_file(dataFilePath);
	xml_node scenesNode = gameDataDoc.child("GameData").child("Scenes");
	for (xml_node sceneNode = scenesNode.child("Scene");
		sceneNode;
		sceneNode = sceneNode.next_sibling("Scene"))
	{
		string sceneType = sceneNode.attribute("sceneType").as_string();
		if (sceneType == "DemoScene")
		{
			pDemoScene scene = new DemoScene(this);
			scene->id = sceneNode.attribute("id").as_string();
			scene->sceneData = sceneNode.attribute("source").as_string();
			scenes->Add(scene->id, scene);
		}
	}
}

void MarioSample::Load(LPCWSTR dataFilePath)
{
	Game::Load(dataFilePath);
	LoadScenes(dataFilePath);
	resource->LoadContent(dataFilePath);
}
