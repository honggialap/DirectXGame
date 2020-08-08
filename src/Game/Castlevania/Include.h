#pragma once
#ifndef __CASTLEVANIA_INCLUDE_H__
#define __CASTLEVANIA_INCLUDE_H__

#include "../DirectXGame/Include.h"

#pragma region Game

class Castlevania;
typedef Castlevania* pCastlevania;

#pragma endregion

#pragma region Scene

class PlayScene;
typedef PlayScene* pPlayScene;

#pragma endregion

#pragma region GameObject

#pragma region Title

class Title;
typedef Title* pTitle;

class Title_Bat;
typedef Title_Bat* pTitle_Bat;

class Title_BG;
typedef Title_BG* pTitle_BG;

class Title_Label;
typedef Title_Label* pTitle_Label;

#pragma endregion

#pragma region Intro

class Intro;
typedef Intro* pIntro;

class Intro_Bat1;
typedef Intro_Bat1* pIntro_Bat1;

class Intro_Bat2;
typedef Intro_Bat2* pIntro_Bat2;

class Intro_BG;
typedef Intro_BG* pIntro_BG;

class Intro_Cloud;
typedef Intro_Cloud* pIntro_Cloud;

class Intro_Simon;
typedef Intro_Simon* pIntro_Simon;

#pragma endregion

#pragma region Stage

class GameMaster;
typedef GameMaster* pGameMaster;

class HUD;
typedef HUD* pHUD;

#pragma region Map

class Stage1;
typedef Stage1* pStage1;

class Stage2A;
typedef Stage2A* pStage2A;

class Stage2B;
typedef Stage2B* pStage2B;

class Stage3A;
typedef Stage3A* pStage3A;

class Stage3B;
typedef Stage3B* pStage3B;

class Stage4;
typedef Stage4* pStage4;

#pragma endregion


#pragma region Simon

class Simon;
typedef Simon* pSimon;

class VampireKiller;
typedef VampireKiller* pVampireKiller;

class Axe;
typedef Axe* pAxe;

class Boomerang;
typedef Boomerang* pBoomerang;

class Dagger;
typedef Dagger* pDagger;

class Firebomb;
typedef Firebomb* pFirebomb;

class Stopwatch;
typedef Stopwatch* pStopwatch;

#pragma endregion

#pragma region Pickup
#pragma region Bonus

class Crown;
typedef Crown* pCrown;

class Moai;
typedef Moai* pMoai;

class TreasureChest;
typedef TreasureChest* pTreasureChest;

class MoneyBag100;
typedef MoneyBag100* pMoneyBag100;

class MoneyBag400;
typedef MoneyBag400* pMoneyBag400;

class MoneyBag700;
typedef MoneyBag700* pMoneyBag700;

class MoneyBag1000;
typedef MoneyBag1000* pMoneyBag1000;


#pragma endregion
#pragma region Item

class Cross;
typedef Cross* pCross;

class LargeHeart;
typedef LargeHeart* pLargeHeart;

class SmallHeart;
typedef SmallHeart* pSmallHeart;

class MagicCrystal;
typedef MagicCrystal* pMagicCrystal;

class OneUp;
typedef OneUp* pOneUp;

class PorkChop;
typedef PorkChop* pPorkChop;

class Potion;
typedef Potion* pPotion;

#pragma endregion
#pragma region Weapon

class AxeItem;
typedef AxeItem* pAxeItem;

class BoomerangItem;
typedef BoomerangItem* pBoomerangItem;

class DaggerItem;
typedef DaggerItem* pDaggerItem;

class FirebombItem;
typedef FirebombItem* pFirebombItem;

class StopwatchItem;
typedef StopwatchItem* pStopwatchItem;

class MorningStar;
typedef MorningStar* pMorningStar;

class DoubleShot;
typedef DoubleShot* pDoubleShot;

class TripleShot;
typedef TripleShot* pTripleShot;

#pragma endregion
#pragma endregion

#pragma region Prop

class BreakableBrick;
typedef BreakableBrick* pBreakableBrick;

class Candle;
typedef Candle* pCandle;

class DeadZone;
typedef DeadZone* pDeadZone;

class Door;
typedef Door* pDoor;

class MovingPlatform;
typedef MovingPlatform* pMovingPlatform;

class Platform;
typedef Platform* pPlatform;

class Stair;
typedef Stair* pStair;

class StairEnd;
typedef StairEnd* pStairEnd;

class Tourch;
typedef Tourch* pTourch;

#pragma endregion

#pragma region Background

class Stage1_BG;
typedef Stage1_BG* pStage1_BG;

class Stage2A_BG;
typedef Stage2A_BG* pStage2A_BG;

class Stage2B_BG;
typedef Stage2B_BG* pStage2B_BG;

class Stage3A_BG;
typedef Stage3A_BG* pStage3A_BG;

class Stage3B_BG;
typedef Stage3B_BG* pStage3B_BG;

class Stage4_BG;
typedef Stage4_BG* pStage4_BG;

#pragma endregion

#pragma region Enemy

class BlackKnight;
typedef BlackKnight* pBlackKnight;

class BlackKnightTrigger;
typedef BlackKnightTrigger* pBlackKnightTrigger;

class Ghost;
typedef Ghost* pGhost;

class GhostSpawnZone;
typedef GhostSpawnZone* pGhostSpawnZone;

class GhostTrigger;
typedef GhostTrigger* pGhostTrigger;

class Hunchback;
typedef Hunchback* pHunchback;

class HunchbackTrigger;
typedef HunchbackTrigger* pHunchbackTrigger;

class PhantomBat;
typedef PhantomBat* pPhantomBat;

class PhantomBatTrigger;
typedef PhantomBatTrigger* pPhantomBatTrigger;

class Fireball;
typedef Fireball* pFireball;

class Raven;
typedef Raven* pRaven;

class RavenTrigger;
typedef RavenTrigger* pRavenTrigger;

class Skeleton;
typedef Skeleton* pSkeleton;

class SkeletonBone;
typedef SkeletonBone* pSkeletonBone;

class SkeletonTrigger;
typedef SkeletonTrigger* pSkeletonTrigger;

class VampireBat;
typedef VampireBat* pVampireBat;

class VampireBatSpawnZone;
typedef VampireBatSpawnZone* pVampireBatSpawnZone;

class VampireBatTrigger;
typedef VampireBatTrigger* pVampireBatTrigger;

class Zombie;
typedef Zombie* pZombie;

class ZombieSpawnZone;
typedef ZombieSpawnZone* pZombieSpawnZone;

#pragma endregion

#pragma region Effects

class HitEffect;
typedef HitEffect* pHitEffect;

class Death1Effect;
typedef Death1Effect* pDeath1Effect;

class Death2Effect;
typedef Death2Effect* pDeath2Effect;

class Death3Effect;
typedef Death3Effect* pDeath3Effect;

class BrokenBrickEffect;
typedef BrokenBrickEffect* pBrokenBrickEffect;

class Text100Effect;
typedef Text100Effect* pText100Effect;

class Text400Effect;
typedef Text400Effect* pText400Effect;

class Text700Effect;
typedef Text700Effect* pText700Effect;

class Text1000Effect;
typedef Text1000Effect* pText1000Effect;

class Text2000Effect;
typedef Text2000Effect* pText2000Effect;

class Text4000Effect;
typedef Text4000Effect* pText4000Effect;

#pragma endregion

#pragma endregion

#pragma endregion

#endif // !__CASTLEVANIA_INCLUDE_H__