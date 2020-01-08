#ifndef PERSONAJE_H
#define PERSONAJE_H
#include<SDL.h>
#include<string>
#include"Ventana.h"
#include<iostream>


class Personaje
{
    public:
        virtual void tamagno(SDL_Rect rect) = 0;
        virtual void loadImage() = 0;

    protected:
        SDL_Renderer *_renderer;
        SDL_Window *_window;
        SDL_Rect *_rect;
    private:

};

#endif // PERSONAJE_H
