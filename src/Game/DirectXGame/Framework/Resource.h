#pragma once
#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include "../Include.h"
#include "../Game.h"
#include "Graphics.h"
#include "Audio.h"
#include "Content/Texture.h"
#include "Content/Font.h"
#include "Content/Sound.h"

class Resource
{
private:
	pGraphics graphics;
	pAudio audio;

public:
	xml_document gameDataDoc;
	string source;

	pTextures textures;
	pSoundBank soundBank;
	pFonts fonts;

public:
	Resource(pGraphics graphics, pAudio audio);
	~Resource();

	void LoadGameData(LPCWSTR filePath);
	void LoadGameSettings(pGame game);
	
	void LoadContent();
	void LoadTextures();
	void LoadSoundBank();
	void LoadFonts();
};

#endif // !__RESOURCE_H__