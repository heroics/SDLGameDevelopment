#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}
void Player::load(int xPosition, int yPosition, int width, int height, std::string textureId)
{
    GameObject::load(xPosition, yPosition, width, height, textureId);
}
void Player::draw(SDL_Renderer *ptrRenderer)
{
    GameObject::draw(ptrRenderer);
}
void Player::update()
{
    x -= 1;
}
void Player::clean()
{


}
