#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H
#include "GameObject.h"
#include "LoaderParameters.h"
#include "Vector2D.h"
#include <string>
class SDLGameObject : public GameObject
{
public:
    SDLGameObject(const LoaderParameters *ptrLoaderParameters);
    virtual void draw();
    virtual void update();
    virtual void clean();

protected:
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    int width;
    int height;
    int currentRow;
    int currentFrame;
    std::string textureId;

private:
};

#endif // SDLGAMEOBJECT_H
