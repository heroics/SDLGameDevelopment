#ifndef GAME_H
#define GAME_H
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
    SDL_Window *window;
    SDL_Renderer *renderer;
};
#endif // GAME_H
