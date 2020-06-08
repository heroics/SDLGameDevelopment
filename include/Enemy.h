#ifndef ENEMY_H
#define ENEMY_H
#include "SDLGameObject.h"
#include <string>

class Enemy : public SDLGameObject
{
public:
    Enemy(const LoaderParameters *ptrLoaderParameters);
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif // ENEMY_H
