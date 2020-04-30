#pragma once
#ifndef __DEMO_SCENE_H__
#define __DEMO_SCENE_H__

#include "../Include.h"

#include "../MarioSample.h"
#include "../Model/Mario.h"

class DemoScene : public Scene
{
public:
	DemoScene(pGame game);

	void Load();
	void Unload();

	void Spawn(string gameObjectId);
	void Despawn(string gameObjectId);

	void Update(pGameTime gameTime);
	void Render();
};

#endif // !__DEMO_SCENE_H__
