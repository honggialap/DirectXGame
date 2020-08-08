#pragma once
#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "../../Include.h"
#include "Component.h"
#include "../GameObject.h"
#include "Sprite.h"

struct AnimationFrame
{
	string spriteID;
	float frameTime;

	AnimationFrame(string spriteID, float frameTime)
	{
		this->spriteID = spriteID;
		this->frameTime = frameTime;
	}
};

struct Animation
{
	vector<pAnimationFrame> animationFrames;
	float animationTime;
};

class Animator : public Component
{
private:
	pSpriteRenderer spriteRenderer;

	unordered_map<string, pAnimation> animations;
	pAnimation animation;
	float animationTime;

	int currentFrame;
	float elapsedTime;

	bool play;
	bool loop;

public:
	Animator(pGameObject gameObject);
	~Animator();

	void AddAnimation(string animationID);
	void AddAnimationFrame(string animationID, string spriteID, float frameTime);

	void Play(string animationID, bool loop = false);
	void Pause() { play = false; }
	pAnimation Get(string animationID);

	void Update(float elapsedMs);
	void Render();
};

#endif // !__ANIMATION_H__
