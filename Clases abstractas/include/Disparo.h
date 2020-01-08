#ifndef DISPARO_H
#define DISPARO_H
#include <SDL.h>
#include "GameObjet.h"

class Disparo : public GameObjet
{
    public:
        Disparo(SDL_Renderer* renderer, int xpos, int ypos);
        virtual ~Disparo();

        void upDate();
        void render();

    private:
        SDL_Texture* objTexture;
};

#endif // DISPARO_H
