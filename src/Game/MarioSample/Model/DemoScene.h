#pragma once
#ifndef __DEMO_SCENE_H__
#define __DEMO_SCENE_H__

#include "../MarioSample.h"

class DemoScene : public Scene
{
public:
	vector<pGameObject> gameObjects;

	void Load();
	void Update(pGameTime gameTime);
	void Render();
};

#endif // !__DEMO_SCENE_H__
