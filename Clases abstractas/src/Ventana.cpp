#include "Ventana.h"
#include <iostream>

#include "GameObjet.h"
#include<SDL2/SDL.h>
#include "TextureManager.h"
#include<stdio.h>



Ventana::Ventana(SDL_Renderer* renderer) : GameObjet(renderer)
{
    objTexture = TextureManager::loadTexture("img/mapa2.png",renderer);
    srcRect.w = 800;
    srcRect.h = 300;
    srcRect.x = 0;
    srcRect.y = 5700;
}

Ventana::~Ventana()
{
    //dtor
}

void Ventana::upDate()
{
    if(srcRect.y <= 0)
    {
        srcRect.y = 5700;
    }
    srcRect.y -= velEnemigo*0.02f;
    //std::cout << "Punto y : " << srcRect.y << "\n";
    desRect.w = 1000;
    desRect.h = 800;
    desRect.x = 0;
    desRect.y = 0;



}

void Ventana::render()
{
    SDL_RenderCopy(_renderer,objTexture,&srcRect,&desRect);
}
