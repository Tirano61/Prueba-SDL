#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include"GameObjet.h"

class Movimiento : public GameObjet
{
    public:
        Movimiento(SDL_Renderer* renderer, GameObjet* gameObjet);
        virtual ~Movimiento();

        void upDate();
    protected:
        GameObjet* objeto;
    private:
};

#endif // MOVIMIENTO_H
