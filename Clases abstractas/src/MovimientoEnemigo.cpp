#include "MovimientoEnemigo.h"
#include "math.h"
#include "GameObjet.h"
#include "TextureManager.h"
#include "Movimiento.h"

MovimientoEnemigo::MovimientoEnemigo(SDL_Renderer* renderer,GameObjet* gameObjet) : Movimiento(renderer,gameObjet)
{
    _destruido = 0;
}

MovimientoEnemigo::~MovimientoEnemigo()
{
    //dtor
}

void MovimientoEnemigo::upDate()
{
    Movimiento::upDate();

    if(_enemigo == 1)
    {
        srcRect.w = 110;
        srcRect.h = 110;
        srcRect.x = 110;
        srcRect.y = 0;
        desRect.w = 45;
        desRect.h = 45;

        if(desRect.y >= 400){
           movimiento = 1;
           freuencia = 0.01;
        }else if(desRect.y <= -30 || desRect.x <= -30){
           movimiento = 0;
        }
        if(movimiento == 0){

            freuencia += 0.017;
            desRect.y -= cos(velEnemigo*(2*3.14/10)*2)*freuencia;
            desRect.x += (velEnemigo*(2*3.14/10)*2);


        }else if(movimiento == 1){
            srcRect.x = 0;
            freuencia -= 0.017;
            frecuenciaY += 0.01;
            //desRect.y += 2;
          //  desRect.x = -((sin(freuencia*desRect.y)*300) );
            desRect.y -= velEnemigo *freuencia;
            desRect.x -= velEnemigo * freuencia;
        }else if(movimiento == 2){}
    }
    else if(_enemigo == 2)
    {

        srcRect.w = 110;
        srcRect.h = 110;
        srcRect.x = 110;
        srcRect.y = 0;

        desRect.w = 45;
        desRect.h = 45;


        if(desRect.y == 400){
           movimiento = 1;
        }else if(desRect.y <= -1 || desRect.x >= 800){
           //movimiento = 2;
        }
        if(movimiento == 0){
            freuencia += 0.011;
            desRect.y += velEnemigo ;
            desRect.x -= velEnemigo * freuencia;

            //desRect.y += velEnemigo;
            //std::cout << "Desplazamiento  : " << desRect.y << std::endl;
        }else if(movimiento == 1){

            freuencia -= 0.01;
            frecuenciaY += 0.01;
            //desRect.y += 2;
            //  desRect.x = -((sin(freuencia*desRect.y)*300) );
            desRect.y -= velEnemigo - frecuenciaY;
            desRect.x += velEnemigo * freuencia;

            //desRect.y -= velEnemigo;
            //desRect.x += velEnemigo;
            srcRect.x = 220;
        }else if(movimiento == 2){
            if(!(desRect.x <= 400)){
                srcRect.x = 220;
                srcRect.x = 0;
            freuencia -= 0.01;
            frecuenciaY += 0.01;
            //desRect.y += 2;
          //  desRect.x = -((sin(freuencia*desRect.y)*300) );
            desRect.y -= velEnemigo - frecuenciaY;
            desRect.x += velEnemigo * freuencia;

                //desRect.y += velEnemigo;
                //desRect.x -= velEnemigo;
            }else{
                desRect.x -= velEnemigo;
            }
        }
    }
}


