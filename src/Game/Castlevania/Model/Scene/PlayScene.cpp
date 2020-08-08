#include "PlayScene.h"

PlayScene::PlayScene(pGame game) : Scene::Scene(game)
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Load()
{
	Scene::Load();
}

void PlayScene::Unload()
{
	Scene::Unload();
}

pGameObject PlayScene::Spawn(string prefabID, float positionX, float positionY)
{
	//// Sandbox for testing feature
	if (prefabID == "demo")
	{
		auto gameObject = new Demo(this);
		dictionary[gameObjectID] = gameObject;
		gameObject->id = gameObjectID;
		gameObject->Load();
		gameObject->SetPosition(positionX, positionY);
		gameObject->Activate();
		gameObject->Show();
	}

	//// Title
	else if (prefabID == "title")
	{
		auto gameObject = new Title(this);
		dictionary[gameObjectID] = gameObject;
		gameObject->id = gameObjectID;
		gameObject->Load();
		gameObject->SetPosition(positionX, positionY);
		gameObject->Activate();
		gameObject->Show();
	}
	else if (prefabID == "title_Bat")
	{
		auto gameObject = new Title_Bat(this);
		dictionary[gameObjectID] = gameObject;
		gameObject->id = gameObjectID;
		gameObject->Load();
		gameObject->SetPosition(positionX, positionY);
		gameObject->Activate();
		gameObject->Show();
	}
	else if (prefabID == "title_BG")
	{
		auto gameObject = new Title_BG(this);
		dictionary[gameObjectID] = gameObject;
		gameObject->id = gameObjectID;
		gameObject->Load();
		gameObject->SetPosition(positionX, positionY);
		gameObject->Activate();
		gameObject->Show();
	}
	else if (prefabID == "title_Label")
	{
		auto gameObject = new Title_Label(this);
		dictionary[gameObjectID] = gameObject;
		gameObject->id = gameObjectID;
		gameObject->Load();
		gameObject->SetPosition(positionX, positionY);
		gameObject->Activate();
		gameObject->Show();
	}

	//// Intro
	else if (prefabID == "intro")
	{
		auto gameObject = new Intro(this);
		dictionary[gameObjectID] = gameObject;
		gameObject->id = gameObjectID;
		gameObject->Load();
		gameObject->SetPosition(positionX, positionY);
		gameObject->Activate();
		gameObject->Show();
	}
	else if (prefabID == "intro_Bat1")
	{
		auto gameObject = new Intro_Bat1(this);
		dictionary[gameObjectID] = gameObject;
		gameObject->id = gameObjectID;
		gameObject->Load();
		gameObject->SetPosition(positionX, positionY);
		gameObject->Activate();
		gameObject->Show();
	}
	else if (prefabID == "intro_Bat2")
	{
		auto gameObject = new Intro_Bat2(this);
		dictionary[gameObjectID] = gameObject;
		gameObject->id = gameObjectID;
		gameObject->Load();
		gameObject->SetPosition(positionX, positionY);
		gameObject->Activate();
		gameObject->Show();
	}
	else if (prefabID == "intro_BG")
	{
		auto gameObject = new Intro_BG(this);
		dictionary[gameObjectID] = gameObject;
		gameObject->id = gameObjectID;
		gameObject->Load();
		gameObject->SetPosition(positionX, positionY);
		gameObject->Activate();
		gameObject->Show();
	}
	else if (prefabID == "intro_Cloud")
	{
		auto gameObject = new Intro_Cloud(this);
		dictionary[gameObjectID] = gameObject;
		gameObject->id = gameObjectID;
		gameObject->Load();
		gameObject->SetPosition(positionX, positionY);
		gameObject->Activate();
		gameObject->Show();
	}
	else if (prefabID == "intro_Simon")
	{
		auto gameObject = new Intro_Simon(this);
		dictionary[gameObjectID] = gameObject;
		gameObject->id = gameObjectID;
		gameObject->Load();
		gameObject->SetPosition(positionX, positionY);
		gameObject->Activate();
		gameObject->Show();
	}

	//// Stage
	else if (prefabID == "gameMaster")
	{
		auto gameObject = new GameMaster(this);
		dictionary[gameObjectID] = gameObject;
		gameObject->id = gameObjectID;
		gameObject->Load();
		gameObject->SetPosition(positionX, positionY);
		gameObject->Activate();
		gameObject->Show();
	}
	else if (prefabID == "hud")
	{
		auto gameObject = new HUD(this);
		dictionary[gameObjectID] = gameObject;
		gameObject->id = gameObjectID;
		gameObject->Load();
		gameObject->SetPosition(positionX, positionY);
		gameObject->Activate();
		gameObject->Show();
	}

	// Map
	else if (prefabID == "stage1")
	{
	auto gameObject = new Stage1(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "stage2A")
	{
	auto gameObject = new Stage2A(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "stage2B")
	{
	auto gameObject = new Stage2B(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "stage3A")
	{
	auto gameObject = new Stage3A(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "stage3B")
	{
	auto gameObject = new Stage3B(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "stage4")
	{
	auto gameObject = new Stage4(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}

	// Background
	else if (prefabID == "stage1_BG")
	{
		auto gameObject = new Stage1_BG(this);
		dictionary[gameObjectID] = gameObject;
		gameObject->id = gameObjectID;
		gameObject->Load();
		gameObject->SetPosition(positionX, positionY);
		gameObject->Activate();
		gameObject->Show();
	}
	else if (prefabID == "stage2A_BG")
	{
	auto gameObject = new Stage2A_BG(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "stage2B_BG")
	{
	auto gameObject = new Stage2B_BG(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "stage3A_BG")
	{
	auto gameObject = new Stage3A_BG(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "stage3B_BG")
	{
	auto gameObject = new Stage3B_BG(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "stage4_BG")
	{
	auto gameObject = new Stage4_BG(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}

	// Effects
	else if (prefabID == "brokenBrickEffect")
	{
	auto gameObject = new BrokenBrickEffect(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "death1Effect")
	{
	auto gameObject = new Death1Effect(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "death2Effect")
	{
	auto gameObject = new Death2Effect(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "death3Effect")
	{
	auto gameObject = new Death3Effect(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "hitEffect")
	{
	auto gameObject = new HitEffect(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "text100Effect")
	{
	auto gameObject = new Text100Effect(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "text400Effect")
	{
	auto gameObject = new Text400Effect(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "text700Effect")
	{
	auto gameObject = new Text700Effect(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "text1000Effect")
	{
	auto gameObject = new Text1000Effect(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "text2000Effect")
	{
	auto gameObject = new Text2000Effect(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "text4000Effect")
	{
	auto gameObject = new Text4000Effect(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}

	// Enemy
	else if (prefabID == "blackKnight")
	{
	auto gameObject = new BlackKnight(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "blackKnightTrigger")
	{
	auto gameObject = new BlackKnightTrigger(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "ghost")
	{
	auto gameObject = new Ghost(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "ghostSpawnZone")
	{
	auto gameObject = new GhostSpawnZone(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "ghostTrigger")
	{
	auto gameObject = new GhostTrigger(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "hunchback")
	{
	auto gameObject = new Hunchback(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "hunchbackTrigger")
	{
	auto gameObject = new HunchbackTrigger(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "fireball")
	{
	auto gameObject = new Fireball(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "phantomBat")
	{
	auto gameObject = new PhantomBat(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "phantomBatTrigger")
	{
	auto gameObject = new PhantomBatTrigger(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "raven")
	{
	auto gameObject = new Raven(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "ravenTrigger")
	{
	auto gameObject = new RavenTrigger(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "skeleton")
	{
	auto gameObject = new Skeleton(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "skeletonBone")
	{
	auto gameObject = new SkeletonBone(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "skeletonTrigger")
	{
	auto gameObject = new SkeletonTrigger(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "ghost")
	{
	auto gameObject = new Ghost(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "ghostSpawnZone")
	{
	auto gameObject = new GhostSpawnZone(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "ghostTrigger")
	{
	auto gameObject = new GhostTrigger(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}

	// Pickup - Bonus
	else if (prefabID == "crown")
	{
	auto gameObject = new Crown(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "moai")
	{
	auto gameObject = new Moai(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "moneyBag100")
	{
	auto gameObject = new MoneyBag100(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "moneyBag400")
	{
	auto gameObject = new MoneyBag400(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "moneyBag700")
	{
	auto gameObject = new MoneyBag700(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "moneyBag1000")
	{
	auto gameObject = new MoneyBag1000(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "treasureChest")
	{
	auto gameObject = new TreasureChest(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}

	// Pickup - Item
	else if (prefabID == "cross")
	{
	auto gameObject = new Cross(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "extraLife")
	{
	auto gameObject = new ExtraLife(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "largeHeart")
	{
	auto gameObject = new LargeHeart(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "magicCrystal")
	{
	auto gameObject = new MagicCrystal(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "porkChop")
	{
	auto gameObject = new PorkChop(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "potion")
	{
	auto gameObject = new Potion(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "smallHeart")
	{
	auto gameObject = new SmallHeart(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}

	// Pickup - Weapon
	else if (prefabID == "axeItem")
	{
	auto gameObject = new AxeItem(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "boomerangItem")
	{
	auto gameObject = new BoomerangItem(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "daggerItem")
	{
	auto gameObject = new DaggerItem(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "doubleShot")
	{
	auto gameObject = new DoubleShot(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "firebombItem")
	{
	auto gameObject = new FirebombItem(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "morningStar")
	{
	auto gameObject = new MorningStar(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "stopwatchItem")
	{
	auto gameObject = new StopwatchItem(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "tripleShot")
	{
	auto gameObject = new TripleShot(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}

	// Prop
	else if (prefabID == "breakableBrick")
	{
	auto gameObject = new BreakableBrick(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "candle")
	{
	auto gameObject = new Candle(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "deadZone")
	{
	auto gameObject = new DeadZone(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "breakableBrick")
	{
	auto gameObject = new BreakableBrick(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "door")
	{
	auto gameObject = new Door(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "movingPlatform")
	{
	auto gameObject = new MovingPlatform(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "platform")
	{
	auto gameObject = new Platform(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "stair")
	{
	auto gameObject = new Stair(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "stairEnd")
	{
	auto gameObject = new StairEnd(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "tourch")
	{
	auto gameObject = new Tourch(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}

	// Simon
	else if (prefabID == "axe")
	{
	auto gameObject = new Axe(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "boomerang")
	{
	auto gameObject = new Boomerang(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "dagger")
	{
	auto gameObject = new Dagger(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "firebomb")
	{
	auto gameObject = new Firebomb(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "simon")
	{
	auto gameObject = new Simon(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "stopwatch")
	{
	auto gameObject = new Stopwatch(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}
	else if (prefabID == "vampireKiller")
	{
	auto gameObject = new VampireKiller(this);
	dictionary[gameObjectID] = gameObject;
	gameObject->id = gameObjectID;
	gameObject->Load();
	gameObject->SetPosition(positionX, positionY);
	gameObject->Activate();
	gameObject->Show();
	}

	return Scene::Spawn(prefabID, positionX, positionY);
}