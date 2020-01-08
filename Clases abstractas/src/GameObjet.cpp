#include "GameObjet.h"
#include <SDL.h>
#include "TextureManager.h"
#include <iostream>

GameObjet::GameObjet(SDL_Renderer* renderer)
{

    _renderer = renderer;


}

GameObjet::~GameObjet()
{
    SDL_DestroyTexture(objTexture);
}

void GameObjet::upDate()
{

}

void GameObjet::render()
{
    //SDL_RenderCopy(renderer,objTexture, &srcRect, &desRect);
}
