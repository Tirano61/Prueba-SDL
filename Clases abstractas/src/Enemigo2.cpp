#include "Enemigo2.h"
#include "math.h"
#include "GameObjet.h"
#include<SDL2/SDL.h>
#include "TextureManager.h"



Enemigo2::Enemigo2(int tipo, SDL_Renderer* renderer) :
    GameObjet(renderer)
{
    _destruido = 0;
    _tipo = tipo;
    objTexture = TextureManager::loadTexture("img/plato2.png", renderer);
    objDestruido = TextureManager::loadTexture("img/explo1.png", renderer);
    objExplosion = TextureManager::loadTexture("img/explosion.png", renderer);
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
    desRect.w = 62;
    desRect.h = 21;

    float freuencia = 0.01;

    if(movimiento == 0)
    {

        desRect.y += 2;
        desRect.x = (sin(freuencia*desRect.y)*200) + 400;
        if(desRect.y > 570){
            movimiento = 1;
        }

    }
    else if(movimiento == 1){

        desRect.y -= 2;
        desRect.x = -((sin(freuencia*desRect.y)*200)) + 400;
    }


}

void Enemigo2::render()
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
        desRect.w = 70;
        desRect.h = 40;

        SDL_RenderCopy(_renderer,objDestruido, &srcRect, &desRect);
        _destruido ++;
    }
    else
    {
       SDL_RenderCopy(_renderer,objTexture, &srcRect, &desRect);
    }

}

void Enemigo2::setDestruido(int destruido)
{
    _destruido = destruido;
}

int Enemigo2::getDestruido()
{
    return _destruido;
}
