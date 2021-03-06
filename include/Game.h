#ifndef GAME_H
#define GAME_H
#include "Enemy.h"
#include "GameObject.h"
#include "Player.h"
#include "TextureManager.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
class Game
{
public:
    ~Game();
    bool init(const char *title, int xPosition, int yPosition, int width, int height, bool fullscreen);
    void render();
    void handleEvents();
    void clean();
    void update();
    bool running();
    void quit();
    static Game *Instance()
    {
        if (staticPtrInstance == 0)
        {
            staticPtrInstance = new Game();
            return staticPtrInstance;
        }
        return staticPtrInstance;
    }
    SDL_Renderer *getRender() const
    {
        return renderer;
    }

protected:
private:
    bool isRunning;
    int currentFrame;
    SDL_Window *window;
    SDL_Renderer *renderer;
    GameObject *gameObject;
    std::vector<GameObject *> gameObjects;
    Game();
    // Create Static Pointer Instance member variable
    static Game *staticPtrInstance;
};
typedef Game TheGame;

#endif // GAME_H
