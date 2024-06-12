#pragma once

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include "Game/GameCore/Utils.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

class Actor;
class Keyboard;
class Ball;
class Wall;

class MyGame : public exGameInterface
{
public:

    MyGame();
    virtual ~MyGame();

    virtual void Initialize(exEngineInterface* pEngine);

    virtual const char* GetWindowName() const;
    virtual void GetClearColor(exColor& color) const;

    virtual void OnEvent(SDL_Event* pEvent);
    virtual void OnEventsConsumed();

    virtual void Run(float fDeltaT);

private:

    exEngineInterface* mEngine;

    int mFontID;

    bool mUp;
    bool mDown;
    bool mW;
    bool mS;

    std::shared_ptr<Keyboard> Robert;
    std::shared_ptr<Keyboard> Preetham;
    std::shared_ptr<Wall> UpCollision;
    std::shared_ptr<Wall> DownCollision;
    std::shared_ptr<Ball> BallX;
    exVector2 mBallVelocity;
    std::thread RenderThread;
    std::thread PhysicsThread;
};
