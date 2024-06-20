#pragma once

#include "Actor.h"
#include "Engine/Public/EngineTypes.h"
#include <memory>

class Keyboard : public Actor
{
public:
    // Constructor
    Keyboard(exColor color, float width, float height);

    // overridable variables
    virtual void BeginPlay() override;
    virtual void InitializeActor(const exVector2 spawnPosition) override;
    void SetVelocity(const exVector2 newVelocity);
    void OnCollisionDetected(exVector2 normal, std::weak_ptr<Actor> otherActor, std::weak_ptr<PhysicsComponent> otherComponent);

// private variables that the keybaord has
private:
    exColor mColor;
    float mWidth;
    float mHeight;
    bool mIsStatic;
    std::shared_ptr<BoxColliderPhysicsComponent> mBoxCollider;
};
