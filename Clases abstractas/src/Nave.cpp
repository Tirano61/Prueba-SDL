#include "Nave.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Ventana.h"
#include <string>
#include "Bala.h"
#include "TextureManager.h"


Nave::Nave(int tipo, SDL_Renderer* renderer)
: GameObjet(renderer)
{
    _destruido = 0;
    _tipo = tipo;
    objTexture = TextureManager::loadTexture("img/NAVES/nave1.png",renderer);
    explosion = TextureManager::loadTexture("img/explo2.png",renderer);
    desRect.x = xpos = 400;
    desRect.y = ypos = 500;
}

Nave::~Nave()
{
    SDL_DestroyTexture(objTexture);
}

int Nave::getTipo()
{
    return _tipo;
}

void Nave::upDate()
{
    srcRect.h = 170;
    srcRect.w = 158;
    srcRect.x = 0;
    srcRect.y = 0;

    desRect.x;
    desRect.y;
    desRect.w = 50;
    desRect.h = 70;

}

void Nave::render()
{
    if(_destruido > 0)
    {
        srcRect.h = 128;
        srcRect.w = 128;
        if(_destruido <= 3){
            srcRect.x = 0;
            srcRect.y = 0;
        }
        else if((_destruido > 3) && (_destruido <=6)){
            srcRect.x = 128;
            srcRect.y = 0;
        }
        else if((_destruido > 6) && (_destruido <=9)){
            srcRect.x = 256;
            srcRect.y = 0;
        }
        else if((_destruido > 9) && (_destruido <= 12)){
            srcRect.x = 384;
            srcRect.y = 0;
        }
        else if((_destruido > 12) && (_destruido <= 15)){
            srcRect.x = 0;
            srcRect.y = 128;
        }
        else if((_destruido > 15) && (_destruido <= 18)){
            srcRect.x = 128;
            srcRect.y = 128;
        }
        else if((_destruido > 18) && (_destruido <= 21)){
            srcRect.x = 256;
            srcRect.y = 128;
        }
        else if((_destruido > 21) && (_destruido <= 24)){
            srcRect.x = 384;
            srcRect.y = 128;
        }

        else if((_destruido > 24) && (_destruido <= 27)){
            srcRect.x = 0;
            srcRect.y = 256;
        }
        else if((_destruido > 27) && (_destruido <= 30)){
            srcRect.x = 128;
            srcRect.y = 256;
        }
        else if((_destruido > 30) && (_destruido <= 33)){
            srcRect.x = 256;
            srcRect.y = 256;
        }
        else if((_destruido > 33) && (_destruido <= 36)){
            srcRect.x = 384;
            srcRect.y = 256;
        }
        else if((_destruido > 36)){
            srcRect.x = 384;
            srcRect.y = 384;
        }

        desRect.w = 50;
        desRect.h = 50;

        SDL_RenderCopy(_renderer,explosion, &srcRect, &desRect);
        _destruido ++;
    }
    else
    {
       SDL_RenderCopy(_renderer,objTexture, &srcRect, &desRect);
    }
}

void Nave::setDestruido(int destruido)
{
    _destruido = destruido;
}

int Nave::getDestruido()
{
    return _destruido;
}
