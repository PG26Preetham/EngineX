#pragma once
#include "Game/GameCore/Utils.h"

#define RENDER_ENGINE RenderEngine::GetInstance()

// forward declaring render component
class RenderComponent;
class exEngineInterface;

class RenderEngine
{

public:

	static RenderEngine* GetInstance();

	// will add render components to render List
	void AddRenderningComponent(std::shared_ptr<RenderComponent> componentToAdd);

	// Render all render components from the list
	void Render(exEngineInterface* engineInterface);

	// @TODO write a function to remove the rendering component

private:

	RenderEngine();

	// stores the RenderComponents
	std::list<std::weak_ptr<RenderComponent>> mRenderComponentList;

	static RenderEngine* sInstance;
};

