#include "Game.h"
#include <SDL2/SDL.h>

// Our Game Object
Game *game = 0;
SDL_Window *gameWindow = 0;
SDL_Renderer *gameRenderer = 0;

int main(int argc, char *args[])
{
    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        // If succeeded create renderer window
        gameWindow = SDL_CreateWindow("Chapter 1: Setting Up SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
        // if the window creation succeeded create the renderer
        if (gameWindow != 0)
        {
            gameRenderer = SDL_CreateRenderer(gameWindow, -1, 0);
        }
        else
        {
            return 1;
        }
    }
    // Set to black
    SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 255);
    // Clear the window to black
    SDL_RenderClear(gameRenderer);
    // Draw the window;
    SDL_RenderPresent(gameRenderer);
    // Delay Before Quitting
    SDL_Delay(5000);
    // Gracefully Clean SDL
    SDL_Quit();
    return 0;
}