#include "RenderComponent.h"
#include "Game/Singletons/RenderEngine.h"

RenderComponent::RenderComponent(std::shared_ptr<Actor> owner, exColor color)
	: Component(owner),
	mColor(color)
{
}

void RenderComponent::InitializeComponent()
{
	Component::InitializeComponent();

	RENDER_ENGINE->AddRenderningComponent(shared_from_this());
}

exColor RenderComponent::GetColor() const
{
	return mColor;
}

void RenderComponent::SetColor(exColor inColor)
{
	mColor = inColor;
}
