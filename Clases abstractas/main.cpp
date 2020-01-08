#include<iostream>
#include"Nave.h"
#include"Asteride.h"
#include <SDL.h>
#include"Control.h"
#include"Game.h"


Game *game = nullptr;
int main(int  argc, char *argv[]){

    const int FPS = 60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("Prueba 1",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600);

    while(game->isRunning())
    {
        frameStart = SDL_GetTicks();

        game->eventos();

        game->upDate();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->cleam();

    return 0;
}
