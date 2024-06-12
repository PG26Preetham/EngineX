#pragma once
#include "Component.h"
#include "Engine/Public/EngineTypes.h"

class exEngineInterface;

class RenderComponent : public Component , 
						public std::enable_shared_from_this<RenderComponent>
{
	friend class RenderEngine;
public:

	RenderComponent() = delete;
	RenderComponent(std::shared_ptr<Actor> owner, exColor color);

	virtual void InitializeComponent() override;

	// Getters
	exColor GetColor() const;

	// Setters
	void SetColor(exColor inColor);


protected:

	virtual void Render(exEngineInterface* engineInterface) = 0;
	exColor mColor;
};

