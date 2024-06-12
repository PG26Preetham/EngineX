#include "BoxColliderPhysicsComponent.h"
#include "TransformComponent.h"
#include "Game/Actors/Actor.h"
#include <algorithm>
#include <cmath>

BoxColliderPhysicsComponent::BoxColliderPhysicsComponent(std::shared_ptr<Actor> owner, float width, float height, exVector2 velocity)
    : PhysicsComponent(owner, false, true, velocity),
    mWidth(width), mHeight(height)
{
}

bool BoxColliderPhysicsComponent::IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComponent)
{
    if (!otherComponent)
    {
        return false;
    }

    std::shared_ptr<TransformComponent> currentTransformComponent = mOwner->FindComponentOfType<TransformComponent>();
    std::shared_ptr<TransformComponent> otherTransformComponent = otherComponent->GetOwner()->FindComponentOfType<TransformComponent>();

    if (!currentTransformComponent || !otherTransformComponent)
    {
        return false;
    }

    exVector2 currentPos = currentTransformComponent->GetPosition();
    exVector2 otherPos = otherTransformComponent->GetPosition();

    if (std::shared_ptr<BoxColliderPhysicsComponent> otherBoxCollider = std::dynamic_pointer_cast<BoxColliderPhysicsComponent>(otherComponent))
    {
        return (std::abs(currentPos.x - otherPos.x) * 2 < (mWidth + otherBoxCollider->mWidth)) &&
            (std::abs(currentPos.y - otherPos.y) * 2 < (mHeight + otherBoxCollider->mHeight));
    }

    return false;
}
