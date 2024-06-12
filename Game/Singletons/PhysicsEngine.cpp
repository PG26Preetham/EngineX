#include "PhysicsEngine.h"
#include "Game/Components/PhysicsComponent.h"

#include <cstdlib> 

// always initialize static variables
PhysicsEngine* PhysicsEngine::sInstance = nullptr;

PhysicsEngine* PhysicsEngine::GetInstance()
{
	if (!sInstance)
	{
		sInstance = new PhysicsEngine();
	}
	return sInstance;
}

void PhysicsEngine::AddPhysicsComponent(std::shared_ptr<PhysicsComponent> componentToAdd)
{
	mPhysicsComponentList.push_back(componentToAdd);
}

void PhysicsEngine::Physics()
{

	for (std::weak_ptr<PhysicsComponent> currentPhysicsComponent : mPhysicsComponentList)
	{
		if (!currentPhysicsComponent.expired())
		{
			currentPhysicsComponent.lock()->Physics();

			for (std::weak_ptr<PhysicsComponent> otherPhysicsComponent : mPhysicsComponentList)
			{
				if (!otherPhysicsComponent.expired())
				{
					if (otherPhysicsComponent.lock() != currentPhysicsComponent.lock())
					{
						if (currentPhysicsComponent.lock()->IsCollisionDetected(otherPhysicsComponent.lock()))
						{
							// @TODO change resolution based on requirement
							//int randnumber = (rand() % 10) - 1;
							//std::cout << randnumber;
							//const exVector2 newVelocity = exVector2(currentPhysicsComponent.lock()->GetVelocity().x * -1.0f ,randnumber);
							//currentPhysicsComponent.lock()->SetVelocity(newVelocity);

							// call collision events
							for (CollisionEventSignature& collisionEvent : currentPhysicsComponent.lock()->mCollisionEvents)
							{
								// @TODO write function to calculate the normal
								collisionEvent(exVector2(0.0f,0.0f),otherPhysicsComponent.lock()->GetOwner(), otherPhysicsComponent);
							}
						}
					}
				}
			}
		}
	}
}

PhysicsEngine::PhysicsEngine()
{
}
