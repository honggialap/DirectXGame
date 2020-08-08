#include "Tilemap.h"

Tilemap::Tilemap(pGameObject gameObject) : Component::Component(gameObject)
{
	type = Component::Type::Tilemap;
	spriteRenderer = gameObject->GetSpriteRenderer();
	map = nullptr;
}

Tilemap::~Tilemap()
{
	if (map != nullptr)
	{
		for (int i = 0; i < mapRow; i++)
			delete[] map[i];
		delete[] map;
	}

	tileSet.clear();
	spriteRenderer = nullptr;
}

void Tilemap::AddTile(string spriteID, int tileNo)
{
	tileSet[tileNo] = spriteID;
}

void Tilemap::AddCell(int column, int row, int tileNo)
{
	map[row][column] = tileNo;
}

void Tilemap::CreateMap(int mapColumn, int mapRow, int tileWidth, int tileHeight, int tileColumn, int tileRow, int margin)
{
	if (map == nullptr)
	{
	this->mapColumn = mapColumn;
	this->mapRow = mapRow;
	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;
	this->tileColumn = tileColumn;
	this->tileRow = tileRow;
	this->margin = margin;

	map = new int* [mapRow];
	for (int i = 0; i < mapRow; i++)
		map[i] = new int[mapColumn];
	}
}

void Tilemap::LoadTileSet()
{
	string spriteID;
	int left, top, right, bottom;
	int tileNo;

	for (int i = 0; i < tileRow; i++)
	{
		for (int j = 0; j < tileColumn; j++)
		{
			spriteID = to_string(i) + "." + to_string(j);
			tileNo = (i * tileColumn + j) + 1;

			left = j * (tileWidth + margin * 2);
			top = i * (tileHeight + margin * 2);
			right = left + tileWidth + margin;
			bottom = top + tileHeight + margin;

			spriteRenderer->Add(spriteID, false, 0,
				left, top, right, bottom, 0, 0);

			AddTile(spriteID, tileNo);
		}
	}
}

void Tilemap::Render()
{
	string spriteID;
	for (int i = 0; i < mapRow; i++)
	{
		for (int j = 0; j < mapColumn; j++)
		{
			float additionX = j * tileWidth;
			float additionY = i * tileHeight;

			spriteRenderer->Render(
				tileSet[map[i][j]],
				additionX,
				-additionY);
		}
	}
}
