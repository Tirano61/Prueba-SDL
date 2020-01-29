#ifndef BALAENEMIGA_H
#define BALAENEMIGA_H
#include "GameObjet.h"


class BalaEnemiga : public GameObjet
{
    public:
        BalaEnemiga(SDL_Renderer* renderer, int xpos, int ypos,int tipoEnemigo, int tipoBalaEnemiga);
        virtual ~BalaEnemiga();

        void upDate();
        void render();
        int getTipo();
        void setDestruido(int destruido);
        int getDestruido();

    protected:

    private:

        SDL_Texture* objTexture;
        int _tipo;
};

#endif // BALAENEMIGA_H
