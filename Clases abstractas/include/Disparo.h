#ifndef DISPARO_H
#define DISPARO_H
#include <SDL.h>
#include "GameObjet.h"

class Disparo : public GameObjet
{
    public:
        Disparo(int tipo, SDL_Renderer* renderer, int xpos, int ypos);
        virtual ~Disparo();

        void upDate();
        void render();
        int getTipo();
        void setDestruido(int destruido);
        int getDestruido();

    private:
        SDL_Texture* objTexture;
        int _tipo;

};

#endif // DISPARO_H
