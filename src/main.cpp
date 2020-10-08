#include "Game.hpp"

Game *game = nullptr;

int main(int argc, const char * argv[]) {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;
    
    game = new Game();
    game->init("Dogelike C++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, false);
    
    // probably need to write a better gameloop????
    while (game->running())
    {
        frameStart = SDL_GetTicks();
        
        game->handleEvents();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    game->clean();
    delete game;
    
    return 0;
}
