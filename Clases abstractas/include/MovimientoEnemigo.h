#ifndef MOVIMIENTOENEMIGO_H
#define MOVIMIENTOENEMIGO_H
#include "GameObjet.h"
#include "Movimiento.h"


class MovimientoEnemigo : public Movimiento
{
    public:
        MovimientoEnemigo(SDL_Renderer* renderer,GameObjet* gameObjet);
        virtual ~MovimientoEnemigo();

        void upDate();


    protected:

    private:
        float freuencia = 0.01;
        float frecuenciaY = 0.01;

};

#endif // MOVIMIENTOENEMIGO_H
