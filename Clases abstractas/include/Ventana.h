#ifndef VENTANA_H
#define VENTANA_H
#include<SDL2/SDL.h>
#include "GameObjet.h"


class Ventana : public GameObjet
{
    public:
        Ventana(SDL_Renderer* renderer);
        virtual ~Ventana();
        void upDate();
        void render();

    protected:

    private:

        SDL_Texture* objTexture;

};

#endif // VENTANA_H
