#include "Game.h"
Game::Game()
{
    //ctor
}
Game::~Game()
{
    //dtor
}
bool Game::init(const char *title, int xPostion, int yPosition, int width, int height, bool isFullScreen)
{
    // Attempt to Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        int flags = 0;
        if (isFullScreen)
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }
        std::cout << "SDL Init - [SUCCESS]" << std::endl;
        // Init the window
        window = SDL_CreateWindow(title, xPostion, yPosition, width, height, flags);
        if (window != 0)
        {
            std::cout << "Window Init - [SUCCESS]" << std::endl;
            // Init the Render
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer != 0)
            {
                std::cout << "Renderer Init - [SUCCESS]" << std::endl;
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            }
            else
            {
                std::cout << "Renderer init - [FAILURE]" << std::endl;
                return false;
            }
        }
        else
        {
            std::cout << "Window init - [FAILURE]" << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "SDL init - [FAILURE]" << std::endl;
        return false;
    }
    std::cout << "Game::Init() - [SUCCESS]" << std::endl;
    isRunning = true;
    return true;
}
void Game::render()
{
    // Clear the renderer to the draw color
    SDL_RenderClear(this->renderer);
    // Draw the renderer to screen
    SDL_RenderPresent(this->renderer);
}
void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
        }
    }
}
void Game::clean()
{
    std::cout << "Cleaning Game" << std::endl;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
bool Game::running()
{
    return isRunning;
}
void Game::update()
{

}
