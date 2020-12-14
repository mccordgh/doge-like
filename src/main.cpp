#define SDL_MAIN_HANDLED

#include "Manager.h"

Manager* GameManager = new Manager();

Game* game = GameManager->createGame();

int main()
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game->init("Roguelike C++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, false);

    // probably need to write a better gameloop????
    while (game->isRunning)
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->draw();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return EXIT_SUCCESS;
}
