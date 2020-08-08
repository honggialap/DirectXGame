#include "Camera.h"

Camera::Camera(pScene scene)
{
	this->scene = scene;
	this->viewport = nullptr;
}

Camera::~Camera()
{
	viewport = nullptr;
	scene = nullptr;
}

void Camera::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Camera::GetPosition(float& x, float& y)
{
	x = this->x;
	y = this->y;
}

void Camera::Translate(float x, float y)
{
	this->x += x;
	this->y += y;
}
