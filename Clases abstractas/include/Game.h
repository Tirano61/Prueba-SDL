#ifndef GAME_H
#define GAME_H
#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "GameObjet.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height);
        void eventos();

        void upDate();
        void render();
        void cleam();
        void crearEnemigos();
        void crearBalaEnemiga();
       // int testThread(void* ptr);

        bool isRunning();
        SDL_Renderer* renderer;
    protected:

    private:
        int cnt = 0;
        bool running;
        SDL_Window* ventana;
        Mix_Chunk* sfxDisparo;
        Mix_Chunk* sfxExplosion;
        Mix_Chunk* sfxExplosionNave;
        Mix_Music * musica;
        const Uint8 *keys =  SDL_GetKeyboardState(NULL);
        SDL_Event event;
        SDL_Event NaveEvent;
        SDL_Thread* _thread;
        int tamVentanaX, tamVentanaY;
};

#endif // GAME_H
