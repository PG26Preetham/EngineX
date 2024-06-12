#pragma once

#include "Component.h"
#include "Engine/Public/EngineTypes.h"

class PhysicsComponent;

typedef std::function<void(exVector2, std::weak_ptr<Actor>, std::weak_ptr<PhysicsComponent>)> CollisionEventSignature;

class PhysicsComponent :	public Component,
							public std::enable_shared_from_this<PhysicsComponent>
{
	friend class PhysicsEngine;

public:

	PhysicsComponent() = delete;
	PhysicsComponent(std::shared_ptr<Actor> owner, bool isStatic, bool isGravityEnabled, exVector2 velocity);

	// @TODO
	// float GetSpeed() const;

	// Physics Function


	
	virtual void InitializeComponent();

	// Getter and Setters
	exVector2 GetVelocity() const;

	void SetVelocity(const exVector2 inVelocity);

	virtual bool IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComponent);

	void ListenForCollision(CollisionEventSignature& delegateToAdd);

	void SetIsStatic(bool isStatic);

protected:

	virtual void Physics();

	bool mIsStatic;
	bool mIsGravityEnabled;
	
	exVector2 mVelocity;

private:

	std::list<CollisionEventSignature> mCollisionEvents;
};

