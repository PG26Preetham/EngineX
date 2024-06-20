#include "Actor.h"

// Constructor
Actor::Actor()
{
}

// Destructor
Actor::~Actor()
{
}

// Start game logic
void Actor::BeginPlay()
{
}

// Eng game logic
void Actor::EndPlay()
{
}

// Update every frame for each actor
void Actor::Tick(float deltaSeconds)
{
}

// Spawning actor
void Actor::InitializeActor(const exVector2 spawnPosition)
{
	mTransformComponent =  AddComponentOfType<TransformComponent>(spawnPosition);
}

// Get actor location
exVector2 Actor::GetActorLocation()
{
	return mTransformComponent->GetPosition();
}
