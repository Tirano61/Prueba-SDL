#include "Nave.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Ventana.h"
#include <string>
#include "Bala.h"
#include "TextureManager.h"


Nave::Nave(SDL_Renderer* renderer)
: GameObjet(renderer)
{
    objTexture = TextureManager::loadTexture("img/nave1.png",renderer);


    desRect.x = xpos = 400;
    desRect.y = ypos = 500;
}

Nave::~Nave()
{
    SDL_DestroyTexture(objTexture);
}
void Nave::upDate()
{
    srcRect.h = 65;
    srcRect.w = 50;
    srcRect.x = 0;
    srcRect.y = 0;

    desRect.x;
    desRect.y;
    desRect.w = 50;
    desRect.h = 65;

}

void Nave::render()
{
    SDL_RenderCopy(_renderer,objTexture, &srcRect, &desRect);
}

