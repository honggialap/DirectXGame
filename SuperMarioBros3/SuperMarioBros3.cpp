#pragma region INCLUDE
/* Game */
#include "SuperMarioBros3.h"

/* Controller */
#include "Actor/Controller/GameMaster.h"

/* Character */
#include "Actor/Character/Mario/Mario.h"
#include "Actor/Character/Mario/MarioTail.h"
#include "Actor/Character/Mario/MarioFireball.h"

#include "Actor/Character/Goomba/Goomba.h"
#include "Actor/Character/Goomba/MicroGoomba.h"

#include "Actor/Character/Koopa/Koopa.h"
#include "Actor/Character/Koopa/KoopaSensor.h"

#include "Actor/Character/Piranha/Piranha.h"
#include "Actor/Character/Piranha/PiranhaSensor.h"

#include "Actor/Character/Venus/Venus.h"
#include "Actor/Character/Venus/VenusSensor.h"
#include "Actor/Character/Venus/Fireball.h"

/* Item */
#include "Actor/Item/Coin.h"
#include "Actor/Item/ExtraLifeMushroom.h"
#include "Actor/Item/SuperMushroom.h"
#include "Actor/Item/SuperLeaf.h"
#include "Actor/Item/FireFlower.h"
#include "Actor/Item/SuperStar.h"

/* Prop */
#include "Actor/Prop/Platform.h"
#include "Actor/Prop/Brick.h"
#include "Actor/Prop/Block.h"

/* Misc */
/* Title */
/* World Map */
#pragma endregion

pGameObject CSuperMarioBros3::Create(pScene scene, unsigned int actor, std::string name, std::string source, float x, float y, int gx, int gy, unsigned int layer)
{
	switch (actor)
	{
		/* Controller */
	case ACT_GAMEMASTER:
	{
		//auto gameObject = new CGameMaster(
		//	this, scene, nextId++,
		//	name, source,
		//	x, y, gx, gy, layer
		//);
		//Add(gameObject);
		//gameObject->Load();
		//return gameObject;
	}
	break;



	default:
		return nullptr;
		break;
	}
}
