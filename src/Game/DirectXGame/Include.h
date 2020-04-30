#pragma once
#ifndef __DIRECTXGAME_INCLUDE_H__
#define __DIRECTXGAME_INCLUDE_H__

#pragma region Forward Declaration

#pragma region Framework
class Game;
typedef Game* pGame;

class GameSettings;
typedef GameSettings* pGameSettings;

class Application;
typedef Application* pApplication;

class GameWindow;
typedef GameWindow* pGameWindow;

class Time;
typedef Time* pTime;

class GameTime;
typedef GameTime* pGameTime;

class Graphics;
typedef Graphics* pGraphics;

class GraphicsDevice;
typedef GraphicsDevice* pGraphicsDevice;

class Input;
typedef Input* pInput;

class InputDevice;
typedef InputDevice* pInputDevice;

class Resource;
typedef Resource* pResource;

class Texture;
typedef Texture* pTexture;

class Textures;
typedef Textures* pTextures;

class TextureRegion;
typedef TextureRegion* pTextureRegion;

#pragma endregion

#pragma region Logic

class Scene;
typedef Scene* pScene;

class Scenes;
typedef Scenes* pScenes;

class Prefab;
typedef Prefab* pPrefab;

class Prefabs;
typedef Prefabs* pPrefabs;

class GameObject;
typedef GameObject* pGameObject;

class GameObjects;
typedef GameObjects* pGameObjects;

class Component;
typedef Component* pComponent;

class Components;
typedef Components* pComponents;

class Transform;
typedef Transform* pTransform;

class Sprite;
typedef Sprite* pSprite;

class Sprites;
typedef Sprites* pSprites;

class SpriteAtlas;
typedef SpriteAtlas* pSpriteAtlas;

class AnimationFrame;
typedef AnimationFrame* pAnimationFrame;

class AnimationFrames;
typedef AnimationFrames* pAnimationFrames;

class Animation;
typedef Animation* pAnimation;

class Animations;
typedef Animations* pAnimations;

class AnimationSet;
typedef AnimationSet* pAnimationSet;

class AnimationSets;
typedef AnimationSets* pAnimationSets;

class Body;
typedef Body* pBody;

class Collider;
typedef Collider* pCollider;

class Colliders;
typedef Colliders* pColliders;

class CollisionEvent;
typedef CollisionEvent* pCollisionEvent;

class CollisionEvents;
typedef CollisionEvents* pCollisionEvents;

#pragma endregion

#pragma endregion

#include "Framework/Ultilities.h"
#include "Framework/Math.h"

#endif //!__DIRECTXGAME_INCLUDE_H__