#include "Keyboard.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Components/BoxRenderComponent.h"
#include "Game/Components/BoxColliderPhysicsComponent.h"
#include "Game/Components/TransformComponent.h"

// Keyboard constructor aka (player)
Keyboard::Keyboard(exColor color, float width, float height )
    : Actor(),
    mColor(color), mWidth(width), mHeight(height)
{

}

// begins play for keybaord
void Keyboard::BeginPlay()
{
}

// initializes the actor with spawn position
void Keyboard::InitializeActor(const exVector2 spawnPosition)
{
    Actor::InitializeActor(spawnPosition);
    AddComponentOfType<BoxRenderComponent>(mColor, mWidth, mHeight);
    mBoxCollider = AddComponentOfType<BoxColliderPhysicsComponent>(mWidth, mHeight, exVector2{ 0.0f, 0.0f });
    mBoxCollider->SetIsStatic(true);
    CollisionEventSignature collisionDelegate = std::bind(&Keyboard::OnCollisionDetected, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    mBoxCollider->ListenForCollision(collisionDelegate);
}

// Set velocity of keyboard
void Keyboard::SetVelocity(const exVector2 newVelocity)
{
    if (mBoxCollider)
    {
        mBoxCollider->SetVelocity(newVelocity);
    }
}

// check for collision
void Keyboard::OnCollisionDetected(exVector2 normal, std::weak_ptr<Actor> otherActor, std::weak_ptr<PhysicsComponent> otherComponent)
{
    
}
