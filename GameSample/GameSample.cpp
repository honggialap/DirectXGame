#include "GameSample.h"

#include "Actor/BrickSample.h"
#include "Actor/CoinSample.h"
#include "Actor/GameMasterSample.h"
#include "Actor/GoombaSample.h"
#include "Actor/MarioSample.h"
#include "Actor/PortalSample.h"

pGameObject CGameSample::Create(pScene scene, unsigned int actor, std::string name, std::string source, float x, float y, int gx, int gy, unsigned int layer)
{
	switch (actor)
	{
	
	case ACT_GAMEMASTER_SAMPLE:
	{
		auto gameObject = new CGameMasterSample(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_MARIO_SAMPLE:
	{
		auto gameObject = new CMarioSample(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_GOOMBA_SAMPLE:
	{
		auto gameObject = new CGoombaSample(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_COIN_SAMPLE:
	{
		auto gameObject = new CCoinSample(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_BRICK_SAMPLE:
	{
		auto gameObject = new CBrickSample(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_PORTAL_SAMPLE:
	{
		auto gameObject = new CPortalSample(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	default:
		return nullptr;
		break;
	}
}