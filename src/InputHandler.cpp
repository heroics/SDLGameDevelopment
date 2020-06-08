#include "InputHandler.h"
#include "Game.h"
InputHandler *InputHandler::staticPtrInstance = 0;
const int NUMBEROFMOUSEBUTTONS = 3;
InputHandler::InputHandler() : keyState(0), isJoysticksInitialised(true), mousePosition(new Vector2D(0, 0))
{
    for (int i = 0; i < 3; i++)
    {
        mouseButtonStates.push_back(false);
    }
}
InputHandler::~InputHandler()
{
    // delete everything created dynamically
    delete keyState;
    delete mousePosition;
    // Clear arrays
    joystickValues.clear();
    joysticks.clear();
    joystickButtonStates.clear();
    mouseButtonStates.clear();
}
void InputHandler::initialiseJoysticks()
{
    if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
    {
        SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }
    if (SDL_NumJoysticks() > 0)
    {
        for (int i = 0; i < SDL_NumJoysticks(); i++)
        {
            SDL_Joystick *joystick = SDL_JoystickOpen(i);
            if (SDL_JoystickOpen(i))
            {
                joysticks.push_back(joystick);
                joystickValues.push_back(std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));
                std::vector<bool> tempButtons;
                for (int j = 0; j < SDL_JoystickNumButtons(joystick); j++)
                {
                    tempButtons.push_back(false);
                }
                joystickButtonStates.push_back(tempButtons);
            }
            else
            {
                std::cout << "Joystick Init - [FAILURE]" << std::endl;
                std::cout << SDL_GetError();
            }
        }
        SDL_JoystickEventState(SDL_ENABLE);
        isJoysticksInitialised = true;
        std::cout << "Joystick Init - [SUCCESS]" << std::endl;
    }
    else
    {
        isJoysticksInitialised = false;
    }
}
void InputHandler::clean()
{
    if (isJoysticksInitialised)
    {
        for (int i = 0; i < SDL_NumJoysticks(); i++)
        {
            SDL_JoystickClose(joysticks[i]);
        }
    }
}
void InputHandler::reset()
{
    mouseButtonStates[LEFT] = false;
    mouseButtonStates[RIGHT] = false;
    mouseButtonStates[MIDDLE] = false;
}
bool InputHandler::isKeyDown(SDL_Scancode key) const
{
    if (keyState != 0)
    {
        if (keyState[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
int InputHandler::getAxisX(int identifier, int stick) const
{
    if (joystickValues.size() > 0)
    {
        if (stick == 1)
        {
            return joystickValues[identifier].first->getX();
        }
        else if (stick == 2)
        {
            return joystickValues[identifier].second->getX();
        }
    }
    return 0;
}
int InputHandler::getAxisY(int identifier, int stick) const
{
    if (stick == 1)
    {
        return joystickValues[identifier].first->getY();
    }
    else if (stick == 2)
    {
        return joystickValues[identifier].second->getY();
    }
    return 0;
}
bool InputHandler::getJoyStickButtonState(int joystick, int buttonNumber) const
{
    return joystickButtonStates[joystick][buttonNumber];
}
bool InputHandler::getMouseButtonState(int buttonNumber) const
{
    return mouseButtonStates[buttonNumber];
}
Vector2D *InputHandler::getMousePosition() const
{
    return mousePosition;
}
void InputHandler::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            TheGame::Instance()->quit();
            break;
        case SDL_JOYAXISMOTION:
            onJoystickAxisMove(event);
            break;
        case SDL_JOYBUTTONDOWN:
            onJoystickButtonDown(event);
            break;
        case SDL_JOYBUTTONUP:
            onJoystickButtonUp(event);
            break;
        case SDL_MOUSEMOTION:
            onMouseMove(event);
            break;
        case SDL_KEYDOWN:
            onKeyDown();
            break;
        case SDL_KEYUP:
            onKeyUp();
            break;
        default:
            break;
        }
    }
}
void InputHandler::onKeyDown()
{
    keyState = SDL_GetKeyboardState(0);
}
void InputHandler::onKeyUp()
{
    keyState = SDL_GetKeyboardState(0);
}
void InputHandler::onMouseMove(SDL_Event &event)
{
    mousePosition->setX(event.motion.x);
    mousePosition->setY(event.motion.y);
}
void InputHandler::onMouseButtonDown(SDL_Event &event)
{
    if (event.button.button == SDL_BUTTON_LEFT)
    {
        mouseButtonStates[LEFT] = true;
    }
    if (event.button.button == SDL_BUTTON_MIDDLE)
    {
        mouseButtonStates[MIDDLE] = true;
    }
    if (event.button.button == SDL_BUTTON_RIGHT)
    {
        mouseButtonStates[RIGHT] = true;
    }
}
void InputHandler::onMouseButtonUp(SDL_Event &event)
{
    if (event.button.button == SDL_BUTTON_LEFT)
    {
        mouseButtonStates[LEFT] = false;
    }
    if (event.button.button == SDL_BUTTON_MIDDLE)
    {
        mouseButtonStates[MIDDLE] = false;
    }
    if (event.button.button == SDL_BUTTON_RIGHT)
    {
        mouseButtonStates[RIGHT] = false;
    }
}
void InputHandler::onJoystickAxisMove(SDL_Event &event)
{
    if (event.type == SDL_JOYAXISMOTION)
    {
        int joystickIdentifer = event.jaxis.which;
        int jAxis = event.jaxis.axis;
        // Left Stick - Left or Right
        if (jAxis == 0)
        {
            if (event.jaxis.value > joystickDeadZone)
            {
                joystickValues[joystickIdentifer].first->setX(1);
            }
            else if (event.jaxis.value < -joystickDeadZone)
            {
                joystickValues[joystickIdentifer].first->setX(-1);
            }
            else
            {
                joystickValues[joystickIdentifer].first->setX(0);
            }
        }
        // Left stick - Up or Down
        if (jAxis == 1)
        {
            if (event.jaxis.value > joystickDeadZone)
            {
                joystickValues[joystickIdentifer].first->setY(1);
            }
            else if (event.jaxis.value < -joystickDeadZone)
            {
                joystickValues[joystickIdentifer].first->setY(-1);
            }
            else
            {
                joystickValues[joystickIdentifer].first->setY(0);
            }
        }
        // Right Stick - Left or Right
        if (jAxis == 3)
        {
            if (event.jaxis.value > joystickDeadZone)
            {
                joystickValues[joystickIdentifer].second->setX(1);
            }
            else if (event.jaxis.value < -joystickDeadZone)
            {
                joystickValues[joystickIdentifer].second->setX(-1);
            }
            else
            {
                joystickValues[joystickIdentifer].second->setX(0);
            }
        }
        // Right Stick - Up or Down
        if (jAxis == 4)
        {
            if (event.jaxis.value > joystickDeadZone)
            {
                joystickValues[joystickIdentifer].second->setY(1);
            }
            else if (event.jaxis.value < -joystickDeadZone)
            {
                joystickValues[joystickIdentifer].second->setY(-1);
            }
            else
            {
                joystickValues[joystickIdentifer].second->setY(0);
            }
        }
    }
}
void InputHandler::onJoystickButtonDown(SDL_Event &event)
{
    int buttonNumber = event.jaxis.which;
    joystickButtonStates[buttonNumber][event.jbutton.button] = true;
}
void InputHandler::onJoystickButtonUp(SDL_Event &event)
{
    int buttonNumber = event.jaxis.which;
    joystickButtonStates[buttonNumber][event.jbutton.button] = false;
}
