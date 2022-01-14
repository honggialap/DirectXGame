#pragma region INCLUDE
/* Game */

#include "SuperMarioBros3.h"

/* Controller */
/* Character */

#include "Actor/Character/Mario/Mario.h"
#include "Actor/Character/Mario/MarioTail.h"
#include "Actor/Character/Mario/MarioFireball.h"

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
		// Mario
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
