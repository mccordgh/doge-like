#define SDL_MAIN_HANDLED

#include "Game.h"

int main()
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    Game::init("Roguelike C++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, false);

    // probably need to write a better gameloop????
    while (Game::isRunning)
    {
        frameStart = SDL_GetTicks();

        Game::handleEvents();
        Game::update();
        Game::draw();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    Game::clean();

    return EXIT_SUCCESS;
}
