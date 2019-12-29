#ifndef NAVE_H
#define NAVE_H
#include"Personaje.h"
#include<SDL2/SDL.h>
#include "Bala.h"



class Nave : public Personaje{
    public:
        Nave(SDL_Renderer *renderer, Bala *bala);
        virtual ~Nave();
        void tamagno(SDL_Rect rect);
        void loadImage();
        void upDate();
        SDL_Texture *loadDisparo();


        SDL_Rect naveRect,balaRect;
        SDL_Rect disparoRect;
        Bala *_bala;
    protected:

    private:

        SDL_Texture *_disparoTexture;
        SDL_Texture *_texture;
        SDL_Renderer *_renderer = nullptr;
        int _x,_y,_w,_h;
};

#endif // NAVE_H
