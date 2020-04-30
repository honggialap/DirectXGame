#pragma once
#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "../Include.h"

enum class ComponentType
{
	Transform,
	SpriteRenderer,
	Animator,
	TilemapRenderer,
	Body,
	Collider,
	Control,
	Camera
};

class Component
{
public:
	pGameObject gameObject;

	string id;
	ComponentType componentType;

	Component();
	~Component();

	void Attach(pGameObject gameObject);
	void Detach();
};

class Components
{
public:
	pGameObject gameObject;
	unordered_map<string, pComponent> components;
	
	Components(pGameObject gameObject);
	~Components();
	
	void Add(string id, pComponent component);
	pComponent Get(string id);

	void Remove(string id);
	void Clear();
};

#endif // !__COMPONENT_H__