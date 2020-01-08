#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <SDL_image.h>


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

        bool isRunning();
        SDL_Renderer* renderer;
    protected:

    private:
        int cnt = 0;
        bool running;
        SDL_Window* ventana;

        const Uint8 *keys =  SDL_GetKeyboardState(NULL);
        SDL_Event event;
};

#endif // GAME_H
