#ifndef __SOUND_SOURCE_H__
#define __SOUND_SOURCE_H__

#include "../../Include.h"
#include "../../Framework/Resource.h"
#include "../../Framework/Content/Sound.h"
#include "Component.h"
#include "../GameObject.h"

struct Sound
{
};

class SoundSource : public Component
{
public:
	SoundSource(pGameObject gameObject);
	~SoundSource();
};

#endif // !__SOUND_SOURCE_H__