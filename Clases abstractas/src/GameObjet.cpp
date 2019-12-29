#include "GameObjet.h"
#include <SDL2/SDL.h>
#include "TextureManager.h"
#include <iostream>

GameObjet::GameObjet(const char* file, SDL_Renderer* renderer,int x, int y, int tipo,int enemigo)
{
    _renderer = renderer;
    objTexture = TextureManager::loadTexture(file,renderer);
    xpos = desRect.x = x;
    ypos = desRect.y = y;
    _tipo = tipo;
    _enemigo = enemigo;
}

GameObjet::~GameObjet()
{
    SDL_DestroyTexture(objTexture);
}

void GameObjet::upDate()
{
    switch(_tipo)
    {
        case 0:
            srcRect.h = 65;
            srcRect.w = 50;
            srcRect.x = 0;
            srcRect.y = 0;

            desRect.x;
            desRect.y;
            desRect.w = 50;
            desRect.h = 65;
            break;
        case 1:
            if(_enemigo == 1)
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
                }else if(movimiento == 2){

                }
            }else if(_enemigo == 2)
            {
                srcRect.h = 29;
                srcRect.w = 70;
                srcRect.x = 0;
                srcRect.y = 0;

                desRect.w = 70;
                desRect.h = 29;
                if(desRect.y == 400){
                   movimiento = 1;
                }else if(desRect.y <= 0 || desRect.x <= 0){
                   movimiento = 0;
                }
                if(movimiento == 0){
                    desRect.y += velEnemigo;
                }else if(movimiento == 1){
                    desRect.y -= velEnemigo;
                    desRect.x += velEnemigo;
                }else if(movimiento == 2){

                }
            }
            break;
        case 2:
            srcRect.h = 33;
            srcRect.w = 16;
            srcRect.x = 0;
            srcRect.y = 0;
            desRect.w = 7;
            desRect.h = 12;
            desRect.x;
            desRect.y -= velBala;
            break;
    }
}

void GameObjet::render()
{
    SDL_RenderCopy(_renderer,objTexture, &srcRect, &desRect);
}
