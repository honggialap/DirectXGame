#pragma once
#ifndef __PLAYSCENE_H__
#define __PLAYSCENE_H__

#include "../../Include.h"
#include "../../../DirectXGame/Logic/Scene.h"

//// Sandbox
#include "../GameObject/Demo/Demo.h"

//// Title
#include "../GameObject/Title/Title.h"
#include "../GameObject/Title/Title_Bat.h"
#include "../GameObject/Title/Title_BG.h"
#include "../GameObject/Title/Title_Label.h"

//// Intro
#include "../GameObject/Intro/Intro.h"
#include "../GameObject/Intro/Intro_Bat1.h"
#include "../GameObject/Intro/Intro_Bat2.h"
#include "../GameObject/Intro/Intro_BG.h"
#include "../GameObject/Intro/Intro_Cloud.h"
#include "../GameObject/Intro/Intro_Simon.h"

//// Stage
#include "../GameObject/Stage/GameMaster.h"
#include "../GameObject/Stage/HUD.h"

// Map
#include "../GameObject/Stage/Map/Stage1.h"
#include "../GameObject/Stage/Map/Stage2A.h"
#include "../GameObject/Stage/Map/Stage2B.h"
#include "../GameObject/Stage/Map/Stage3A.h"
#include "../GameObject/Stage/Map/Stage3B.h"
#include "../GameObject/Stage/Map/Stage4.h"

// Background
#include "../GameObject/Stage/Background/Stage1_BG.h"
#include "../GameObject/Stage/Background/Stage2A_BG.h"
#include "../GameObject/Stage/Background/Stage2B_BG.h"
#include "../GameObject/Stage/Background/Stage3A_BG.h"
#include "../GameObject/Stage/Background/Stage3B_BG.h"
#include "../GameObject/Stage/Background/Stage4_BG.h"

// Effect
#include "../GameObject/Stage/Effect/BrokenBrickEffect.h"
#include "../GameObject/Stage/Effect/Death1Effect.h"
#include "../GameObject/Stage/Effect/Death2Effect.h"
#include "../GameObject/Stage/Effect/Death3Effect.h"
#include "../GameObject/Stage/Effect/HitEffect.h"
#include "../GameObject/Stage/Effect/Text/Text100Effect.h"
#include "../GameObject/Stage/Effect/Text/Text400Effect.h"
#include "../GameObject/Stage/Effect/Text/Text700Effect.h"
#include "../GameObject/Stage/Effect/Text/Text1000Effect.h"
#include "../GameObject/Stage/Effect/Text/Text2000Effect.h"
#include "../GameObject/Stage/Effect/Text/Text4000Effect.h"

// Enemy
#include "../GameObject/Stage/Enemy/BlackKnight/BlackKnight.h"
#include "../GameObject/Stage/Enemy/BlackKnight/BlackKnightTrigger.h"
#include "../GameObject/Stage/Enemy/Ghost/Ghost.h"
#include "../GameObject/Stage/Enemy/Ghost/GhostSpawnZone.h"
#include "../GameObject/Stage/Enemy/Ghost/GhostTrigger.h"
#include "../GameObject/Stage/Enemy/Hunchback/Hunchback.h"
#include "../GameObject/Stage/Enemy/Hunchback/HunchbackTrigger.h"
#include "../GameObject/Stage/Enemy/PhantomBat/Fireball.h"
#include "../GameObject/Stage/Enemy/PhantomBat/PhantomBat.h"
#include "../GameObject/Stage/Enemy/PhantomBat/PhantomBatTrigger.h"
#include "../GameObject/Stage/Enemy/Raven/Raven.h"
#include "../GameObject/Stage/Enemy/Raven/RavenTrigger.h"
#include "../GameObject/Stage/Enemy/Skeleton/Skeleton.h"
#include "../GameObject/Stage/Enemy/Skeleton/SkeletonBone.h"
#include "../GameObject/Stage/Enemy/Skeleton/SkeletonTrigger.h"
#include "../GameObject/Stage/Enemy/VampireBat/VampireBat.h"
#include "../GameObject/Stage/Enemy/VampireBat/VampireBatSpawnZone.h"
#include "../GameObject/Stage/Enemy/VampireBat/VampireBatTrigger.h"
#include "../GameObject/Stage/Enemy/Zombie/Zombie.h"
#include "../GameObject/Stage/Enemy/Zombie/ZombieSpawnZone.h"

// Pickup
#include "../GameObject/Stage/Pickup/Bonus/Crown.h"
#include "../GameObject/Stage/Pickup/Bonus/Moai.h"
#include "../GameObject/Stage/Pickup/Bonus/MoneyBag100.h"
#include "../GameObject/Stage/Pickup/Bonus/MoneyBag400.h"
#include "../GameObject/Stage/Pickup/Bonus/MoneyBag700.h"
#include "../GameObject/Stage/Pickup/Bonus/MoneyBag1000.h"
#include "../GameObject/Stage/Pickup/Bonus/TreasureChest.h"
#include "../GameObject/Stage/Pickup/Item/Cross.h"
#include "../GameObject/Stage/Pickup/Item/ExtraLife.h"
#include "../GameObject/Stage/Pickup/Item/LargeHeart.h"
#include "../GameObject/Stage/Pickup/Item/MagicCrystal.h"
#include "../GameObject/Stage/Pickup/Item/PorkChop.h"
#include "../GameObject/Stage/Pickup/Item/Potion.h"
#include "../GameObject/Stage/Pickup/Item/SmallHeart.h"
#include "../GameObject/Stage/Pickup/Weapon/AxeItem.h"
#include "../GameObject/Stage/Pickup/Weapon/BoomerangItem.h"
#include "../GameObject/Stage/Pickup/Weapon/DaggerItem.h"
#include "../GameObject/Stage/Pickup/Weapon/DoubleShot.h"
#include "../GameObject/Stage/Pickup/Weapon/FirebombItem.h"
#include "../GameObject/Stage/Pickup/Weapon/MorningStar.h"
#include "../GameObject/Stage/Pickup/Weapon/StopwatchItem.h"
#include "../GameObject/Stage/Pickup/Weapon/TripleShot.h"

// Prop
#include "../GameObject/Stage/Prop/BreakableBrick.h"
#include "../GameObject/Stage/Prop/Candle.h"
#include "../GameObject/Stage/Prop/DeadZone.h"
#include "../GameObject/Stage/Prop/Door.h"
#include "../GameObject/Stage/Prop/MovingPlatform.h"
#include "../GameObject/Stage/Prop/Platform.h"
#include "../GameObject/Stage/Prop/Stair.h"
#include "../GameObject/Stage/Prop/StairEnd.h"
#include "../GameObject/Stage/Prop/Tourch.h"

// Simon
#include "../GameObject/Stage/Simon/Axe.h"
#include "../GameObject/Stage/Simon/Boomerang.h"
#include "../GameObject/Stage/Simon/Dagger.h"
#include "../GameObject/Stage/Simon/Firebomb.h"
#include "../GameObject/Stage/Simon/Simon.h"
#include "../GameObject/Stage/Simon/Stopwatch.h"
#include "../GameObject/Stage/Simon/VampireKiller.h"

class PlayScene : public Scene
{
public:	
	PlayScene(pGame game);
	~PlayScene();

	virtual void Load();
	virtual void Unload();

	pGameObject Spawn(string prefabID, float positionX, float positionY);
};

#endif // !__PLAYSCENE__