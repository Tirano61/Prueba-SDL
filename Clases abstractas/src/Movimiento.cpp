#include "Movimiento.h"
#include <SDL2/SDL.h>
#include"GameObjet.h"

Movimiento::Movimiento(SDL_Renderer* renderer, GameObjet* gameObjet) : GameObjet(renderer)
{
    objeto = gameObjet;
}

Movimiento::~Movimiento()
{
    //dtor
}

void Movimiento::upDate()
{
    objeto->upDate();
}
