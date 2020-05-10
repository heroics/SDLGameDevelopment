#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>
#include <string>

class TextureManager
{
public:
    virtual ~TextureManager();
    bool load(std::string fileName, std::string id, SDL_Renderer *ptrRenderer);
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer *ptrRenderer, SDL_RendererFlip rendererFlip = SDL_FLIP_NONE);
    void drawCurrentFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *ptrRenderer, SDL_RendererFlip rendererFlip = SDL_FLIP_NONE);
    static TextureManager *Instance()
    {
        if (staticPtrInstance == 0)
        {
            staticPtrInstance = new TextureManager();
            return staticPtrInstance;
        }
        return staticPtrInstance;
    }

private:
    std::map<std::string, SDL_Texture *> textureMap;
    static TextureManager *staticPtrInstance;
    TextureManager();
};

typedef TextureManager TheTextureManager;

#endif // TEXTUREMANAGER_H
