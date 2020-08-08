#ifndef __LOCAL_PLAYER_H__
#define __LOCAL_PLAYER_H__

#include "../Player.h"
#include "Control.h"
#include "Viewport.h"

class LocalPlayer : public Player
{
public:
	pViewport viewport;
	pController controller;

	LocalPlayer(pScene scene);
	~LocalPlayer();
};

#endif // !__LOCAL_PLAYER_H__