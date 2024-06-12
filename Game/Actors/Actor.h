#pragma once

#include "Game/GameCore/ComponentTypes.h"
#include <type_traits>


class Actor : public std::enable_shared_from_this<Actor>
{
protected:

	// List of components added to the actor
	ComponentList mComponents;

public:
	Actor();

	~Actor();

	// overridable functions
	virtual void BeginPlay();
	virtual void EndPlay();
	virtual void Tick(float deltaSeconds);

	virtual void InitializeActor(const exVector2 spawnPosition);

	exVector2 GetActorLocation();

	// Variadic Argmuments
	template<std::derived_from<Component> ComponentType, typename ...Args>
	std::shared_ptr<ComponentType> AddComponentOfType(Args... arguments)
	{
		std::shared_ptr<ComponentType> newComponent = std::make_shared<ComponentType>(shared_from_this(), arguments...);
		mComponents.push_back(newComponent);
		newComponent->InitializeComponent();

		return newComponent;
	}

	template<std::derived_from<Component> ComponentTypeToFind>
	std::shared_ptr<ComponentTypeToFind>  FindComponentOfType()
	{
		for (std::shared_ptr<Component> componentIterator : mComponents)
		{
			if (std::shared_ptr<ComponentTypeToFind> foundComponent 
				= std::dynamic_pointer_cast<ComponentTypeToFind>(componentIterator))
			{
				return foundComponent;
			}
		}
		return nullptr;
	}

private:
	std::shared_ptr<TransformComponent> mTransformComponent;
};

