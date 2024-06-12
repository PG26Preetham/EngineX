#include "Wall.h"

Wall::Wall(exColor color, float width, float height) : Actor(),
mColor(color), mWidth(width), mHeight(height)
{
}

void Wall::BeginPlay()
{
}

void Wall::InitializeActor(const exVector2 spawnPosition)
{
    Actor::InitializeActor(spawnPosition);
    AddComponentOfType<BoxRenderComponent>(mColor, mWidth, mHeight);
    mBoxCollider = AddComponentOfType<BoxColliderPhysicsComponent>(mWidth, mHeight, exVector2{ 0.0f, 0.0f });
    mBoxCollider->SetIsStatic(true);
    CollisionEventSignature collisionDelegate = std::bind(&Wall::OnCollisionDetected, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    mBoxCollider->ListenForCollision(collisionDelegate);
}

void Wall::SetVelocity(const exVector2 newVelocity)
{

}

void Wall::OnCollisionDetected(exVector2 normal, std::weak_ptr<Actor> otherActor, std::weak_ptr<PhysicsComponent> otherComponent)
{
}
