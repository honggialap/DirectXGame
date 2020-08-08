#pragma once
#ifndef __PHYSICS_H__
#define __PHYSICS_H__

#include "../../Include.h"
#include "Component.h"
#include "../GameObject.h"

struct Collision
{
	pGameObject gameObject;
	float t, nx, ny;
	float dx, dy;
	enum Response {
		None,
		Block,
		Stick
	};
	Response response;

	Collision(float t, float nx, float ny, float dx = 0, float dy = 0, pGameObject gameObject = nullptr, Response response = None)
	{
		this->t = t;
		this->nx = nx;
		this->ny = ny;
		this->dx = dx;
		this->dy = dy;
		this->gameObject = gameObject;
		this->response = response;
	}

	static bool Compare(pCollision a, pCollision b)
	{
		return a->t < b->t;
	}
};

class Physics : public Component
{
private:
	pSpriteRenderer spriteRenderer;

public:
	bool enable;

	float width, height;
	float offsetX, offsetY;

	float vx, vy;
	float gravity;

	float dt, dx, dy;

	vector<pCollision> collisions;
	vector<pCollision> result;
	vector<pGameObject> collidables;

	Physics(pGameObject gameObject);
	~Physics();

	void SetGravity(float gravity) { this->gravity = gravity; }

	void SetVelocity(float vx, float vy);
	void AddVelocity(float vx, float vy);
	void GetVelocity(float& vx, float& vy);

	void Enable() { enable = true; }
	void Disable() { enable = false; }
	void SetCollider(float width, float height, float offsetX, float offsetY);
	void GetCollider(float& left, float& top, float& right, float& bottom);

	void Overlapping();
	void PotentialCollisions();
	pCollision SweptAABBEx(pGameObject gameObject);
	void SweptAABB(
		float ml, float mt, float mr, float mb,
		float dx, float dy,
		float sl, float st, float sr, float sb,
		float& t, float& nx, float& ny);
	void FilterCollision(
		float& min_tx, float& min_ty,
		float& nx, float& ny,
		float& rdx, float& rdy);
	void Response();

	void Update(float elapsedMs);
	void RenderBoundingBox();
};

#endif // !__PHYSICS_H__
