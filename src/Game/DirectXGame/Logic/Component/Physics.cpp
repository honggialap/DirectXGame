#include "Physics.h"

Physics::Physics(pGameObject gameObject) : Component::Component(gameObject)
{
	spriteRenderer = gameObject->GetSpriteRenderer();
}

Physics::~Physics()
{
	spriteRenderer = nullptr;
}

void Physics::Update(float elapsedMs)
{
	if (enable)
	{
		//initial motion
		dt = elapsedMs;
		vy += gravity * dt;
		dx = vx * dt;
		dy = vy * dt;

		//overlapping
		Overlapping();

		//sweptAABB
		PotentialCollisions();

		//final motion
		gameObject->x += dx;
		gameObject->y += dy;

		//


		if (collisions.size() != 0)
		{
			float min_tx, min_ty, nx, ny;
			float rdx = 0;
			float rdy = 0;

			// TODO: This is a very ugly designed function!!!!
			FilterCollision(min_tx, min_ty, nx, ny, rdx, rdy);

			// how to push back Mario if collides with a moving objects, what if Mario is pushed this way into another object?
			//if (rdx != 0 && rdx!=dx)
			//	x += nx*abs(rdx); 

			// block every object first!
			gameObject->x += min_tx * dx + nx * 0.4f;
			gameObject->y += min_ty * dy + ny * 0.4f;

			if (nx != 0) vx = 0;
			if (ny != 0) vy = 0;
		}

		gameObject->x += dx;
		gameObject->y += dy;
	}
}

void Physics::RenderBoundingBox()
{
	if (enable)
	{
		auto bbox = spriteRenderer->Get("bbox");
		bbox->offset.x = offsetX;
		bbox->offset.y = offsetY;
		bbox->sourceRect.right = width -1;
		bbox->sourceRect.bottom = height -1;
		bbox->center.x = width/2;
		bbox->center.y = height/2;
		spriteRenderer->Render("bbox");
	}
}

void Physics::SetCollider(float width, float height, float offsetX, float offsetY)
{
	this->width = width;
	this->height = height;
	this->offsetX = offsetX;
	this->offsetY = offsetY;
}

void Physics::GetCollider(float& left, float& top, float& right, float& bottom)
{
	left = gameObject->x + offsetX - width / 2;
	top = gameObject->y + offsetY + height / 2;
	right = gameObject->x + offsetX + width / 2;
	bottom = gameObject->y + offsetY - height / 2;
}

void Physics::Overlapping()
{
	for (int i = 0; i < collidables.size(); i++)
	{
		pCollision collision = nullptr;

		float l1, t1, r1, b1;
		GetCollider(l1, t1, r1, b1);

		float l2, t2, r2, b2;
		collidables[i]->GetPhysics()->GetCollider(l2, t2, r2, b2);

		bool isOverlapping;
		if ((l1 <= l2 && r2 <= r1) && (t1 >= t2 && b2 >= b1))
			isOverlapping = true;
		else if ((l2 <= l1 && r1 <= r2) && (t2 >= t1 && b1 >= b2))
			isOverlapping = true;
		else
			isOverlapping = false;

		if (isOverlapping)
		{
			float nx, ny;
			if ((l1 <= l2 && r2 <= r1) || (l2 <= l1 && r1 <= r2))
				nx = 0;
			else if (l1 < l2 && r1 < r2) nx = 1;
			else if (l2 < l1 && r2 < r1) nx = -1;

			if ((b1 <= b2 && t2 <= t1) || (b2 <= b1 && t1 <= t2))
				ny = 0;
			else if (b1 < b2 && t1 < t2) ny = 1;
			else if (b2 < b1 && t2 < t1) ny = -1;

			auto collision = new Collision(0, nx, ny, 0, 0, collidables[i]);
			result.push_back(collision);
		}
	}
}

void Physics::SweptAABB(
	float ml, float mt, float mr, float mb,
	float dx, float dy,
	float sl, float st, float sr, float sb,
	float& t, float& nx, float& ny)
{
	float dx_entry, dx_exit, tx_entry, tx_exit;
	float dy_entry, dy_exit, ty_entry, ty_exit;

	float t_entry;
	float t_exit;

	t = -1.0f;			// no collision
	nx = ny = 0;

	//
	// Broad-phase test 
	//

	float bl = dx > 0 ? ml : ml + dx;
	float bt = dy > 0 ? mt : mt + dy;
	float br = dx > 0 ? mr + dx : mr;
	float bb = dy > 0 ? mb + dy : mb;

	if (br < sl || bl > sr || bb < st || bt > sb) return;

	if (dx == 0 && dy == 0) return;		// moving object is not moving > obvious no collision

	if (dx > 0)
	{
		dx_entry = sl - mr;
		dx_exit = sr - ml;
	}
	else if (dx < 0)
	{
		dx_entry = sr - ml;
		dx_exit = sl - mr;
	}

	if (dy > 0)
	{
		dy_entry = st - mb;
		dy_exit = sb - mt;
	}
	else if (dy < 0)
	{
		dy_entry = sb - mt;
		dy_exit = st - mb;
	}


	if (dx == 0)
	{
		tx_entry = -999999.0f;
		tx_exit = 999999.0f;
	}
	else
	{
		tx_entry = dx_entry / dx;
		tx_exit = dx_exit / dx;
	}

	if (dy == 0)
	{
		ty_entry = -99999.0f;
		ty_exit = 99999.0f;
	}
	else
	{
		ty_entry = dy_entry / dy;
		ty_exit = dy_exit / dy;
	}


	if ((tx_entry < 0.0f && ty_entry < 0.0f) || tx_entry > 1.0f || ty_entry > 1.0f) return;

	t_entry = max(tx_entry, ty_entry);
	t_exit = min(tx_exit, ty_exit);

	if (t_entry > t_exit) return;

	t = t_entry;

	if (tx_entry > ty_entry)
	{
		ny = 0.0f;
		dx > 0 ? nx = -1.0f : nx = 1.0f;
	}
	else
	{
		nx = 0.0f;
		dy > 0 ? ny = -1.0f : ny = 1.0f;
	}
}

pCollision Physics::SweptAABBEx(pGameObject gameObject)
{
	float sl, st, sr, sb;		// static object bbox
	float svx, svy;
	this->gameObject->GetPhysics()->GetCollider(sl, st, sr, sb);
	this->gameObject->GetPhysics()->GetVelocity(svx, svy);

	float ml, mt, mr, mb;		// moving object bbox
	GetCollider(ml, mt, mr, mb);

	// deal with moving object: m speed = original m speed - collide object speed
	float sdx = svx * dt;
	float sdy = svy * dt;

	// (rdx, rdy) is RELATIVE movement distance/velocity 
	float rdx = this->dx - sdx;
	float rdy = this->dy - sdy;

	float t, nx, ny;
	SweptAABB(
		ml, mt, mr, mb,
		rdx, rdy,
		sl, st, sr, sb,
		t, nx, ny);

	auto collision = new Collision(t, nx, ny, rdx, rdy, gameObject);
	return collision;
}

void Physics::PotentialCollisions()
{
	for (int i = 0; i < collidables.size(); i++)
	{
		pCollision collision = nullptr;
		collision = SweptAABBEx(collidables[i]);

		if (collision->t > 0 && collision->t <= 1.0f)
			collisions.push_back(collision);
		else delete collision;
	}

	std::sort(collisions.begin(), collisions.end(), Collision::Compare);

	if (collisions.size() != 0)
	{
		float min_tx, min_ty, nx, ny;
		float rdx = 0;
		float rdy = 0;

		// TODO: This is a very ugly designed function!!!!
		FilterCollision(min_tx, min_ty, nx, ny, rdx, rdy);
	}
}

void Physics::FilterCollision(
	float& min_tx, float& min_ty,
	float& nx, float& ny,
	float& rdx, float& rdy)
{
	min_tx = 1.0f;
	min_ty = 1.0f;
	int min_ix = -1;
	int min_iy = -1;

	nx = 0.0f;
	ny = 0.0f;

	for (UINT i = 0; i < collisions.size(); i++)
	{
		auto collision = collisions[i];

		if (collision->t < min_tx && collision->nx != 0) {
			min_tx = collision->t; nx = collision->nx; min_ix = i; rdx = collision->dx;
		}

		if (collision->t < min_ty && collision->ny != 0) {
			min_ty = collision->t; ny = collision->ny; min_iy = i; rdy = collision->dy;
		}
	}

	if (min_ix >= 0) result.push_back(collisions[min_ix]);
	if (min_iy >= 0) result.push_back(collisions[min_iy]);
}

void Physics::Response()
{
	for (int i = 0; i < result.size(); i++)
	{
		gameObject->Collided(result[i]);

		switch (result[i]->response)
		{
		case Collision::None:
			break;

		case Collision::Block:
			break;

		case Collision::Stick:
			break;
		}
	}

	for (int i = 0; i < collisions.size(); i++)
		delete collisions[i];
	collisions.clear();

	for (int i = 0; i < result.size(); i++)
		delete result[i];
	result.clear();
}

void Physics::SetVelocity(float vx, float vy)
{
	this->vx = vx;
	this->vy = vy;
}

void Physics::AddVelocity(float vx, float vy)
{
	this->vx += vx;
	this->vy += vy;
}

void Physics::GetVelocity(float& vx, float& vy)
{
	vx = this->vx;
	vy = this->vy;
}
