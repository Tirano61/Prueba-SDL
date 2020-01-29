#ifndef ASTERIDE_H
#define ASTERIDE_H
#include<SDL2/SDL.h>
#include"Personaje.h"
#include<SDL2/SDL_image.h>
#include<string>
#include<random>
#include "GameObjet.h"



class Asteride : public GameObjet
{
    public:
        Asteride(int tipo, SDL_Renderer* renderer, int enemigo, int numero) ;
        virtual ~Asteride();

        void secuencia();
        void upDate();
        void render();
        int getTipo();
        void setDestruido(int destruido);
        int getDestruido();
        bool getDisparado();
        void setDisparado(bool disparado);
        int getEnemigo();


    protected:

    private:
    SDL_Texture* objTexture;
    SDL_Texture* objDestruido;
    SDL_Texture* objExplosion;
    int _tipo = 0;
    float freuencia = 0.01;
    float frecuenciaY = 0.01;
    int contador = 0;
    int contador2 = 0;
    //int _enemigo = 0;

};

#endif // ASTERIDE_H
