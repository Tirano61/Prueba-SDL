#ifndef NAVE_H
#define NAVE_H
#include "GameObjet.h"
#include<SDL.h>
#include "Bala.h"
void upDate();


class Nave : public GameObjet
{
    public:
        Nave(SDL_Renderer* renderer);
        virtual ~Nave();

        void upDate();
        void render();

    protected:

    private:
    SDL_Texture* objTexture;

};

#endif // NAVE_H
