#pragma once
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "../Include.h"
#include "View/Player.h"

class Camera
{
private:
	pScene scene;
	
public:
	float x, y;
	pViewport viewport;

	Camera(pScene scene);
	~Camera();

	void SetPosition(float x, float y);
	void GetPosition(float& x, float& y);
	void Translate(float x, float y);

	void AttachViewport(pViewport viewport) { this->viewport = viewport; }
	void DettachViewport() { viewport = nullptr; }
};
#endif // !__CAMERA_H__