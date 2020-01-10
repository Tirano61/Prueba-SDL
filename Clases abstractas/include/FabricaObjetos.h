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

        static int tipoEnemigo;



        static GameObjet* crearObjetos(int tipo,SDL_Renderer* renderer,int x,int y);


    protected:

    private:
};

#endif // FABRICAOBJETOS_H
