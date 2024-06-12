#include "TransformComponent.h"

TransformComponent::TransformComponent(std::shared_ptr<Actor> owner, exVector2 loc)
    :   Component(owner),
        mLocation(loc)
{
}

exVector2 TransformComponent::GetPosition() const
{
    return mLocation;
}

void TransformComponent::SetPosition(const exVector2 inValue)
{
    mLocation = inValue;
}
