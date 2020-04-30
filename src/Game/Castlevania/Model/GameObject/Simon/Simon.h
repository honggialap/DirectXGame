#pragma once
#ifndef __SIMON_H__
#define __SIMON_H__

#include "../../../Include.h"
#include "../../../Castlevania.h"

class Simon : public GameObject
{
public:
	Simon(pGame game, pScene scene);
	~Simon();

	void Load(xml_node node);
	void Update(pGameTime gameTime);
	void Render();
};

#endif //!__SIMON_H__