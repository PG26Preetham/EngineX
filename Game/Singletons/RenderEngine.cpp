#include "RenderEngine.h"
#include "Game/Components/RenderComponent.h"

// always initialize static variables
RenderEngine* RenderEngine::sInstance = nullptr;

RenderEngine* RenderEngine::GetInstance()
{
	if (!sInstance)
	{
		sInstance = new RenderEngine();
	}
	return sInstance;
}

void RenderEngine::AddRenderningComponent(std::shared_ptr<RenderComponent> componentToAdd)
{
	mRenderComponentList.push_back(componentToAdd);
}

void RenderEngine::Render(exEngineInterface* engineInterface)
{
	for (std::weak_ptr<RenderComponent> componentToRender : mRenderComponentList)
	{
		if (!componentToRender.expired())
		{
			componentToRender.lock()->Render(engineInterface);
		}
	}
}

RenderEngine::RenderEngine()
{
}
