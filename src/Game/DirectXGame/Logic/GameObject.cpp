#include "GameObject.h"

GameObject::GameObject(pScene scene)
{
	this->scene = scene;

	start = false;
	expired = false;
	enable = false;
	visible = false;
}

GameObject::~GameObject()
{
	scene = nullptr;
}

void GameObject::Load()
{
	xml_document prefabDoc;
	prefabDoc.load_file(source.c_str());

	layer = prefabDoc.child("Prefab").attribute("layer").as_int();
	xml_node componentsNode = prefabDoc.child("Prefab").child("Components");
	for (xml_node componentNode = componentsNode.child("Component");
		componentNode;
		componentNode = componentNode.next_sibling("Component"))
	{
		auto componentType = (Component::Type)componentNode.attribute("componentType").as_int();

		// Sprite Renderer
		if (componentType == Component::Type::SpriteRenderer)
		{
			pSpriteRenderer spriteRenderer = new SpriteRenderer(this);
			components[Component::Type::SpriteRenderer] = spriteRenderer;

			xml_node spriteRenderNode = componentNode.child("SpriteRenderer");

			for (xml_node paletteNode = spriteRenderNode.child("Palette");
				paletteNode;
				paletteNode = paletteNode.next_sibling("Palette"))
			{
				spriteRenderer->AddPalette(
					paletteNode.attribute("paletteNo").as_int(),
					paletteNode.attribute("textureID").as_string()
				);
			}

			for (xml_node spriteNode = spriteRenderNode.child("Sprite");
				spriteNode;
				spriteNode = spriteNode.next_sibling("Sprite"))
			{
				spriteRenderer->Add(
					spriteNode.attribute("spriteID").as_string(),
					spriteNode.attribute("paletting").as_bool(),
					spriteNode.attribute("paletteNo").as_int(),
					spriteNode.attribute("left").as_int(),
					spriteNode.attribute("top").as_int(),
					spriteNode.attribute("right").as_int(),
					spriteNode.attribute("bottom").as_int(),
					spriteNode.attribute("offsetX").as_int(),
					spriteNode.attribute("offsetY").as_int());
			}
		}

		// Animator
		else if (componentType == Component::Type::Animator)
		{
			pAnimator animator = new Animator(this);
			components[Component::Type::Animator] = animator;
		
			xml_node animatorNode = componentNode.child("Animator");
			for (xml_node animationNode = animatorNode.child("Animation");
				animationNode;
				animationNode = animationNode.next_sibling("Animation"))
			{
				animator->AddAnimation(animationNode.attribute("animationID").as_string());
		
				for (xml_node animationFrameNode = animationNode.child("AnimationFrame");
					animationFrameNode;
					animationFrameNode = animationFrameNode.next_sibling("AnimationFrame"))
				{
					animator->AddAnimationFrame(
						animationNode.attribute("animationID").as_string(),
						animationFrameNode.attribute("spriteID").as_string(),
						animationFrameNode.attribute("frameTime").as_float()
					);
				}
			}
		}
		
		// Tilemap
		else if (componentType == Component::Type::Tilemap)
		{
			pTilemap tilemap = new Tilemap(this);
			components[Component::Type::Tilemap] = tilemap;

			xml_node tilemapNode = componentNode.child("Tilemap");
			tilemap->CreateMap(
				tilemapNode.attribute("mapColumn").as_int(),
				tilemapNode.attribute("mapRow").as_int(),
				tilemapNode.attribute("tileWidth").as_int(),
				tilemapNode.attribute("tileHeight").as_int(),
				tilemapNode.attribute("tileColumn").as_int(),
				tilemapNode.attribute("tileRow").as_int(),
				tilemapNode.attribute("margin").as_int());

			tilemap->LoadTileSet();

			int cellNo = 0;
			for (xml_node tileNode = tilemapNode.child("Tile");
				tileNode;
				tileNode = tileNode.next_sibling("Tile"))
			{
				tilemap->AddCell(
					(cellNo % tilemap->mapColumn), 
					(cellNo / tilemap->mapColumn),
					tileNode.attribute("tileNo").as_int());
				cellNo++;
			}
		}
		
		// Text Renderer
		else if (componentType == Component::Type::TextRenderer)
		{
			pTextRenderer textRenderer = new TextRenderer(this);
			components[Component::Type::TextRenderer] = textRenderer;
		}

		// Sound Source
		else if (componentType == Component::Type::SoundSource)
		{
			pSoundSource soundSource = new SoundSource(this);
			components[Component::Type::SoundSource] = soundSource;
		}

		// Physics
		else if (componentType == Component::Type::Physics)
		{
		pPhysics physics = new Physics(this);
		components[Component::Type::Physics] = physics;
		}
	}
}

void GameObject::Unload()
{
	for (auto component : components)
		delete component.second;
	components.clear();
}

void GameObject::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void GameObject::GetPosition(float& x, float& y)
{
	x = this->x;
	y = this->y;
}

void GameObject::Translate(float x, float y)
{
	this->x += x;
	this->y += y;
}

pSpriteRenderer GameObject::GetSpriteRenderer()
{
	if (components.find(Component::Type::SpriteRenderer) == components.end()) return nullptr;
	return dynamic_cast<pSpriteRenderer>(components[Component::Type::SpriteRenderer]);
}

pAnimator GameObject::GetAnimator()
{
	if (components.find(Component::Type::Animator) == components.end()) return nullptr;
	return dynamic_cast<pAnimator>(components[Component::Type::Animator]);
}

pTilemap GameObject::GetTilemap()
{
	if (components.find(Component::Type::Tilemap) == components.end()) return nullptr;
	return dynamic_cast<pTilemap>(components[Component::Type::Tilemap]);
}

pTextRenderer GameObject::GetTextRenderer()
{
	if (components.find(Component::Type::TextRenderer) == components.end()) return nullptr;
	return dynamic_cast<pTextRenderer>(components[Component::Type::TextRenderer]);
}

pSoundSource GameObject::GetSoundSource()
{
	if (components.find(Component::Type::SoundSource) == components.end()) return nullptr;
	return dynamic_cast<pSoundSource>(components[Component::Type::SoundSource]);
}

pPhysics GameObject::GetPhysics()
{
	if (components.find(Component::Type::Physics) == components.end()) return nullptr;
	return dynamic_cast<pPhysics>(components[Component::Type::Physics]);
}

bool GameObject::LayerCompare(const pGameObject& a, const pGameObject& b)
{
	return a->layer < b->layer;
}
