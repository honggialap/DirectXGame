#pragma once
#ifndef __TILEMAP_H__
#define __TILEMAP_H__

#include "../../Include.h"
#include "Component.h"
#include "Sprite.h"

class Tilemap : public Component
{
private:
	pSpriteRenderer spriteRenderer;

	int** map;
	int tileWidth, tileHeight;
	int tileColumn, tileRow;
	unordered_map<int, string> tileSet;
	int margin;

public:
	int mapColumn, mapRow;
	Tilemap(pGameObject gameObject);
	~Tilemap();

	void CreateMap(int mapColumn, int mapRow, int tileWidth, int tileHeight, int tileColumn, int tileRow, int margin = 1);
	void LoadTileSet();
	void AddTile(string spriteID, int tileNo);
	void AddCell(int column, int row, int tileNo);

	void Render();
};

#endif // !__TILEMAP_H__
