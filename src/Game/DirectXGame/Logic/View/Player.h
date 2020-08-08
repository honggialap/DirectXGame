#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../../Include.h"

class Player
{
public:
	pScene scene;
	enum Type
	{
		Local, 
		Remote, 
		Host
	};
	Type type;

public:
	Player(pScene scene);
	virtual ~Player() = 0;
};

#endif // !__PLAYER_H__