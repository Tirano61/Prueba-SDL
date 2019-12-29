#include "Control.h"
#include "Nave.h"
#include <iostream>
#include "Bala.h"




Control::Control(Nave *nave, Bala *bala)
{
    _nave = nave;
    _bala = bala;
}

Control::~Control()
{
    //dtor
}
bool Control::salir(){
    return _running;
}
void Control::controlarNave(){

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_KEYDOWN){
           if(keys[SDL_SCANCODE_RIGHT]){
                _nave->naveRect.x += 10;
            }
            if(keys[SDL_SCANCODE_LEFT]){
                _nave->naveRect.x -= 10;
            }
            if(keys[SDL_SCANCODE_UP]){
                _nave->naveRect.y -= 10;
            }
            if(keys[SDL_SCANCODE_DOWN]){
                _nave->naveRect.y += 10;
            }
            if(keys[SDL_SCANCODE_ESCAPE]){
                _running = false;
                std::cout << " Presiono la tecla \n";
            }
            if(keys[SDL_SCANCODE_SPACE]){

                _nave->_bala->loadImage();

            }
        }


    }

}
