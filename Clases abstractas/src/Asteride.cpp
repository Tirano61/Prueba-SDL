#include "Asteride.h"
#include <iostream>
#include<SDL.h>
#include<string>
#include"Ventana.h"
#include "GameObjet.h"
#include "TextureManager.h"


Asteride::Asteride(int tipo, SDL_Renderer* renderer, int enemigo)
: GameObjet(renderer)
{
    _destruido = 0;
    _tipo = tipo;
    _enemigo = enemigo;
    objTexture = TextureManager::loadTexture("img/plato.png", renderer);
    objDestruido = TextureManager::loadTexture("img/explosion22.png", renderer);
    if(_enemigo == 1)
    {
        desRect.x = 300;
        desRect.y = 0;

    }else{
        desRect.x = 400;
        desRect.y = 0;

    }

}

Asteride::~Asteride()
{
    SDL_DestroyTexture(objTexture);
    SDL_DestroyTexture(objDestruido);
}

int Asteride::getTipo()
{
   return _tipo;
}

void Asteride::secuencia()
{

}

void Asteride::upDate()
{
    if(_enemigo == 1)
    {
        if(_destruido > 0)
        {
            srcRect.h = 53;
            srcRect.w = 70;
            srcRect.x = 0;
            srcRect.y = 0;

            desRect.w = 70;
            desRect.h = 53;
        }else{
            srcRect.h = 29;
            srcRect.w = 70;
            srcRect.x = 0;
            srcRect.y = 0;

            desRect.w = 70;
            desRect.h = 29;
        }

        if(desRect.y == 400){
           movimiento = 1;
        }else if(desRect.y <= -30 || desRect.x <= -30){
           movimiento = 0;
        }
        if(movimiento == 0){
            desRect.y += velEnemigo;
        }else if(movimiento == 1){
            desRect.y -= velEnemigo;
            desRect.x -= velEnemigo;
        }else if(movimiento == 2){}
    }
    else if(_enemigo == 2)
    {
        if(_destruido > 0)
        {
            srcRect.h = 53;
            srcRect.w = 70;
            srcRect.x = 0;
            srcRect.y = 0;

            desRect.w = 70;
            desRect.h = 53;
        }
        else{

            srcRect.h = 29;
            srcRect.w = 70;
            srcRect.x = 0;
            srcRect.y = 0;

            desRect.w = 70;
            desRect.h = 29;
        }

        if(desRect.y == 400){
           movimiento = 1;
        }else if(desRect.y <= -1 || desRect.x >= 800){
           movimiento = 2;
        }
        if(movimiento == 0){
            desRect.y += velEnemigo;
            //std::cout << "Desplazamiento  : " << desRect.y << std::endl;
        }else if(movimiento == 1){
            desRect.y -= velEnemigo;
            desRect.x += velEnemigo;
        }else if(movimiento == 2){
            if(!desRect.x <= 400){
                desRect.y += velEnemigo;
                desRect.x -= velEnemigo;
            }else{
                desRect.x -= velEnemigo;
            }

        }
    }
}

void Asteride::render()
{
    if(_destruido)
    {
        SDL_RenderCopy(_renderer,objDestruido, &srcRect, &desRect);
        _destruido ++;
    }
    else
    {
       SDL_RenderCopy(_renderer,objTexture, &srcRect, &desRect);
    }

}
void Asteride::setDestruido(int destruido)
{
    _destruido = destruido;
}
int Asteride::getDestruido()
{
    return _destruido;
}
