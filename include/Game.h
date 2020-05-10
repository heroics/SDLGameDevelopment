#ifndef GAME_H
#define GAME_H
#include "GameObject.h"
#include "Player.h"
#include "TextureManager.h"
#include <SDL2/SDL.h>
#include <iostream>
class Game
{
public:
    Game();
    virtual ~Game();
    bool init(const char *title, int xPosition, int yPosition, int width, int height, bool fullscreen);
    void render();
    void handleEvents();
    void clean();
    void update();
    bool running();

protected:
private:
    bool isRunning;
    int currentFrame;
    SDL_Window *window;
    SDL_Renderer *renderer;
    GameObject gameObject;
    Player player;
};
#endif // GAME_H
