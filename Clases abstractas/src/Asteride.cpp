#include "Asteride.h"
#include <iostream>
#include<SDL.h>
#include<string>
#include"Ventana.h"
#include "GameObjet.h"
#include "TextureManager.h"


Asteride::Asteride(SDL_Renderer* renderer, int tipo)
: GameObjet(renderer)
{
    _tipo = tipo;
    objTexture = TextureManager::loadTexture("img/plato.png", renderer);
    if(_tipo == 1)
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
}

void Asteride::secuencia()
{

}

void Asteride::upDate()
{
    if(_tipo == 1)
    {
       srcRect.h = 29;
        srcRect.w = 70;
        srcRect.x = 0;
        srcRect.y = 0;

        desRect.w = 70;
        desRect.h = 29;
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
    else if(_tipo == 2)
    {
        srcRect.h = 29;
        srcRect.w = 70;
        srcRect.x = 0;
        srcRect.y = 0;

        desRect.w = 70;
        desRect.h = 29;
        if(desRect.y == 400){
           movimiento = 1;
        }else if(desRect.y <= -30 || desRect.x >= 800){
           movimiento = 2;
        }
        if(movimiento == 0){
            desRect.y += velEnemigo;
            //std::cout << "Desplazamiento  : " << desRect.y << std::endl;
        }else if(movimiento == 1){
            desRect.y -= velEnemigo;
            desRect.x += velEnemigo;
        }else if(movimiento == 2){

        }
    }
}

void Asteride::render()
{
    SDL_RenderCopy(_renderer,objTexture, &srcRect, &desRect);
}
