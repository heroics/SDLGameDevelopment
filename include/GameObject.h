#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
#include <SDL2/SDL.h>
class GameObject
{
public:
    virtual void load(int x, int y, int width, int height, std::string textureID);
    virtual void draw(SDL_Renderer *pRenderer);
    virtual void update();
    virtual void clean();

protected:
    std::string textureID;
    int currentFrame;
    int currentRow;
    int x;
    int y;
    int width;
    int height;
};

#endif // GAMEOBJECT_H
