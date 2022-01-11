#include "Collision.h"

CCollider::CCollider(pGameObject gameObject)
{
}

void CCollider::SweptAABB(float ml, float mt, float mr, float mb, float dx, float dy, float sl, float st, float sr, float sb, float& t, float& nx, float& ny)
{
}

pCollision CCollider::Overlap(pGameObject collidables)
{
	return pCollision();
}

void CCollider::ScanOverlap(std::vector<pGameObject>* collidables)
{
}

pCollision CCollider::SweptAABB(float elapsedMs, pGameObject collidable)
{
	return pCollision();
}

void CCollider::ScanSweptAABB(float elapsedMs, pGameObject collidable)
{
}

void CCollider::Filter(pCollision& colX, pCollision& colY, int filterBlock, int filterX, int filterY)
{
}

void CCollider::Process(float elapsedMs, std::vector<pGameObject>* collidables)
{
}
