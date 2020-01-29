#include "GameObjet.h"
#include<SDL2/SDL.h>
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
int GameObjet::getTipo()
{

}
void GameObjet::setDestruido(int destruido)
{

}
int GameObjet::getDestruido()
{

}
void GameObjet::setDisparado(bool disparado)
{
    _disparado = disparado;
}

bool GameObjet::getDisparado()
{
    return _disparado;
}

int GameObjet::getEnemigo()
{
    return _enemigo;
}
