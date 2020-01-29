#ifndef NAVE_H
#define NAVE_H
#include "GameObjet.h"
#include<SDL2/SDL.h>
#include "Bala.h"
void upDate();


class Nave : public GameObjet
{
    public:
        Nave(int tipo, SDL_Renderer* renderer);
        virtual ~Nave();

        void upDate();
        void render();
        int getTipo();
        void setDestruido(int destruido);
        int getDestruido();

    protected:

    private:
    SDL_Texture* objTexture;
    SDL_Texture* explosion;
    int _tipo;


};

#endif // NAVE_H
