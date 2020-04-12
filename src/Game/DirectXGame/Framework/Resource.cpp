#include "Resource.h"

Resource::Resource(pGraphics graphics, pAudio audio)
{
	this->graphics = graphics;
	this->audio = audio;
}

Resource::~Resource()
{
	this->graphics = nullptr;
	this->audio = nullptr;
}

//bool Resource::Load()
//{
//	return false;
//}
//
//template<class T> T Resource::Get()
//{
//	return T();
//}