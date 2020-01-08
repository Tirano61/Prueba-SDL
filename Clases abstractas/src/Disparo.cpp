#include "Disparo.h"
#include "TextureManager.h"
#include <SDL.h>
#include "GameObjet.h"

Disparo::Disparo(SDL_Renderer* renderer, int xpos, int ypos)
: GameObjet(renderer)
{
    objTexture = TextureManager::loadTexture("img/bala.png",renderer);

    desRect.x = xpos;
    desRect.y = ypos;
}

Disparo::~Disparo()
{
    SDL_DestroyTexture(objTexture);
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
