#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <LoaderParameters.h>
#include <SDL2/SDL.h>
#include <string>
class GameObject
{
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;

protected:
    GameObject(const LoaderParameters *ptrParams) {}
    virtual ~GameObject() {}
};
#endif // GAMEOBJECT_H
