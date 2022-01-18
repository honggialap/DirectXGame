#pragma region INCLUDE
/* Game */

#include "SuperMarioBros3.h"

/* Controller */
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
/* Prop */

#include "Actor/Prop/Platform/Platform.h"

/* Misc */
/* Title */
/* World Map */
#pragma endregion

pGameObject CSuperMarioBros3::Create(pScene scene, unsigned int actor, std::string name, std::string source, float x, float y, int gx, int gy, unsigned int layer)
{
	switch (actor)
	{
	/* Controller */

	/* Character */
	// MARIO
	case ACT_MARIO:
	{
		auto gameObject = new CMario(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_MARIO_TAIL:
	{
		auto gameObject = new CMarioTail(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_MARIO_FIREBALL:
	{
		auto gameObject = new CMarioFireball(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// GOOMBA
	case ACT_GOOMBA:
	{
		auto gameObject = new CGoomba(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_GOOMBA_MICRO:
	{
		auto gameObject = new CMicroGoomba(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// KOOPA
	case ACT_KOOPA:
	{
		auto gameObject = new CKoopa(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_KOOPA_SENSOR:
	{
		auto gameObject = new CKoopaSensor(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// PIRANHA
	case ACT_PIRANHA:
	{
		auto gameObject = new CPiranha(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_PIRANHA_SENSOR:
	{
		auto gameObject = new CPiranhaSensor(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// VENUS
	case ACT_VENUS:
	{
		auto gameObject = new CVenus(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_VENUS_SENSOR:
	{
		auto gameObject = new CVenusSensor(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_VENUS_FIREBALL:
	{
		auto gameObject = new CFireball(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	/* Prop */
	// Platform
	case ACT_PLATFORM:
	{
		auto gameObject = new CPlatform(
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
