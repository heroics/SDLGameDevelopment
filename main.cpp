#include "Game.h"
#include <SDL2/SDL.h>
// Our Game Object
Game *game = 0;
int main(int argc, char *args[])
{
    game = new Game();
    game->init("Chapter 1", 100, 100, 640, 480, false);
    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }
    game->clean();
    return 0;
}
