#pragma region INCLUDE
/* Game */
#include "SuperMarioBros3.h"


/* Controller */
#include "Actor/Controller/GameMaster/GameMaster.h"
#include "Actor/Controller/Title/Title.h"
#include "Actor/Controller/WorldMap/WorldMap.h"
#include "Actor/Controller/World/World.h"


/* Character */
#include "Actor/Character/Mario/Mario.h"
#include "Actor/Character/Mario/MarioTail.h"
#include "Actor/Character/Mario/MarioFireball.h"
#include "Actor/Character/Goomba/Goomba.h"
#include "Actor/Character/Goomba/MicroGoomba.h"
#include "Actor/Character/Koopa/Koopa.h"
#include "Actor/Character/Koopa/KoopaSensor.h"
#include "Actor/Character/Plant/Plant.h"
#include "Actor/Character/Plant/PlantSensor.h"
#include "Actor/Character/Plant/PlantFireball.h"


/* Item */
#include "Actor/Item/Coin/Coin.h"
#include "Actor/Item/SuperMushroom/SuperMushroom.h"
#include "Actor/Item/FireFlower/FireFlower.h"
#include "Actor/Item/SuperLeaf/SuperLeaf.h"
#include "Actor/Item/Starman/Starman.h"
#include "Actor/Item/ExtraLifeMushroom/ExtraLifeMushroom.h"


/* Prop */
#include "Actor/Prop/Platform/Platform.h"
#include "Actor/Prop/Block/Block.h"
#include "Actor/Prop/Brick/Brick.h"
#include "Actor/Prop/Relay/Relay.h"
#include "Actor/Prop/Pipe/Pipe.h"
#include "Actor/Prop/Pipe/TransportPipe.h"
#include "Actor/Prop/SpawnZone/SpawnZone.h"
#include "Actor/Prop/DeadZone/DeadZone.h"
#include "Actor/Prop/Goal/Goal.h"


/* Misc */
#include "Actor/Misc/Background/Background.h"
#include "Actor/Misc/HUD/HUD.h"
#include "Actor/Misc/HUD/PowerBar.h"
#include "Actor/Misc/ScoreEffect/ScoreEffect.h"
#include "Actor/Misc/BrickFragEffect/BrickFragEffect.h"
#include "Actor/Misc/HitEffect/HitEffect.h"
#include "Actor/Misc/DeathEffect/DeathEffect.h"


/* Title */
/* World Map */
#pragma endregion

pGameObject CSuperMarioBros3::Create(pScene scene, unsigned int actor, std::string name, std::string source, float x, float y, int gx, int gy, unsigned int layer)
{
	switch (actor)
	{
	/* Controller */
	// Game Master
	case ACT_GAMEMASTER:
	{
		auto gameObject = new CGameMaster(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Title
	case ACT_TITLE:
	{
		auto gameObject = new CTitle(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// World Map
	case ACT_WORLDMAP:
	{
		auto gameObject = new CWorldMap(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// World
	case ACT_WORLD:
	{
		auto gameObject = new CWorld(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;


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

	// Goomba
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

	// Koopa
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

	// Plant
	case ACT_PLANT:
	{
		auto gameObject = new CPlant(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_PLANT_SENSOR:
	{
		auto gameObject = new CPlantSensor(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_PLANT_FIREBALL:
	{
		auto gameObject = new CPlantFireball(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;


	/* Item */
	// Coin
	case ACT_COIN:
	{
		auto gameObject = new CCoin(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Super Mushroom
	case ACT_SUPER_MUSHROOM:
	{
		auto gameObject = new CSuperMushroom(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Fire Flower
	case ACT_FIRE_FLOWER:
	{
		auto gameObject = new CFireFlower(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Super Leaf
	case ACT_SUPER_LEAF:
	{
		auto gameObject = new CSuperLeaf(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Starman
	case ACT_STARMAN:
	{
		auto gameObject = new CStarman(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Extra Life Mushroom
	case ACT_EXTRA_LIFE_MUSHROOM:
	{
		auto gameObject = new CExtraLifeMushroom(
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
	// Block
	case ACT_BLOCK:
	{
		auto gameObject = new CBlock(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Brick
	case ACT_BRICK:
	{
		auto gameObject = new CBrick(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

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

	// Relay
	case ACT_RELAY:
	{
		auto gameObject = new CRelay(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Pipe
	case ACT_PIPE:
	{
		auto gameObject = new CPipe(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_TRANSPORT_PIPE:
	{
		auto gameObject = new CTransportPipe(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Spawm Zone
	case ACT_SPAWN_ZONE:
	{
		auto gameObject = new CSpawnZone(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Dead Zone
	case ACT_DEAD_ZONE:
	{
		auto gameObject = new CDeadZone(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Goal
	case ACT_GOAL:
	{
		auto gameObject = new CGoal(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;


	/* Misc */
	// Background
	case ACT_BACKGROUND:
	{
		auto gameObject = new CBackground(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// HUD
	case ACT_HUD:
	{
		auto gameObject = new CHUD(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	case ACT_POWER_BAR:
	{
		auto gameObject = new CPowerBar(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Score Effect
	case ACT_SCORE_EFFECT:
	{
		auto gameObject = new CScoreEffect(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Brick Frag Effect
	case ACT_BRICK_FRAG_EFFECT:
	{
		auto gameObject = new CBrickFragEffect(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Hit Effect
	case ACT_HIT_EFFECT:
	{
		auto gameObject = new CHitEffect(
			this, scene, nextId++,
			name, source,
			x, y, gx, gy, layer
		);
		Add(gameObject);
		gameObject->Load();
		return gameObject;
	}
	break;

	// Death Effect
	case ACT_DEATH_EFFECT:
	{
		auto gameObject = new CDeathEffect(
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
