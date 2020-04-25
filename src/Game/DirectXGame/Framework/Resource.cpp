#include "Resource.h"

Resource::Resource(pGraphics graphics, pAudio audio)
{
	this->graphics = graphics;
	this->audio = audio;

	this->textures = new Textures(graphics);
	this->sounds = new Sounds(audio);
	this->sprites = new Sprites();
}

Resource::~Resource()
{
	if (sprites != nullptr)
	{
		delete sprites;
		sprites = nullptr;
	}

	if (sounds != nullptr)
	{
		delete sounds;
		sounds = nullptr;
	}

	if (textures != nullptr)
	{
		delete textures;
		textures = nullptr;
	}

	this->graphics = nullptr;
	this->audio = nullptr;
}

void Resource::LoadData(pGameSettings gameSettings, LPCWSTR filePath)
{
	xml_document doc;
	xml_parse_result result = doc.load_file(filePath);

	xml_node node = doc.child("GameData").child("GameSettings");

	gameSettings->gameTitle = node.attribute("gameTitle").as_string();
	gameSettings->maxFrameRate = node.attribute("maxFrameRate").as_int();
	gameSettings->fullscreen = node.attribute("fullscreen").as_bool();
	gameSettings->widthResolution = node.attribute("widthResolution").as_int();
	gameSettings->heightResolution = node.attribute("heightResolution").as_int();
}

void Resource::LoadContent(LPCWSTR filePath)
{
	xml_document gameDataDoc;
	xml_parse_result result = gameDataDoc.load_file(filePath);
	string source = gameDataDoc.child("GameData").child("GameContent").attribute("source").as_string();

	xml_document gameContentDoc;
	result = gameContentDoc.load_file(source.c_str());

	xml_node texturesNode = gameContentDoc.child("GameContent").child("Textures");
	for (xml_node textureNode = texturesNode.child("Texture");
		textureNode;
		textureNode = textureNode.next_sibling("Texture"))
	{
		textures->Add(
			textureNode.attribute("id").as_string(),
			ToLPCWSTR(textureNode.attribute("source").as_string()),
			D3DCOLOR_XRGB(
				textureNode.attribute("transR").as_int(),
				textureNode.attribute("transG").as_int(),
				textureNode.attribute("transB").as_int())
		);
	}

	xml_node spritesNode = gameContentDoc.child("GameContent").child("Sprites");
	for (xml_node spriteNode = spritesNode.child("Sprite");
		spriteNode;
		spriteNode = spriteNode.next_sibling("Sprite"))
	{
		sprites->Add(
			spriteNode.attribute("id").as_string(),
			textures->Get(spriteNode.attribute("textureId").as_string()),
			spriteNode.attribute("left").as_int(),
			spriteNode.attribute("top").as_int(),
			spriteNode.attribute("right").as_int(),
			spriteNode.attribute("bottom").as_int(),
			spriteNode.attribute("offsetX").as_float(),
			spriteNode.attribute("offsetY").as_float()
		);
	}

	//xml_node animationSets
	//
}

void Resource::LoadScenes(pScenes scenes, LPCWSTR filePath)
{
}

void Resource::LoadScene(pScene scene, LPCWSTR filePath)
{
}

//void Resource::LoadSprite(string gameData)
//{
//}
//
//void Resource::LoadAnimation(string gameData)
//{
//}
//
//void Resource::LoadGameObject()
//{
//}

//bool Resource::Load()
//{
//	return false;
//}
//
//template<class T> T Resource::Get()
//{
//	return T();
//}