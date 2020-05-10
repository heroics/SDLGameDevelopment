#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include <iostream>
#include <string>

class Player : public GameObject
{
public:
    Player();
    ~Player();
    void load(int xPosition, int yPosition, int width, int height, std::string textureId);
    void draw(SDL_Renderer *ptrRenderer);
    void update();

    void clean();

protected:
private:
};

#endif // PLAYER_H
