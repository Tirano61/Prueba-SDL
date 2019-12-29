#include "Asteride.h"
#include <iostream>
#include<SDL2/SDL.h>
#include<string>
#include"Ventana.h"


Asteride::Asteride()
{
    //ctor
}

Asteride::~Asteride()
{
    //dtor
}

void Asteride::tamagno(SDL_Rect rect){

    asteroideRect = rect;

    std::cout << "Posision del Asteroide : " << asteroideRect.x << " , " << asteroideRect.y <<"\n";
}

void Asteride::loadImage(){
   /* SDL_Surface *_surface = IMG_Load("img/plato.png");
    _texture = SDL_CreateTextureFromSurface(ventana._renderer,_surface);
    SDL_FreeSurface(_surface);*/
}
