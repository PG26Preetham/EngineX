#include "Ball.h"
#include"Game/GameCore/ActorTypes.h"

// initialzes ball with colour width height and velocity
Ball::Ball(exColor color, float width, float height , exVector2 velocity) : Actor(),
mColor(color), mWidth(width), mHeight(height),mVeclocity(velocity)
{
}

// initialzes ball for begin play
void Ball::BeginPlay()
{
}

// initialzes the actor with the spawn position and adds the components
void Ball::InitializeActor(const exVector2 spawnPosition)
{
    Actor::InitializeActor(spawnPosition);
    AddComponentOfType<BoxRenderComponent>(mColor, mWidth, mHeight);
    mBoxCollider = AddComponentOfType<BoxColliderPhysicsComponent>(mWidth, mHeight, mVeclocity);
   
    CollisionEventSignature collisionDelegate = std::bind(&Ball::OnCollisionDetected, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    mBoxCollider->ListenForCollision(collisionDelegate);
}

// sets velocity
void Ball::SetVelocity(const exVector2 newVelocity)
{
    if (mBoxCollider)
    {
        mBoxCollider->SetVelocity(newVelocity);
    }
}

// detects collision with ball keybaord and wall
void Ball::OnCollisionDetected(exVector2 normal, std::weak_ptr<Actor> otherActor, std::weak_ptr<PhysicsComponent> otherComponent)
{
    if (std::dynamic_pointer_cast<Keyboard>(otherActor.lock()))
    {
        exVector2 dif = GetActorLocation() - otherActor.lock()->GetActorLocation();
        float ydifnormal = 0;
        if (dif.y > 0) ydifnormal = 5;
        else if (dif.y < 0) ydifnormal = -5;
        SetVelocity(exVector2(mBoxCollider->GetVelocity().x * -1,ydifnormal));
    }
    else if(std::dynamic_pointer_cast<Wall>(otherActor.lock()))
    {
       SetVelocity(exVector2(mBoxCollider->GetVelocity().x , mBoxCollider->GetVelocity().y * -1));

    }
}
