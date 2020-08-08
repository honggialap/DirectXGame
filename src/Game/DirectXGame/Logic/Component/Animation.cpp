#include "Animation.h"

Animator::Animator(pGameObject gameObject) : Component::Component(gameObject)
{
	type = Component::Type::Animator;
	spriteRenderer = gameObject->GetSpriteRenderer();
	animation = nullptr;
	animationTime = 0;
	currentFrame = 0;
	elapsedTime = 0;
	play = false;
	loop = false;
}

Animator::~Animator()
{
	for (auto animation : animations)
	{
		for (auto animationFrame : animation.second->animationFrames)
		{
			delete animationFrame;
			animationFrame = nullptr;
		}
		animation.second->animationFrames.clear();

		delete animation.second;
		animation.second = nullptr;
	}
	animations.clear();

	animation = nullptr;
	spriteRenderer = nullptr;
}

void Animator::AddAnimation(string animationID)
{
	animations[animationID] = new Animation();
	animations[animationID]->animationTime = 0;
}

void Animator::AddAnimationFrame(string animationID, string spriteID, float frameTime)
{
	auto animation = new AnimationFrame(spriteID, frameTime);
	animations[animationID]->animationFrames.push_back(animation);
	animations[animationID]->animationTime += frameTime;
}

void Animator::Play(string animationID, bool loop)
{
	animation = animations[animationID];
	animationTime = 0;
	currentFrame = 0;
	elapsedTime = 0;
	this->play = true;
	this->loop = loop;
}

pAnimation Animator::Get(string animationID)
{
	return animations[animationID];
}

void Animator::Update(float elapsedMs)
{
	if (play)
	{
		if (animation->animationFrames.size() > 1)
		{
			animationTime += elapsedMs;
			if (animationTime <= animation->animationTime)
			{
				elapsedTime += elapsedMs;
				while (elapsedTime - animation->animationFrames.at(currentFrame)->frameTime >= 0)
				{
					elapsedTime -= animation->animationFrames.at(currentFrame)->frameTime;
					if (currentFrame < animation->animationFrames.size() - 1)
						currentFrame++;
					else
					{
						currentFrame = 0;
						if (!loop)
						{
							play = false;
							elapsedTime = 0;
						}
					}
				}
			}
			else animationTime = 0;
		}
		else currentFrame = 0;
	}	
}

void Animator::Render()
{
	spriteRenderer->Render(
		animation->animationFrames.at(currentFrame)->spriteID
	);
}
