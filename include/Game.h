#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    virtual ~Game();

    // simply set the running variable to true
    void init()
    {
        isRunning = true;
    }

protected:
private:
    bool isRunning;
};

#endif // GAME_H
