#include "Resource.h"

Resource::Resource(pGraphics graphics)
{
	this->graphics = graphics;
	this->textures = new Textures(this, graphics);
	this->spriteAtlas = new SpriteAtlas(this);
	this->sprites = new Sprites(this);
	//this->animations = new Animations(this);
	//this->tilemaps = new Tilemaps(this);
}

Resource::~Resource()
{
	//if (tilemaps != nullptr)
	//{
	//	delete tilemaps;
	//	tilemaps = nullptr;
	//}

	//if (animations != nullptr)
	//{
	//	delete animations;
	//	animations = nullptr;
	//}

	if (sprites != nullptr)
	{
		delete sprites;
		sprites = nullptr;
	}

	if (spriteAtlas != nullptr)
	{
		delete spriteAtlas;
		spriteAtlas = nullptr;
	}

	if (textures != nullptr)
	{
		delete textures;
		textures = nullptr;
	}

	this->graphics = nullptr;
}

void Resource::LoadGameSettings(pGameSettings gameSettings, LPCWSTR filePath)
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
			textureNode.attribute("textureID").as_string(),
			ToLPCWSTR(textureNode.attribute("source").as_string()),
			D3DCOLOR_XRGB(
				textureNode.attribute("transR").as_int(),
				textureNode.attribute("transG").as_int(),
				textureNode.attribute("transB").as_int()));
	}

	xml_node spriteAtlasNode = gameContentDoc.child("GameContent").child("SpriteAtlas");
	for (xml_node textureRegionNode = spriteAtlasNode.child("TextureRegion");
		textureRegionNode;
		textureRegionNode = textureRegionNode.next_sibling("TextureRegion"))
	{
		spriteAtlas->Add(
			textureRegionNode.attribute("textureRegionID").as_string(),
			textureRegionNode.attribute("textureID").as_string(),
			textureRegionNode.attribute("left").as_int(),
			textureRegionNode.attribute("top").as_int(),
			textureRegionNode.attribute("right").as_int(),
			textureRegionNode.attribute("bottom").as_int());
	}

	xml_node spritesNode = gameContentDoc.child("GameContent").child("Sprites");
	for (xml_node spriteNode = spritesNode.child("Sprite");
		spriteNode;
		spriteNode = spritesNode.next_sibling("Sprite"))
	{
		sprites->Add(
			spriteNode.attribute("spriteID").as_string(),
			spriteNode.attribute("textureRegionID").as_string(),
			spriteNode.attribute("offsetX").as_float(),
			spriteNode.attribute("offsetY").as_float());
	}

}