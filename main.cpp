#include "Game.h"
#include <SDL2/SDL.h>
#include <iostream>
// Our Game Object
Game *game = 0;
// Constant Values
const int FRAMESPERSECOND = 60;
const int DELAYTIME = 1000.0f / FRAMESPERSECOND;
int main(int argc, char *args[])
{
    Uint32 frameStart;
    Uint32 frameTime;
    std::cout << "Attempting game init..." << std::endl;
    if (TheGame::Instance()->init("Super Brave Knight", 100, 100, 640, 480, false))
    {
        std::cout << "Super Brave Knight Game Init - [SUCCESS]" << std::endl;
        while (TheGame::Instance()->running())
        {
            frameStart = SDL_GetTicks();
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();
            frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < DELAYTIME)
            {
                SDL_Delay((int)(DELAYTIME - frameTime));
            }
        }
    }
    else
    {
        std::cout << "Game Init - [FAILURE]" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return -1;
    }
    std::cout << "Attempting Game Close..." << std::endl;
    TheGame::Instance()->clean();
    std::cout << "Game Close - [SUCCESS]" << std::endl;
    return 0;
}
