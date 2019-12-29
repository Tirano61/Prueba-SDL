#ifndef CONTROL_H
#define CONTROL_H
#include"Nave.h"
#include"Bala.h"


class Control
{
    public:
        Control(Nave *nave,Bala *bala);
        virtual ~Control();
        void controlarNave();
        bool salir();
    protected:

    private:
        Bala *_bala;
        Nave *_nave;
        SDL_Event event;
        int x, y;
        bool _running = true;
        const Uint8 *keys =  SDL_GetKeyboardState(NULL);

};

#endif // CONTROL_H
