#pragma once
#include "Game/GameCore/Utils.h"

#define PHYSICS_ENGINE PhysicsEngine::GetInstance()

// forward declaring Physics component
class PhysicsComponent;

class PhysicsEngine
{

public:

	static PhysicsEngine* GetInstance();

	// will add Physics components to do physics List
	void AddPhysicsComponent(std::shared_ptr<PhysicsComponent> componentToAdd);

	// do all Physics
	void Physics();

	// @TODO write a function to remove the rendering component

private:

	PhysicsEngine();

	// stores the RenderComponents
	std::list<std::weak_ptr<PhysicsComponent>> mPhysicsComponentList;

	static PhysicsEngine* sInstance;
};

