#ifndef BALA_H
#define BALA_H
#include "Personaje.h"
#include <SDL2/SDL.h>



class Bala :Personaje
{
    public:
        Bala(SDL_Renderer *renderer,SDL_Rect *rect);
        virtual ~Bala();
        void loadImage();
        void tamagno(SDL_Rect rect);
        void mover(SDL_Rect *rect);
        void update();

        SDL_Rect *_balaRect;
        SDL_Texture *_texture;
    protected:

    private:

        SDL_Renderer *_renderer;

};

#endif // BALA_H
