#include "Asteride.h"
#include <iostream>
#include<SDL2/SDL.h>
#include<string>
#include"Ventana.h"
#include "GameObjet.h"
#include "TextureManager.h"


Asteride::Asteride(int tipo, SDL_Renderer* renderer, int enemigo, int numero)
: GameObjet(renderer)
{
    _destruido = 0;
    //_enemigo = enemigo;
    _tipo = tipo;
    _enemigo = enemigo;
    _numeroEnemigo = numero;
    //std::cout << numero << "\n";
    objTexture = TextureManager::loadTexture("img/NAVES/nave9b.png", renderer);
    objDestruido = TextureManager::loadTexture("img/NAVES/nave9b.png", renderer);
    objExplosion = TextureManager::loadTexture("img/explo.png", renderer);
    if(_enemigo == 1)
    {
        srcRect.w = 110;
        srcRect.h = 120;
        srcRect.x = 0;
        srcRect.y = 0;

        desRect.w = 50;
        desRect.h = 60;
        desRect.x = 470;
        desRect.y = 0;


    }else{
        srcRect.w = 110;
        srcRect.h = 120;
        srcRect.x = 0;
        srcRect.y = 0;

        desRect.w = 50;
        desRect.h = 60;
        desRect.x = 530;
        desRect.y = 0;

    }

}

Asteride::~Asteride()
{
    SDL_DestroyTexture(objTexture);
    SDL_DestroyTexture(objDestruido);
    SDL_DestroyTexture(objExplosion);
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
        srcRect.w = 110;
        srcRect.h = 110;
        srcRect.x = 110;
        srcRect.y = 0;

        desRect.w = 45;
        desRect.h = 45;

        if(desRect.y == 450){
           movimiento = 1;
        }else if(desRect.y <= -30 || desRect.x <= -30){
           movimiento = 0;
        }
        if(movimiento == 0){

            desRect.y += velEnemigo ;

        }else if(movimiento == 1){
            freuencia += 0.02;
            contador2 ++;

            srcRect.x = 440;
            srcRect.y = 110;
            if(contador2 > 30 && contador2 < 61){
                srcRect.x = 330;
                srcRect.y = 0;
            }else if(contador2 > 60 && contador2 < 91){
                srcRect.x = 220;
                srcRect.y = 110;
            }else if(contador2 > 90 && contador2 < 121){
                srcRect.x = 550;
                srcRect.y = 0;
            }else if(contador2 > 120 && contador2 < 151 ){
                srcRect.x =0;
                srcRect.y =110;
            }else if(contador2 > 150){
                srcRect.x =0;
                srcRect.y =0;
            }

            desRect.y += velEnemigo - freuencia;
            desRect.x -= velEnemigo;
        }else if(movimiento == 2){}
    }
    else if(_enemigo == 2){
        srcRect.w = 110;
        srcRect.h = 110;
        srcRect.x = 110;
        srcRect.y = 0;

        desRect.w = 45;
        desRect.h = 45;

        if(desRect.y == 450){
           movimiento = 1;
        }else if(desRect.y <= -1 || desRect.x >= 800){
           //movimiento = 2;
        }
        if(movimiento == 0){
            desRect.y += velEnemigo ;
            desRect.x ;
        }else if(movimiento == 1){
            srcRect.x = 550;
            srcRect.y = 110;
            frecuenciaY += 0.02;
            contador ++;
            if(contador > 30 && contador < 61){
                srcRect.x = 440;
                srcRect.y = 0;
            }else if(contador > 60 && contador < 91){
                srcRect.x = 330;
                srcRect.y = 110;
            }else if(contador > 90 && contador < 121){
                srcRect.x = 660;
                srcRect.y = 0;
            }else if(contador > 120 && contador < 151){
                srcRect.x = 110;
                srcRect.y = 110;
            }else if(contador > 150){
                srcRect.x = 220;
                srcRect.y = 0;
            }

            desRect.y += velEnemigo - frecuenciaY;
            desRect.x += velEnemigo ;
            std::cout << "velEnemigo - frecuenciaY : ...:" << frecuenciaY << "\n";
        }
    }
}

void Asteride::render()
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
        desRect.w = 50;
        desRect.h = 50;

        SDL_RenderCopy(_renderer,objExplosion, &srcRect, &desRect);
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

bool Asteride::getDisparado()
{
    return _disparado;
}

void Asteride::setDisparado(bool disparado)
{
    _disparado = disparado;
}
int Asteride::getEnemigo()
{
    return _enemigo;
}
