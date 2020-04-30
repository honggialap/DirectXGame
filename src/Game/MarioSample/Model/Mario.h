#pragma once
#ifndef __MARIO_H__
#define __MARIO_H__

#include "../Include.h"

#include "../MarioSample.h"

class Mario : public GameObject
{
public:
	Mario();
	~Mario();

	Mario(pGame game, pScene scene);
	void Load(xml_node node);
	void Update(pGameTime gameTime);
	void Render();
};

#endif // !__DEMO_SCENE_H__