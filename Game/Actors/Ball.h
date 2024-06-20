#pragma once

#include "Actor.h"
#include "Engine/Public/EngineTypes.h"
#include <memory>

class Ball :public Actor
{

public:
    // Constructor for ball
    Ball(exColor color, float width, float height , exVector2 velocity);

    // Sets ball prerequisites
    virtual void BeginPlay() override;
    virtual void InitializeActor(const exVector2 spawnPosition) override;
    void SetVelocity(const exVector2 newVelocity);
    void OnCollisionDetected(exVector2 normal, std::weak_ptr<Actor> otherActor, std::weak_ptr<PhysicsComponent> otherComponent);

// private variables that the ball has
private:
    exColor mColor;
    float mWidth;
    float mHeight;
    exVector2 mVeclocity;
    std::shared_ptr<BoxColliderPhysicsComponent> mBoxCollider;
};

