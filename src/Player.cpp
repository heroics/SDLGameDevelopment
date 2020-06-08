#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParameters *ptrLoaderParameters) : SDLGameObject(ptrLoaderParameters)
{
}

void Player::draw()
{
    SDLGameObject::draw();
}
void Player::update()
{
    velocity.setX(0);
    velocity.setY(0);
    handleInput();
    currentFrame = int(((SDL_GetTicks() / 100) % 6));
    SDLGameObject::update();
}
void Player::clean()
{
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        velocity.setX(1);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        velocity.setX(-1);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        velocity.setY(-2);
    }
        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        velocity.setY(2);
    }
}
