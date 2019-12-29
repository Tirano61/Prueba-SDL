#ifndef ASTERIDE_H
#define ASTERIDE_H
#include<SDL2/SDL.h>
#include"Personaje.h"
#include<SDL2/SDL_image.h>
#include<string>



class Asteride : public Personaje{
    public:
        Asteride();
        virtual ~Asteride();
        void tamagno(SDL_Rect rect);
        void loadImage();
    protected:

    private:
        SDL_Rect asteroideRect;
        SDL_Texture *_texture;
        int _x,_y,_w,_h;
};

#endif // ASTERIDE_H
