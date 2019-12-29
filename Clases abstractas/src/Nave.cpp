#include "Nave.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Ventana.h"
#include <string>
#include "Bala.h"



Nave::Nave(SDL_Renderer *renderer, Bala *bala)
{
    _renderer = renderer;
    _bala = bala;

}

Nave::~Nave()
{

}

void Nave::tamagno(SDL_Rect rect)
{
    naveRect = rect;
    std::cout << "Posision de la Nave : " << naveRect.x << " , " << naveRect.y <<"\n";
}
SDL_Texture *Nave::loadDisparo(){
    SDL_Texture *disparoTexture;
    auto *_dispSurface = IMG_Load("img/bala.png");
    if(_dispSurface){
        disparoTexture = SDL_CreateTextureFromSurface(_renderer, _dispSurface);
        SDL_FreeSurface(_dispSurface);
    }else{
        std::cout << "ERROR surface   ... \n";
    }
    disparoRect.x = naveRect.x + 25;
    disparoRect.y = naveRect.y - 20;
    disparoRect.w = 10;
    disparoRect.h = 20;
    return disparoTexture;
}
void Nave::loadImage()
{
    auto *_surface = IMG_Load("img/nave.png");
    if(_surface){
       _texture = SDL_CreateTextureFromSurface(_renderer,_surface);
        SDL_FreeSurface(_surface);
    }else{
        std::cout << "ERROR surface   ... \n";
    }
}

void Nave::upDate()
{   balaRect.y -= 3;
    SDL_RenderClear(_renderer);

    SDL_RenderCopy(_renderer, _texture, NULL, &naveRect);
    SDL_RenderCopy(_renderer,_bala->_texture, NULL, &balaRect);
    SDL_RenderPresent(_renderer);
}
