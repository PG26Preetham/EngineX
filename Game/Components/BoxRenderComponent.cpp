#include "BoxRenderComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Components/TransformComponent.h"
#include "Game/Actors/Actor.h"

BoxRenderComponent::BoxRenderComponent(std::shared_ptr<Actor> owner, exColor color, float width, float height)
	: RenderComponent(owner, color),
	mWidth(width),
	mHeight(height)
{
}

void BoxRenderComponent::Render(exEngineInterface* engineInterface)
{
	std::shared_ptr<TransformComponent> transformComp = mOwner->FindComponentOfType<TransformComponent>();

	if (transformComp)
	{
		const exVector2 centerPosition = transformComp->GetPosition();
		const exVector2 halfBoxDimension = exVector2{ mWidth * 0.5f, mHeight * 0.5f };
		const exVector2 topLeftPosition = centerPosition - halfBoxDimension;
		const exVector2 bottomRightPosition = centerPosition + halfBoxDimension;

		engineInterface->DrawBox(topLeftPosition, bottomRightPosition, mColor, 0);
	}
}
