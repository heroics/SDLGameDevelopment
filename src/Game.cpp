#include "Game.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include <SDL2/SDL_image.h>

Game::~Game()
{
    //dtor
}
Game::Game()
{
}
void Game::quit()
{
    isRunning = false;
}
Game *Game::staticPtrInstance = 0;

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
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
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
    // Load player
    if (!TheTextureManager::Instance()->load("src/Assets/animate.png", "animate", renderer))
    {
        std::cout << "Player LOAD - [FAILURE]" << std::endl;
        return false;
    }
    std::cout << "Game::Init() - [SUCCESS]" << std::endl;
    isRunning = true;

    // Create Game Objects
    gameObjects.push_back(new Player(new LoaderParameters(300, 300, 52, 52, "animate")));
    std::cout << "Player Object Init - [SUCCESS]" << std::endl;
    gameObjects.push_back(new Enemy(new LoaderParameters(300, 300, 52, 52, "animate")));
    std::cout << "Enemy Object Init - [SUCCESS]" << std::endl;

    // Create the Joystick
    TheInputHandler::Instance()->initialiseJoysticks();
    return true;
}
void Game::render()
{
    // Clear the renderer to the draw color
    SDL_RenderClear(renderer);

    // Loop GameObjects Array and render objects
    for (std::vector<GameObject *>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
    // Draw the renderer to screen
    SDL_RenderPresent(renderer);
}
void Game::update()
{
    // Loop GameObjects Array and Update objects
    for (std::vector<GameObject *>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

void Game::clean()
{

    std::cout << "Cleaning Game" << std::endl;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TheInputHandler::Instance()->clean();
    SDL_Quit();
    std::cout << "Graceful Quit - [SUCCESS]" << std::endl;
}
bool Game::running()
{
    return isRunning;
}
void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
}
