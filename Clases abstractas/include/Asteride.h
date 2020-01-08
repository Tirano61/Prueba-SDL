#ifndef ASTERIDE_H
#define ASTERIDE_H
#include<SDL.h>
#include"Personaje.h"
#include<SDL_image.h>
#include<string>
#include<random>
#include "GameObjet.h"



class Asteride : public GameObjet
{
    public:
        Asteride(SDL_Renderer* renderer, int tipo) ;
        virtual ~Asteride();

        void secuencia();
        void upDate();
        void render();

    protected:

    private:
    SDL_Texture* objTexture;
    int _tipo = 0;
};

#endif // ASTERIDE_H
