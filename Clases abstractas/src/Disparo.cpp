#include "Disparo.h"
#include "TextureManager.h"
#include <SDL.h>
#include "GameObjet.h"

Disparo::Disparo(int tipo, SDL_Renderer* renderer, int xpos, int ypos)
: GameObjet(renderer)
{
    _destruido = false;
    _tipo = tipo;
    objTexture = TextureManager::loadTexture("img/bala.png",renderer);

    desRect.x = xpos;
    desRect.y = ypos;
}

Disparo::~Disparo()
{
    SDL_DestroyTexture(objTexture);
}

int Disparo::getTipo()
{
    return _tipo;
}

void Disparo::upDate()
{
    srcRect.h = 33;
    srcRect.w = 16;
    srcRect.x = 0;
    srcRect.y = 0;
    desRect.w = 7;
    desRect.h = 12;
    desRect.y -= velBala;
}

void Disparo::render()
{
   SDL_RenderCopy(_renderer,objTexture, &srcRect, &desRect);
}

void Disparo::setDestruido(int destruido)
{
    _destruido = destruido;
}
int Disparo::getDestruido()
{
    return _destruido;
}
