#include "Game/Private/Game.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"
#include "Game/GameCore/ActorTypes.h"
#include "Game/GameCore/ComponentTypes.h"
#include "Game/Singletons/RenderEngine.h"
#include "Game/Singletons/PhysicsEngine.h"
#include "Game/Singletons/WorldManager.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "pim pim bam bam pong pong";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
    : mEngine(nullptr)
    , mFontID(-1)
    , mUp(false)
    , mDown(false)
    , mW(false)
    , mS(false)
    , mBallVelocity(exVector2{ -12.5f, 0.0f })
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize(exEngineInterface* pEngine)
{
    mEngine = pEngine;

    // Add the Keyboard actor **PLAYERS**

    Robert = WORLD->SpawnActorOfClass<Keyboard>(exVector2{ 50.0f, 300.0f }, exColor{ 0, 0, 255, 255 }, 25.0f, 100.0f);
    Preetham = WORLD->SpawnActorOfClass<Keyboard>(exVector2{ 750.0f, 300.0f }, exColor{ 255, 0, 0, 255 }, 25.0f, 100.0f);

    // Add the Keyboard actor **COLLISION**
    UpCollision = WORLD->SpawnActorOfClass<Wall>(exVector2{ 400.0f, 10.0f }, exColor{ 200, 200, 200, 255 }, 800.0f, 10.0f);
    DownCollision = WORLD->SpawnActorOfClass<Wall>(exVector2{ 400.0f, 590.0f }, exColor{ 200, 200, 200, 255 }, 800.0f, 10.0f);
    // Moving ball or smth idk
    BallX = WORLD->SpawnActorOfClass<Ball>(exVector2{ 400.0f, 300.0f }, exColor{ 255, 255, 255, 255 }, 25.0f, 25.0f , exVector2{-12.5f,0});
    
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
    return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor(exColor& color) const
{
    color.mColor[0] = 5;
    color.mColor[1] = 5;
    color.mColor[2] = 5;
    color.mColor[3] = 255;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent(SDL_Event* pEvent)
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEventsConsumed()
{
    int nKeys = 0;
    const Uint8* pState = SDL_GetKeyboardState(&nKeys);

    mUp = pState[SDL_SCANCODE_UP];
    mDown = pState[SDL_SCANCODE_DOWN];
    mW = pState[SDL_SCANCODE_W];
    mS = pState[SDL_SCANCODE_S];
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run(float fDeltaT)
{
    // Robert Controls
    if (mW || mS)
    {
        auto transformComp = Robert->FindComponentOfType<TransformComponent>();
        if (transformComp)
        {
            exVector2 position = transformComp->GetPosition();
            if (mW)
            {
                position.y -= 500.0f * fDeltaT;
            }
            if (mS)
            {
                position.y += 500.0f * fDeltaT;
            }
            transformComp->SetPosition(position);
        }
    }

    // Preetham Controls
    if (mUp || mDown)
    {
        auto transformComp = Preetham->FindComponentOfType<TransformComponent>();
        if (transformComp)
        {
            exVector2 position = transformComp->GetPosition();
            if (mUp)
            {
                position.y -= 500.0f * fDeltaT;
            }
            if (mDown)
            {
                position.y += 500.0f * fDeltaT;
            }
            transformComp->SetPosition(position);
        }
    }



    // multithreading hehehahaha
    if (!RenderThread.joinable())
    {
        RenderThread = std::thread(&RenderEngine::Render, RENDER_ENGINE, mEngine);
    }

    if (!PhysicsThread.joinable())
    {
        PhysicsThread = std::thread(&PhysicsEngine::Physics, PHYSICS_ENGINE);
    }

    RenderThread.join();
    PhysicsThread.join();
}