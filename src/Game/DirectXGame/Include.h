#pragma once
#ifndef __DIRECTXGAME_INCLUDE_H__
#define __DIRECTXGAME_INCLUDE_H__

#pragma region Include

// Standard Library
#include <algorithm>
#include <iostream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <cmath>

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <signal.h>
#include <string.h>

// API
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dx9math.h>
#include <dinput.h>
#include "Library/pugixml/pugixml.hpp"
//#include <winsock2.h>
//#include <WS2tcpip.h>

using namespace std;
using namespace pugi;
using namespace std::chrono;

#pragma endregion

#pragma region Forward Declaration

class Game;
typedef Game* pGame;
struct GameSettings;
typedef GameSettings* pGameSettings;

class Application;
typedef Application* pApplication;
struct GameWindow;
typedef GameWindow* pGameWindow;

class Time;
typedef Time* pTime;

class Graphics;
typedef Graphics* pGraphics;
struct GraphicsDevice;
typedef GraphicsDevice* pGraphicsDevice;

class Input;
typedef Input* pInput;
struct InputDevice;
typedef InputDevice* pInputDevice;
class KeyHandler;
typedef KeyHandler* pKeyHandler;

class Audio;
typedef Audio* pAudio;
struct AudioDevice;
typedef AudioDevice* pAudioDevice;

class Networks;
typedef Networks* pNetworks;
struct NetworksDevice;
typedef NetworksDevice* pNetworksDevice;

class Resource;
typedef Resource* pResource;
struct Texture;
typedef Texture* pTexture;
class Textures;
typedef Textures* pTextures;
struct Font;
typedef Font* pFont;
class Fonts;
typedef Fonts* pFonts;
struct SoundClip;
typedef SoundClip* pSoundClip;
class SoundBank;
typedef SoundBank* pSoundBank;

class Scene;
typedef Scene* pScene;

class GameObject;
typedef GameObject* pGameObject;

class Component;
typedef Component* pComponent;

class SpriteRenderer;
typedef SpriteRenderer* pSpriteRenderer;
struct Sprite;
typedef Sprite* pSprite;

class Animator;
typedef Animator* pAnimator;
struct Animation;
typedef Animation* pAnimation;
struct AnimationFrame;
typedef AnimationFrame* pAnimationFrame;

class Tilemap;
typedef Tilemap* pTilemap;

class TextRenderer;
typedef TextRenderer* pTextRenderer;
struct Text;
typedef Text* pText;

class Physics;
typedef Physics* pPhysics;
struct Collision;
typedef Collision* pCollision;

class SoundSource;
typedef SoundSource* pSoundSource;
struct Sound;
typedef Sound* pSound;

class Camera;
typedef Camera* pCamera;

class Player;
typedef Player* pPlayer;

class LocalPlayer;
typedef LocalPlayer* pLocalPlayer;
class Controller;
typedef Controller* pController;
class Viewport;
typedef Viewport* pViewport;

#pragma endregion

#pragma region Ultilities

const double pi = 3.14159;

void DebugOut(const wchar_t* fmt, ...);
wstring ToWSTR(string st);
LPCWSTR ToLPCWSTR(string st);

#pragma endregion

#endif //!__DIRECTXGAME_INCLUDE_H__