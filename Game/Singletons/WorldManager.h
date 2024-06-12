#pragma once

#include "Game/GameCore/Utils.h"
#include "Game/GameCore/ActorTypes.h"

#define WORLD WorldManager::GetInstnance()

class WorldManager
{

public:

	static WorldManager* GetInstnance();

	template<std::derived_from<Actor> ActorType, typename ...Args>
	std::shared_ptr<ActorType> SpawnActorOfClass(exVector2 spawnLocation, Args... arguments)
	{
		std::shared_ptr<ActorType> newActor = std::make_shared<ActorType>(arguments...);

		newActor->InitializeActor(spawnLocation);
		mActors.push_back(newActor);
		return newActor;
	}

private:

	WorldManager();

	static WorldManager* sInstance;

	std::list<std::shared_ptr<Actor>> mActors;
};

