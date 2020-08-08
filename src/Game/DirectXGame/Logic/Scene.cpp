#include "Scene.h"

#pragma region Scene

Scene::Scene(pGame game)
{
	this->game = game;
}

Scene::~Scene()
{
	this->game = nullptr;
}

void Scene::SwitchScene(string sceneID)
{
	done = true;
	nextScene = sceneID;
}

void Scene::Load()
{
	done = false;
	loading = true;
	nextScene = "";

	xml_document sceneDoc;
	sceneDoc.load_file(source.c_str());

	xml_node sceneNode = sceneDoc.child("Scene");
	mode = Scene::Mode(sceneNode.attribute("mode").as_int());

	int playerNo = 0;
	for (xml_node playerNode = sceneNode.child("Player");
		playerNode;
		playerNode = playerNode.next_sibling("Player"), playerNo++)
	{
		if (Player::Type(playerNode.attribute("type").as_int()) == Player::Type::Local)
		{
			auto player = new LocalPlayer(this);

			game->input->SetKeyHandler(player->controller);
			for (xml_node keyBindNode = playerNode.child("Controller").child("Keybind");
				keyBindNode;
				keyBindNode = keyBindNode.next_sibling("Keybind"))
			{
				Controller::Button button = static_cast<Controller::Button>(keyBindNode.attribute("button").as_int());
				player->controller->keybinds[keyBindNode.attribute("keyCode").as_int()] = button;
				player->controller->buttonState[button] = Controller::ButtonState::Released;
				player->controller->previousButtonState[button] = Controller::ButtonState::Released;
			}

			xml_node viewportNode = playerNode.child("Viewport");
			player->viewport->SetBound(
				viewportNode.attribute("left").as_int(),
				viewportNode.attribute("top").as_int(),
				viewportNode.attribute("right").as_int(),
				viewportNode.attribute("bottom").as_int());

			players[playerNo] = player;
		}
	}

	int cameraNo = 0;
	for (xml_node cameraNode = sceneNode.child("Camera");
		cameraNode;
		cameraNode = cameraNode.next_sibling("Camera"), cameraNo++)
	{
		auto camera = new Camera(this);
		camera->SetPosition(
			cameraNode.attribute("positionX").as_float(),
			cameraNode.attribute("positionY").as_float());

		camera->AttachViewport(
			dynamic_cast<pLocalPlayer>(
				players[
					cameraNode.attribute("viewport").as_int()
				])->viewport);

		cameras[cameraNo] = camera;
	}

	for (xml_node gameObjectNode = sceneNode.child("GameObject");
		gameObjectNode;
		gameObjectNode = gameObjectNode.next_sibling("GameObject"))
	{
		Spawn(
			gameObjectNode.attribute("prefabID").as_string(),
			gameObjectNode.attribute("positionX").as_float(),
			gameObjectNode.attribute("positionY").as_float()
		);
	}

	int gameObjectNo = 0;
	cellWidth = sceneNode.attribute("cellWidth").as_float();
	cellHeight = sceneNode.attribute("cellHeight").as_float();
	for (xml_node gameObjectNode = sceneNode.child("Grid").child("GameObject");
		gameObjectNode;
		gameObjectNode = gameObjectNode.next_sibling("GameObject"), gameObjectNo++)
	{
		AddCell(gameObjectNo,
			gameObjectNode.attribute("cellX").as_int(),
			gameObjectNode.attribute("cellY").as_int());
	}

	loading = false;
}

void Scene::Unload()
{
	// Camera
	for (auto camera : cameras)
	{
		camera.second->DettachViewport();
		delete camera.second;
	}
	cameras.clear();

	// Player
	for (auto player : players)
		delete player.second;
	players.clear();

	// GameObject
	for (auto gameObject : dictionary)
	{
		gameObject.second->Unload();
		delete gameObject.second;
	}
	dictionary.clear();
	addedObjects.clear();
	removedObjects.clear();
	updateSequence.clear();
	renderSequence.clear();

	// Grid
	for (auto cell : grid)
		cell.second.clear();
	grid.clear();
}

pGameObject Scene::Spawn(string prefabID, float positionX, float positionY)
{
	addedObjects.push_back(dictionary[gameObjectID]);
	if (!loading)
	{
		int cellX, cellY;
		CalculateCell(positionX, positionY, cellX, cellY);
		AddCell(gameObjectID, cellX, cellY);
	}
	return dictionary[gameObjectID++];
}

void Scene::Destroy(int id)
{
	dictionary[id]->expired = true;
	removedObjects.push_back(dictionary[id]);
}

void Scene::Add()
{
	if (!addedObjects.empty())
	{
		for (auto addedObject : addedObjects)
		{
			for (auto gameObject : dictionary)
				gameObject.second->SpawnedHandler(addedObject);

			updateSequence.push_back(addedObject);
			renderSequence.push_back(addedObject);
		}
		addedObjects.clear();
	}
}

void Scene::Remove()
{
	if (!removedObjects.empty())
	{
		for (auto removedObject : removedObjects)
		{
			updateSequence.erase(
				std::remove(updateSequence.begin(), updateSequence.end(), removedObject),
				updateSequence.end());

			renderSequence.erase(
				std::remove(renderSequence.begin(), renderSequence.end(), removedObject),
				renderSequence.end());

			RemoveCell(removedObject->id);

			for (auto gameObject : dictionary)
				gameObject.second->DestroyedHandler(removedObject);

			dictionary.erase(removedObject->id);

			removedObject->Unload();
			delete removedObject;

		}
		removedObjects.clear();
	}
}

void Scene::CalculateCell(int positionX, int positionY, int& cellX, int& cellY)
{
	if (positionX <= (cellWidth / 2) && positionX >= -(cellWidth / 2)) cellX = 0;
	else if (positionX > (cellWidth / 2)) cellX = (positionX + (cellWidth / 2) - 1) / cellWidth;
	else if (positionX < -(cellWidth / 2)) cellX = (positionX - (cellWidth / 2) + 1) / cellWidth;

	if (positionY <= (cellHeight / 2) && positionY >= -(cellHeight / 2)) cellY = 0;
	else if (positionY > cellHeight / 2) cellY = (positionY + (cellHeight / 2) - 1) / cellHeight;
	else if (positionY < -(cellHeight / 2)) cellY = (positionY - (cellHeight / 2) + 1) / cellHeight;
}

void Scene::AddCell(int gameObjectID, int cellX, int cellY)
{
	dictionary[gameObjectID]->cellX = cellX;
	dictionary[gameObjectID]->cellY = cellY;
	grid[make_pair(cellX, cellY)].push_back(gameObjectID);
}

void Scene::RemoveCell(int gameObjectID)
{
	vector<int>* cell = &grid[make_pair(dictionary[gameObjectID]->cellX, dictionary[gameObjectID]->cellY)];
	cell->erase(
		std::remove(cell->begin(), cell->end(), gameObjectID),
		cell->end());
}

void Scene::UpdateCell(int gameObjectID)
{
	auto go = dictionary[gameObjectID];
	int cellX, cellY;
	CalculateCell(go->x, go->y, cellX, cellY);
	if (cellX != go->cellX || cellY != go->cellY)
	{
		RemoveCell(gameObjectID);
		AddCell(gameObjectID, cellX, cellY);
	}
}

void Scene::GetLocalGroup(vector<int>* list, int cellX, int cellY)
{
	list->clear();

	// left-top
	if (grid.find(make_pair(cellX - 1, cellY + 1)) != grid.end())
		for (auto cell : grid[make_pair(cellX - 1, cellY + 1)])
			list->push_back(cell);

	// top
	if (grid.find(make_pair(cellX, cellY + 1)) != grid.end())
		for (auto cell : grid[make_pair(cellX, cellY + 1)])
			list->push_back(cell);

	// right-top
	if (grid.find(make_pair(cellX + 1, cellY + 1)) != grid.end())
		for (auto cell : grid[make_pair(cellX + 1, cellY + 1)])
			list->push_back(cell);

	// left
	if (grid.find(make_pair(cellX - 1, cellY)) != grid.end())
		for (auto cell : grid[make_pair(cellX - 1, cellY)])
			list->push_back(cell);

	// center
	for (auto cell : grid[make_pair(cellX, cellY)])
		list->push_back(cell);

	// right
	if (grid.find(make_pair(cellX + 1, cellY)) != grid.end())
		for (auto cell : grid[make_pair(cellX + 1, cellY)])
			list->push_back(cell);

	// bottom-left
	if (grid.find(make_pair(cellX - 1, cellY - 1)) != grid.end())
		for (auto cell : grid[make_pair(cellX - 1, cellY - 1)])
			list->push_back(cell);

	// bottom
	if (grid.find(make_pair(cellX, cellY - 1)) != grid.end())
		for (auto cell : grid[make_pair(cellX, cellY - 1)])
			list->push_back(cell);

	// bottom-right
	if (grid.find(make_pair(cellX + 1, cellY - 1)) != grid.end())
		for (auto cell : grid[make_pair(cellX + 1, cellY - 1)])
			list->push_back(cell);
}

void Scene::Update(float elapsedMs)
{
	Remove();
	Add();
	if (!updateSequence.empty())
	{
		for (auto gameObject : updateSequence)
			if (gameObject->enable
				&& !gameObject->expired)
			{
				gameObject->Update(elapsedMs);
				UpdateCell(gameObject->id);
			}
	}

}

void Scene::Render()
{
	if (!renderSequence.empty())
	{
		SortByRenderLayer();
		for (auto gameObject : renderSequence)
			if (gameObject->visible
				&& !gameObject->expired)
				gameObject->Render();
	}
}

void Scene::SortByRenderLayer()
{
	std::sort(renderSequence.begin(), renderSequence.end(), GameObject::LayerCompare);
}

#pragma endregion