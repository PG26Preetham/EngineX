#pragma once
#include "PhysicsComponent.h"

class BoxColliderPhysicsComponent : public PhysicsComponent
{
public:
    BoxColliderPhysicsComponent() = delete;
    BoxColliderPhysicsComponent(std::shared_ptr<Actor> owner, float width, float height, exVector2 velocity);

// protected variables Box ColliderPhysicsComponent has
protected:
    virtual bool IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComponent) override;

    float mWidth;
    float mHeight;
};
