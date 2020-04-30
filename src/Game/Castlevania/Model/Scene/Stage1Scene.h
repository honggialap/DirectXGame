#pragma once
#ifndef __STAGE_1_SCENE_H
#define __STAGE_1_SCENE_H

#include "../../Include.h"
#include "../../Castlevania.h"
#include "../GameObject/Simon/Simon.h"

class Stage1Scene : public Scene
{
public:
	Stage1Scene(pGame game);

	void Load();
	void Unload();

	void Spawn(string gameObjectId);
	void Despawn(string gameObjectId);

	void Update(pGameTime gameTime);
	void Render();
};

#endif // !__STAGE_1_SCENE_H