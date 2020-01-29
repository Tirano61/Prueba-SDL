#include "BalaEnemiga.h"
#include "TextureManager.h"
#include "GameObjet.h"
#include <iostream>

BalaEnemiga::BalaEnemiga(SDL_Renderer* renderer, int xpos, int ypos,int tipoEnemigo, int tipoBala)
: GameObjet(renderer)
{
    objTexture = TextureManager::loadTexture("img/balaEnemiga.png",renderer);
    desRect.x = xpos;
    desRect.y = ypos;
    _enemigo = tipoEnemigo;
    _tipoBalaEnemiga = tipoBala;
}

BalaEnemiga::~BalaEnemiga()
{

}

void BalaEnemiga::upDate()
{
    srcRect.h = 14;
    srcRect.w = 14;
    desRect.w = 7;
    desRect.h = 7;

    srcRect.x = 0;
    srcRect.y = 0;


    switch(_tipoBalaEnemiga)
    {
    case 0:
        if(_enemigo == 1)
        {
            desRect.y += velBalaEnemiga;
            desRect.x -= velBalaEnemiga;
            //std::cout << "ENEMIGO 1  \n";
            //std::cout << "TIPO DE BALA 0  \n";
        }else if(_enemigo == 2)
        {
            desRect.y += velBalaEnemiga;
            desRect.x += velBalaEnemiga;
            //std::cout << "ENEMIGO 2  \n";
            //std::cout << "TIPO DE BALA 0  \n";
        }

        break;
    case 1:
        if(_enemigo == 1)
        {
            desRect.y += velBalaEnemiga;
            //desRect.x -= velBalaEnemiga;
            //std::cout << "ENEMIGO 1  \n";
            //std::cout << "TIPO DE BALA 1  \n";
        }else if(_enemigo == 2)
        {
            desRect.y += velBalaEnemiga;
           // desRect.x += velBalaEnemiga;
           //std::cout << "ENEMIGO 2  \n";
           //std::cout << "TIPO DE BALA 1  \n";
        }

        break;
    case 2:
        if(_enemigo == 1)
        {
            desRect.y += velBalaEnemiga;
            desRect.x -= velBalaEnemiga;
            //std::cout << "ENEMIGO 1  \n";
            //std::cout << "TIPO DE BALA 2  \n";
        }else if(_enemigo == 2)
        {
            desRect.y += velBalaEnemiga;
            desRect.x += velBalaEnemiga;
            //std::cout << "ENEMIGO 2  \n";
            //std::cout << "TIPO DE BALA 2  \n";
        }
        ;
        break;
    case 3:
        if(_enemigo == 1)
        {
            desRect.y += velBalaEnemiga;
            desRect.x -= velBalaEnemiga;
            //std::cout << "ENEMIGO 1  \n";
            //std::cout << "TIPO DE BALA 3  \n";
        }else if(_enemigo == 2)
        {
            desRect.y += velBalaEnemiga;
            desRect.x += velBalaEnemiga;
            //std::cout << "ENEMIGO 2  \n";
           //std::cout << "TIPO DE BALA 3  \n";
        }

        break;
    case 4:
        if(_enemigo == 1)
        {
            desRect.y += velBalaEnemiga;
            desRect.x -= velBalaEnemiga;
            //std::cout << "ENEMIGO 1  \n";
           //std::cout << "TIPO DE BALA 4  \n";
        }else if(_enemigo == 2)
        {
            desRect.y += velBalaEnemiga;
            desRect.x += velBalaEnemiga;
            //std::cout << "ENEMIGO 2  \n";
           //std::cout << "TIPO DE BALA 4  \n";
        }

        break;
    case 5:
        if(_enemigo == 1)
        {
            desRect.y += velBalaEnemiga;
            desRect.x -= velBalaEnemiga;
            //std::cout << "ENEMIGO 1  \n";
           //std::cout << "TIPO DE BALA 5  \n";
        }else if(_enemigo == 2)
        {
            desRect.y += velBalaEnemiga;
            desRect.x += velBalaEnemiga;
            //std::cout << "ENEMIGO 2  \n";
           //std::cout << "TIPO DE BALA 5  \n";
        }

        break;
    case 6:
        if(_enemigo == 1)
        {
            desRect.y += velBalaEnemiga;
            desRect.x -= velBalaEnemiga +1;
            //std::cout << "ENEMIGO 1  \n";
            //std::cout << "TIPO DE BALA 6  \n";
        }else if(_enemigo == 2)
        {
            desRect.y += velBalaEnemiga;
            desRect.x += velBalaEnemiga;
            //std::cout << "ENEMIGO 2  \n";
            //std::cout << "TIPO DE BALA 6  \n";
        }

        break;
    case 7:
        if(_enemigo == 1)
        {
            //desRect.y += velBalaEnemiga;
            desRect.x -= velBalaEnemiga;
            //std::cout << "ENEMIGO 1  \n";
            //std::cout << "TIPO DE BALA 7  \n";
        }else if(_enemigo == 2)
        {
            //desRect.y += velBalaEnemiga;
            desRect.x += velBalaEnemiga;
            //std::cout << "ENEMIGO 2  \n";
            //std::cout << "TIPO DE BALA 7  \n";
        }
        break;
        case 8:
        if(_enemigo == 1)
        {
            desRect.y -= velBalaEnemiga;
            desRect.x -= velBalaEnemiga;
            //std::cout << "ENEMIGO 1  \n";
            //std::cout << "TIPO DE BALA 7  \n";
        }else if(_enemigo == 2)
        {
            desRect.y -= velBalaEnemiga +1;
            desRect.x += velBalaEnemiga;
            //std::cout << "ENEMIGO 2  \n";
            //std::cout << "TIPO DE BALA 7  \n";
        }


        break;
    }


   // std::cout << "TIPO DE BALA : " << _tipoBalaEnemiga << "\n";
}

void BalaEnemiga::render()
{
    SDL_RenderCopy(_renderer,objTexture, &srcRect, &desRect);
}

int BalaEnemiga::getTipo()
{

}

void BalaEnemiga::setDestruido(int destruido)
{
    _destruido = destruido;
}

int BalaEnemiga::getDestruido()
{
    return _destruido;
}
