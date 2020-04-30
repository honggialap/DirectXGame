#include "GameObject.h"

GameObject::GameObject(pGame game, pScene scene)
{
	this->game = game;
	this->scene = scene;

	enable = false;
	components = new Components(this);
}

GameObject::~GameObject()
{
	this->scene = nullptr;
	this->game = nullptr;
}

void GameObject::Load(xml_node gameObjectNode)
{
	xml_node componentsNode = gameObjectNode.child("Components");
	for (xml_node componentNode = componentsNode.child("Component");
		componentNode;
		componentNode = componentNode.next_sibling("Component"))
	{
		string componentType = componentNode.attribute("componentType").as_string();
		if (componentType == "Transform")
		{
			xml_node transformNode = componentNode.child("Transform");
			
			pTransform transform = new Transform();
			transform->id = componentNode.attribute("id").as_string();
			transform->position = D3DXVECTOR3(
					transformNode.attribute("x").as_float(),
					transformNode.attribute("y").as_float(), 
					0.0f);
			transform->Attach(this);

			components->Add(transform->id, transform);
		}
		else if (componentType == "Sprite") 
		{

		}
		//else if (componentType == "Animation") {}
		//else if (componentType == "Body") {}
		//else if (componentType == "Collider") {}
		//else if (componentType == "Control") {}
		//else if (componentType == "Camera") {}
	}
}

//bool GameObject::CompareByUpdateOrder(const pGameObject a, const pGameObject b)
//{
//	return a->updateOrder < b->updateOrder;
//}

GameObjects::GameObjects(pGame game, pScene scene)
{
	this->game = game;
	this->scene = scene;
}

GameObjects::~GameObjects()
{
	this->game = nullptr;
	this->scene = nullptr;
}

void GameObjects::Add(pGameObject gameObject)
{
	gameObjects.push_back(gameObject);
}


pGameObject GameObjects::Get(string id)
{
	for (auto gameObject : gameObjects)
		if (gameObject->id == id) return gameObject;
	
	return nullptr;
}

void GameObjects::Remove()
{
}

void GameObjects::Clear()
{
}

//void GameObjects::SortByUpdateOrder()
//{
//	sort(gameObjects.begin(), gameObjects.end(), GameObject::CompareByUpdateOrder);
//}
