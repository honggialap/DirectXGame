#include "Transform.h"

Transform::Transform() : Component::Component()
{
	componentType = ComponentType::Transform;
}

Transform::~Transform()
{
}
