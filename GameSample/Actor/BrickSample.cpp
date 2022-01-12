#include "BrickSample.h"

void CBrickSample::Load()
{
	CGameObject::Load();

	/* Read file */
	pugi::xml_document prefab;
	prefab.load_file(_source.c_str());

	/* Body */
	pugi::xml_node bodyNode = prefab.child("Prefab").child("Body");
	_renderBody = bodyNode.attribute("render").as_bool();
	BODY_WIDTH = bodyNode.attribute("width").as_float();
	BODY_HEIGHT = bodyNode.attribute("height").as_float();
	BODY_OFFSETX = bodyNode.attribute("offsetX").as_float();
	BODY_OFFSETY = bodyNode.attribute("offsetY").as_float();
}

void CBrickSample::Start()
{
	CGameObject::Start();
	_animations[ANI_BRICK]->Play(true);
}

void CBrickSample::Update(float elapsedMs)
{
	if (!_start) Start();
	_animations[ANI_BRICK]->Update(elapsedMs);
}

void CBrickSample::Render()
{
	if (_renderBody) _sprites[BBOX]->Render(_x, _y);
	_animations[ANI_BRICK]->Render(_x, _y);
}

int CBrickSample::IsCollidable()
{
	return 1;
}

int CBrickSample::IsBlocking()
{
	return 1;
}

void CBrickSample::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = _x + BODY_OFFSETX - (BODY_WIDTH / 2);
	right = _x + BODY_OFFSETX + (BODY_WIDTH / 2);
	top = _y + BODY_OFFSETY + (BODY_HEIGHT / 2);
	bottom = _y + BODY_OFFSETY - (BODY_HEIGHT / 2);
}
