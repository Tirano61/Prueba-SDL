#ifndef ENEMIGO2_H
#define ENEMIGO2_H
#include "GameObjet.h"

class Enemigo2 : public GameObjet
{
    public:
        Enemigo2(int tipo, SDL_Renderer* renderer);
        virtual ~Enemigo2();

        void upDate();
        void render();
        int getTipo();
        void setDestruido(int destruido);
        int getDestruido();


    protected:

    private:

        int _tipo;
};

#endif // ENEMIGO2_H
