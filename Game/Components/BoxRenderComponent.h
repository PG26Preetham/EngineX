#pragma once
#include "RenderComponent.h"
class BoxRenderComponent : public RenderComponent
{

public:

	BoxRenderComponent() = delete;

	BoxRenderComponent(std::shared_ptr<Actor> owner, exColor color, float width, float height);

	virtual void Render(exEngineInterface* engineInterface) override;

private:

	float mWidth;
	float mHeight;
};

