#include "Enemigo2.h"
#include "math.h"
#include "GameObjet.h"
#include <SDL.h>
#include "TextureManager.h"



Enemigo2::Enemigo2(int tipo, SDL_Renderer* renderer) :
    GameObjet(renderer)
{
    _tipo = tipo;
    objTexture = TextureManager::loadTexture("img/plato2.png", renderer);

    desRect.x = 300;
    desRect.y = 0;

}

Enemigo2::~Enemigo2()
{
    //dtor
}

int Enemigo2::getTipo()
{
    return _tipo;
}

void Enemigo2::upDate()
{
    srcRect.h = 29;
    srcRect.w = 70;
    srcRect.x = 0;
    srcRect.y = 0;

    desRect.w = 70;
    desRect.h = 29;


    float freuencia = 0.01;

    if(movimiento == 0)
    {

        desRect.y += 2;
        desRect.x = (sin(freuencia*desRect.y)*350) + 350;
        if(desRect.y > 570){
            movimiento = 1;
        }

    }
    else if(movimiento == 1){

        desRect.y -= 2;
        desRect.x = -((sin(freuencia*desRect.y)*350)) + 350;
    }


}

void Enemigo2::render()
{
    SDL_RenderCopy(_renderer,objTexture, &srcRect, &desRect);
}

void Enemigo2::setDestruido(int destruido)
{
    _destruido = destruido;
}

int Enemigo2::getDestruido()
{
    return _destruido;
}
