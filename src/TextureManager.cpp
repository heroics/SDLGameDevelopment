#include "TextureManager.h"

TextureManager *TextureManager::staticPtrInstance = 0;

TextureManager::TextureManager()
{
    //ctor
}

TextureManager::~TextureManager()
{
    //dtor
}

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer *ptrRenderer)
{
    SDL_Surface *ptrTempSurface = IMG_Load(fileName.c_str());
    if (ptrTempSurface == 0)
    {
        return false;
    }
    SDL_Texture *ptrTexture = SDL_CreateTextureFromSurface(ptrRenderer, ptrTempSurface);
    SDL_FreeSurface(ptrTempSurface);
    // If no errors, add the texture to the list
    if (ptrTexture != 0)
    {
        textureMap[id] = ptrTexture;
        return true;
    }
    // Reaching here means something went wrong
    std::cout << "Texture Manager Load - [FAILURE]" << std::endl;
    return false;
}

void TextureManager::draw(std::string id, int xPosition, int yPosition, int width, int height, SDL_Renderer *ptrRender, SDL_RendererFlip rendererFlip)
{
    SDL_Rect sourceRect;
    SDL_Rect destinationRect;
    sourceRect.x = 0;
    sourceRect.y = 0;
    destinationRect.w = width;
    sourceRect.w = destinationRect.w;
    destinationRect.h = height;
    sourceRect.h = destinationRect.h;
    destinationRect.x = xPosition;
    destinationRect.y = yPosition;
    SDL_RenderCopyEx(ptrRender, textureMap[id], &sourceRect, &destinationRect, 0, 0, rendererFlip);
}
void TextureManager::drawCurrentFrame(std::string id, int xPosition, int yPosition, int width, int height, int currentRow, int currentFrame, SDL_Renderer *ptrRenderer, SDL_RendererFlip rendererFlip)
{
    SDL_Rect sourceRect;
    SDL_Rect destinationRect;
    sourceRect.x = width * currentFrame;
    sourceRect.y = height * (currentRow - 1);
    destinationRect.w = width;
    sourceRect.w = destinationRect.w;
    destinationRect.h = height;
    sourceRect.h = destinationRect.h;
    destinationRect.x = xPosition;
    destinationRect.y = yPosition;
    SDL_RenderCopyEx(ptrRenderer, textureMap[id], &sourceRect, &destinationRect, 0, 0, rendererFlip);
}
