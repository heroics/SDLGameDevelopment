#include "SDLGameObject.h"
#include "Game.h"
#include "TextureManager.h"
SDLGameObject::SDLGameObject(const LoaderParameters *pParams) : GameObject(pParams), position(pParams->getXPosition(), pParams->getYPosition()), velocity(0, 0), acceleration(0,0)
{
    this->width = pParams->getWidth();
    this->height = pParams->getHeight();
    this->textureId = pParams->getTextureId();
    this->currentRow = 1;
    this->currentFrame = 1;
}
void SDLGameObject::draw()
{
    TextureManager::Instance()->drawCurrentFrame(textureId, (int)position.getX(), (int)position.getY(), width, height, currentRow, currentFrame, TheGame::Instance()->getRender());
}
void SDLGameObject::update()
{
    velocity += acceleration;
    position += velocity;
}
void SDLGameObject::clean()
{
}
