#ifndef FABRICAOBJETOS_H
#define FABRICAOBJETOS_H
#include "GameObjet.h"

class FabricaObjetos
{
    public:
        FabricaObjetos();
        virtual ~FabricaObjetos();

        const static int NAVE = 1;
        const static int BALA = 2;
        const static int ENEMIGO = 3;
        const static int ENEMIGO1 = 4;
        const static int BALAENEMIGA = 5;
        const static int MAPA = 6;

        static int tipoEnemigo;
        static int tipoBala1;
        static int tipoBala2;
        static int numero1;
        static int numero2;

        static GameObjet* crearObjetos(int tipo,SDL_Renderer* renderer,int x,int y,int tipoBalaEnemiga);


    protected:

    private:
};

#endif // FABRICAOBJETOS_H
