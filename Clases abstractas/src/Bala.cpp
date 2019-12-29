#include "Bala.h"
#include<SDL.h>
#include<SDL_image.h>



Bala::Bala(SDL_Renderer *renderer, SDL_Rect *rect)
{
    _renderer = renderer;
    _balaRect = rect;
    _balaRect->w = 10;
    _balaRect->h = 20;
}

Bala::~Bala()
{

}

void Bala::loadImage(){
    auto *_surface = IMG_Load("img/bala.png");
    if(_surface){
       _texture = SDL_CreateTextureFromSurface(_renderer,_surface);
        SDL_FreeSurface(_surface);
    }else{
        std::cout << "ERROR surface   ... \n";
    }
}

void Bala::tamagno(SDL_Rect rect){

}
void Bala::update(){
    _balaRect->y -= 3;
    SDL_RenderClear(_renderer);
    SDL_RenderCopy(_renderer, _texture, NULL, _balaRect);
    SDL_RenderPresent(_renderer);
}

void Bala::mover(SDL_Rect *rect){
    Personaje::_rect->w = 10;
   rect->y -= 3;
}

