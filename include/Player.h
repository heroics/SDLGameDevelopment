#ifndef PLAYER_H
#define PLAYER_H
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
    Player(const LoaderParameters *ptrLoaderParameters);
    virtual void draw();
    virtual void update();
    virtual void clean();

private:
    void handleInput();
};

#endif // PLAYER_H
