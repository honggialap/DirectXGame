#include "GameObject.h"

CGameObject::CGameObject(pGame game, pScene scene, unsigned int id, std::string name, std::string source, float x, float y, int gridX, int gridY, unsigned int layer)
{
	_game = game;
	_scene = scene;
	_id = id;
	_name = name;
	_source = source;
	_x = x;
	_y = y;
	_gx = gridX;
	_gy = gridY;
	_layer = layer;
}

CGameObject::~CGameObject()
{
}

void CGameObject::Load()
{
}

void CGameObject::Destroy()
{
}
