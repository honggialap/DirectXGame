#include "Resource.h"

Resource::Resource(pGraphics graphics, pAudio audio)
{
	this->graphics = graphics;
	this->audio = audio;
	this->textures = new Textures(graphics);
	this->fonts = new Fonts();
	this->soundBank = new SoundBank(audio);
}

Resource::~Resource()
{
	if (textures != nullptr)
	{
		delete textures;
		textures = nullptr;
	}

	if (fonts != nullptr)
	{
		delete fonts;
		fonts = nullptr;
	}

	if (soundBank != nullptr)
	{
		delete soundBank;
		soundBank = nullptr;
	}

	this->graphics = nullptr;
	this->audio = nullptr;
}

void Resource::LoadGameData(LPCWSTR filePath)
{
	gameDataDoc.load_file(filePath);
	source = gameDataDoc.child("GameData").child("GameContent")
		.attribute("source").as_string();
}

void Resource::LoadGameSettings(pGame game)
{
	xml_node node = gameDataDoc.child("GameData").child("GameSettings");

	game->gameSettings->gameTitle = node.attribute("gameTitle").as_string();
	game->gameSettings->maxFrameRate = node.attribute("maxFrameRate").as_int();
	game->gameSettings->fullscreen = node.attribute("fullscreen").as_bool();
	game->gameSettings->widthResolution = node.attribute("widthResolution").as_int();
	game->gameSettings->heightResolution = node.attribute("heightResolution").as_int();
}

void Resource::LoadContent()
{
	LoadTextures();
	LoadSoundBank();
	LoadFonts();
}

void Resource::LoadTextures()
{
	xml_document gameContent;
	gameContent.load_file(source.c_str());

	xml_node texturesNode = gameContent.child("GameContent").child("Textures");
	for (xml_node textureNode = texturesNode.child("Texture");
		textureNode;
		textureNode = textureNode.next_sibling("Texture"))
	{
		textures->Add(
			textureNode.attribute("textureID").as_string(),
			ToLPCWSTR(textureNode.attribute("source").as_string()),
			textureNode.attribute("transR").as_int(),
			textureNode.attribute("transG").as_int(),
			textureNode.attribute("transB").as_int());
	}
}

void Resource::LoadSoundBank()
{
	xml_document gameContent;
	gameContent.load_file(source.c_str());

}

void Resource::LoadFonts()
{
	xml_document gameContent;
	gameContent.load_file(source.c_str());

}
