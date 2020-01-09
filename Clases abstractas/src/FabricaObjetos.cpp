#include "FabricaObjetos.h"
#include "GameObjet.h"
#include "Nave.h"
#include "Disparo.h"
#include "Asteride.h"
#include "Game.h"
#include "Enemigo2.h"

int FabricaObjetos::tipoEnemigo = 0;
FabricaObjetos::FabricaObjetos()
{
    //ctor
}

FabricaObjetos::~FabricaObjetos()
{
    //dtor
}

GameObjet* FabricaObjetos::crearObjetos(int tipo, SDL_Renderer* _renderer)
{

    GameObjet* objeto = nullptr;
    switch(tipo)
    {
        case NAVE:
            objeto = new Nave(_renderer);
            break;
        case BALA:
            break;
        case ENEMIGO:
            if (tipoEnemigo == 0)
            {
                tipoEnemigo = 1;
                objeto = new Asteride(_renderer, 1);
            }
            else if(tipoEnemigo == 1)
            {
                objeto = new Asteride(_renderer, 2);
                tipoEnemigo = 0;
            }
            break;
        case ENEMIGO1:
            objeto = new Enemigo2(_renderer);
            break;
            }

    return objeto;
}
