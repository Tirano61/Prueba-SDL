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
        Asteride(int tipo, SDL_Renderer* renderer, int enemigo) ;
        virtual ~Asteride();

        void secuencia();
        void upDate();
        void render();
        int getTipo();
        void setDestruido(int destruido);
        int getDestruido();

    protected:

    private:
    SDL_Texture* objTexture;
    SDL_Texture* objDestruido;
    int _tipo = 0;
    int _enemigo = 0;

};

#endif // ASTERIDE_H
