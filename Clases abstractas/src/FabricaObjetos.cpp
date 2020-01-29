#include "FabricaObjetos.h"
#include "GameObjet.h"
#include "Nave.h"
#include "Disparo.h"
#include "Asteride.h"
#include "Game.h"
#include "Enemigo2.h"
#include "BalaEnemiga.h"
#include "MovimientoEnemigo.h"

int FabricaObjetos::tipoEnemigo = 0;
int FabricaObjetos::tipoBala1 = 0;
int FabricaObjetos::tipoBala2 = 0;
int FabricaObjetos::numero1 = 0;
int FabricaObjetos::numero2 = 0;
FabricaObjetos::FabricaObjetos()
{
    //ctor
}

FabricaObjetos::~FabricaObjetos()
{
    //dtor
}

GameObjet* FabricaObjetos::crearObjetos(int tipo, SDL_Renderer* _renderer,int x,int y,int tipoBalaEnemiga)
{

    GameObjet* objeto = nullptr;
    switch(tipo)
    {
        case NAVE:
            objeto = new Nave(tipo, _renderer);
            break;

        case BALA:
            objeto = new Disparo(tipo,_renderer,x,y);
            break;

        case ENEMIGO:
            if (tipoEnemigo == 0)
            {
                tipoEnemigo = 1;
                objeto = new Asteride(tipo,_renderer, 1, numero1);

                numero1 ++;
            }
            else if(tipoEnemigo == 1)
            {
                objeto = new Asteride(tipo,_renderer, 2, numero2);

                //objeto = new MovimientoEnemigo(_renderer,objeto);
                tipoEnemigo = 0;
                numero2 ++;
            }
            if(numero1 == 9)
            {
                numero1 = 0;
            }
            if(numero2 == 9)
            {
                numero2 = 0;
            }
            break;

        case ENEMIGO1:
            objeto = new Enemigo2(tipo,_renderer);
            break;

        case BALAENEMIGA:

            if(tipoBalaEnemiga == 1)
            {
                objeto = new BalaEnemiga(_renderer, x, y, tipoBalaEnemiga, tipoBala1);
                tipoBala1 ++;
            }else{
                objeto = new BalaEnemiga(_renderer, x, y, tipoBalaEnemiga, tipoBala2);
                tipoBala2 ++;
            }
            if(tipoBala1 == 9)
            {
                tipoBala1 = 0;
            }
            if(tipoBala2 == 9)
            {
                tipoBala2 = 0;
            }
            break;
        case MAPA:
            objeto = new Ventana(_renderer);
    }

    return objeto;
}

