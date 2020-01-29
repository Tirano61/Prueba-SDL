#include "Game.h"
#include <iostream>
#include "TextureManager.h"
#include "GameObjet.h"
#include <list>
#include "Asteride.h"
#include "Nave.h"
#include "Disparo.h"
#include "FabricaObjetos.h"
#include<SDL2/SDL_mixer.h>

using namespace std;



GameObjet* nave;
GameObjet* mapa;

list<GameObjet*> listaBalas;
list<GameObjet*> listaBalasEnemigas;
list<GameObjet*> listEnemigos;
list<GameObjet*> listEnemigos2;



int cantidad = 0;
Game::Game()
{

}

Game::~Game()
{
    Mix_FreeChunk(sfxDisparo);
    Mix_FreeChunk(sfxExplosion);
    Mix_FreeMusic(musica);
    Mix_Quit();
}

void Game::init(const char* title, int xpos, int ypos, int width, int height)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "Iniciado correctamente ..." << endl;
        ventana = SDL_CreateWindow(title, xpos, ypos, width, height,0);
        if(ventana)
        {
            cout << "Ventana creada .. \n";
        }
        tamVentanaX = width;
        tamVentanaY = height;
        renderer = SDL_CreateRenderer(ventana, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer,0,0,0,255);
            cout << "Renderer created ... \n";
            //cout << "Cantidad :" << cantidad <<" \n";
        }

        if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,2048) < 0)
        {
            std::cout << "ERROR AL INICIAR AUDIO \n";
        }
            sfxDisparo = Mix_LoadWAV("music/disparo.ogg");
            sfxExplosion = Mix_LoadWAV("music/explosion.ogg");
            sfxExplosionNave = Mix_LoadWAV("music/explosionNave.ogg");
            musica = Mix_LoadMUS("music/gameloop.ogg");
            Mix_AllocateChannels(4);


        running = true;
    }
    else
    {
        running = false;
    }
    mapa = FabricaObjetos::crearObjetos(FabricaObjetos::MAPA,renderer,NULL,NULL,NULL);
    nave =  FabricaObjetos::crearObjetos(FabricaObjetos::NAVE, renderer,NULL,NULL,NULL);


}

int contador = 0;
int contarEnemigos = 0;
int contarEnemigos1 = 0;
int etapa = 0;
void Game::crearEnemigos()
{
    if(etapa == 0)
    {
        if(contarEnemigos < 9)
        {
            listEnemigos.push_back(FabricaObjetos::crearObjetos(FabricaObjetos::ENEMIGO,renderer,NULL,NULL,NULL));

            contarEnemigos ++;

        }
        if(contarEnemigos1 < 9)
        {
            listEnemigos.push_back(FabricaObjetos::crearObjetos(FabricaObjetos::ENEMIGO,renderer,NULL,NULL,NULL));
            contarEnemigos1 ++;
        }
        if(listEnemigos.size() == 0)
        {
            contador = -50;
            etapa ++;
            contarEnemigos = 0;
            contarEnemigos1 = 0;
        }
    }
    if(etapa == 1)
    {
        if(contarEnemigos < 9)
        {
            listEnemigos.push_back(FabricaObjetos::crearObjetos(FabricaObjetos::ENEMIGO1,renderer,NULL,NULL,NULL));
            contarEnemigos ++;

        }
        if(listEnemigos.size() == 0)
        {
            contador = -50;
            etapa -- ;
            contarEnemigos = 0;
            contarEnemigos1 = 0;
        }
    }


}


void Game::eventos()
{
    while(SDL_PollEvent(&event))
    {

        //Prueba para git

       switch(event.type)
        {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:

                if(keys[SDL_SCANCODE_UP])
                {
                    if(!(nave->desRect.y <= 10)){
                       nave->desRect.y -=  10;
                    }
                }
                if(keys[SDL_SCANCODE_DOWN])
                {
                    if(nave->desRect.y <= (tamVentanaY - 78)){
                       nave->desRect.y +=  10;
                    }
                }
                if(keys[SDL_SCANCODE_RIGHT])
                {
                    if(nave->desRect.x <= (tamVentanaX - 60)){
                      nave->desRect.x +=  10;
                    }
                }
                if(keys[SDL_SCANCODE_LEFT])
                {
                    if(!(nave->desRect.x <= 10)){
                       nave->desRect.x -=  10;
                    }
                }
                if(keys[SDL_SCANCODE_SPACE])
                {
                    if(listaBalas.size() <= 10)
                    {
                        if(nave->getDestruido()==0)
                        {
                            listaBalas.push_back(FabricaObjetos::crearObjetos(FabricaObjetos::BALA,renderer, nave->desRect.x + 25,nave->desRect.y - 10,NULL));
                            Mix_PlayChannel(1,sfxDisparo,0);
                        }
                    }
                }

                break;
            default:
                break;
        }
    }

}


void Game::crearBalaEnemiga()
{
     Mix_PlayChannel(3,sfxExplosionNave,0);
}

void Game::upDate()
{

    if(!Mix_PlayingMusic())
    {
        Mix_PlayMusic(musica,-1);
    }
    mapa->upDate();
    nave->upDate();

    if(contador == 35)
    {
        crearEnemigos();
        contador = 0;
    }

    GameObjet* tempEnemigo;
    GameObjet* tempEnemigo2;
    GameObjet* tempBala;
    GameObjet* tempBalaEnemigas;

    for (list<GameObjet*>::iterator itBalasEnemigas=listaBalasEnemigas.begin(); itBalasEnemigas != listaBalasEnemigas.end(); ++itBalasEnemigas)
    {
        tempBalaEnemigas = *itBalasEnemigas;
        if(nave->getDestruido() == 0)
        {
            if(((nave->desRect.y <= tempBalaEnemigas->desRect.y) || (nave->desRect.y <= tempBalaEnemigas->desRect.y +7)) && ((nave->desRect.y +70 >= tempBalaEnemigas->desRect.y +7) || (nave->desRect.y +70 >= tempBalaEnemigas->desRect.y)))
            {
                if((tempBalaEnemigas->desRect.x + 7 < nave->desRect.x) || (tempBalaEnemigas->desRect.x > nave->desRect.x + 50))
                {
                    tempBalaEnemigas->upDate();
                }
                else
                {
                    listaBalasEnemigas.remove(tempBalaEnemigas);
                    nave->setDestruido(1);
                }
            }
            else
            {
                tempBalaEnemigas->upDate();
            }
        }
        else
        {
            tempBalaEnemigas->upDate();
        }

        if(tempBalaEnemigas->desRect.x >= tamVentanaX || tempBalaEnemigas->desRect.x <= 0 || tempBalaEnemigas->desRect.y <= 0 || tempBalaEnemigas->desRect.y >= tamVentanaY)
        {
            listaBalasEnemigas.remove(*itBalasEnemigas);
            std::cout << "Bala removida \n";
        }
    }


    int bala = 0;
    if(listEnemigos.size() > 0)
    {
        for (list<GameObjet*>::iterator itEnemigo=listEnemigos.begin(); itEnemigo != listEnemigos.end(); ++itEnemigo)
        {
            bala += 5;
            tempEnemigo = *itEnemigo;

            if(tempEnemigo->getDestruido() == 0)
            {
               //std::cout << "ENtro a destruido \n";
                if(nave->getDestruido() == 0)
                {
                    if(((tempEnemigo->desRect.y >= nave->desRect.y) || (tempEnemigo->desRect.y +29 >= nave->desRect.y)) && ((tempEnemigo->desRect.y <= nave->desRect.y +70) || (tempEnemigo->desRect.y +29 <= nave->desRect.y +70)))
                    {
                        if(((tempEnemigo->desRect.x) > (nave->desRect.x + 50)) || ((tempEnemigo->desRect.x + 70) < (nave->desRect.x)))
                        {
                            tempEnemigo->upDate();
                        }
                        else
                        {
                            tempEnemigo->setDestruido(1);
                            nave->setDestruido(1);
                        }
                    }
                    else
                    {
                        if(etapa == 0)
                        {
                            //std::cout << "contarEnemigos : " << contarEnemigos <<"\n";
                            if((tempEnemigo->_numeroEnemigo < 5) && (tempEnemigo->desRect.y >= 150))
                            {
                                if(!tempEnemigo->getDisparado())
                                {
                                   if((tempEnemigo->getEnemigo()) == 1)
                                   {
                                       listaBalasEnemigas.push_back(FabricaObjetos::crearObjetos(FabricaObjetos::BALAENEMIGA,renderer, tempEnemigo->desRect.x , tempEnemigo->desRect.y, 1 ));
                                       tempEnemigo->setDisparado(true);
                                   }else{
                                       listaBalasEnemigas.push_back(FabricaObjetos::crearObjetos(FabricaObjetos::BALAENEMIGA, renderer, tempEnemigo->desRect.x + 70 ,tempEnemigo->desRect.y, 2 ));
                                       tempEnemigo->setDisparado(true);
                                   }
                                }

                            }
                            else
                            {
                                if((tempEnemigo->desRect.y >= 300) && (tempEnemigo->_numeroEnemigo >= 5))
                                {
                                    if(!tempEnemigo->getDisparado())
                                    {
                                       if((tempEnemigo->getEnemigo()) == 1)
                                       {
                                           listaBalasEnemigas.push_back(FabricaObjetos::crearObjetos(FabricaObjetos::BALAENEMIGA,renderer, tempEnemigo->desRect.x , tempEnemigo->desRect.y, 1 ));
                                           tempEnemigo->setDisparado(true);
                                       }else{
                                           listaBalasEnemigas.push_back(FabricaObjetos::crearObjetos(FabricaObjetos::BALAENEMIGA, renderer, tempEnemigo->desRect.x + 70 ,tempEnemigo->desRect.y, 2 ));
                                           tempEnemigo->setDisparado(true);
                                       }
                                    }
                                }
                            }
                        }
                        tempEnemigo->upDate();
                    }
                }
                else
                {
                    tempEnemigo->upDate();
                }

            }

            if(tempEnemigo->desRect.y <= -20 || tempEnemigo->desRect.x <= 0 || tempEnemigo->desRect.x >= tamVentanaX)
            {
                 listEnemigos.remove(*itEnemigo);

                 //break;
            }
        }
    }



    for (list<GameObjet*>::iterator it=listaBalas.begin(); it != listaBalas.end(); ++it)
    {
        tempBala = *it;
        if(listEnemigos.size() > 0)
        {
            for (list<GameObjet*>::iterator itEnemigo=listEnemigos.begin(); itEnemigo != listEnemigos.end(); ++itEnemigo)
            {
                tempEnemigo = *itEnemigo;
                if(tempEnemigo->getDestruido() == 0)
                {
                    if(((tempEnemigo->desRect.y + 29) >= tempBala->desRect.y) && (tempEnemigo->desRect.y) <= (tempBala->desRect.y))
                    {
                        if(!(((tempEnemigo->desRect.x) > (tempBala->desRect.x + 16)) || ((tempEnemigo->desRect.x + 70) < (tempBala->desRect.x))))
                        {
                            listaBalas.remove(*it);
                            tempEnemigo->setDestruido(1);
                            //listEnemigos.remove(tempEnemigo);
                            //break;
                        }
                    }
                }
                if(tempEnemigo->desRect.y <= -20 || tempEnemigo->desRect.x <= 0)
                {
                     listEnemigos.remove(*itEnemigo);
                     //break;
                }
            }

            if(tempEnemigo->getDestruido() == 0)
            {
                if(listEnemigos.size() > 0)
                {
                    if(((tempEnemigo->desRect.y + 29) >= tempBala->desRect.y) && (tempEnemigo->desRect.y) <= (tempBala->desRect.y))
                    {
                        if(((tempEnemigo->desRect.x) > (tempBala->desRect.x + 16)) || ((tempEnemigo->desRect.x + 70) < (tempBala->desRect.x)))
                        {
                            tempBala->upDate();
                        }
                        else
                        {
                            tempEnemigo->setDestruido(1);
                            listaBalas.remove(*it);
                            //break;
                        }
                    }
                    else
                    {
                        tempBala->upDate();
                    }
                }
                else
                {
                    tempBala->upDate();
                }
            }
        }
        else
        {
            tempBala->upDate();
        }
        if(tempBala->desRect.y <= 0 )
        {
             listaBalas.remove(*it);
             //std::cout << "Se remobio BALA  \n";
            // break;
        }

        //numero ++;
    }
    /** contador se utiliza para fabricar los enemigos cada cierto tiempo */
    contador ++;

}

int testThread(void* ptr)
{
       Mix_Chunk* sfxExplosionNave = Mix_LoadWAV("music/explosionNave.ogg");

        Mix_PlayChannel(3,sfxExplosionNave,0);


}
int var;
void Game::render()
{
    SDL_RenderClear(renderer);


    mapa->render();

    if(nave->getDestruido() > 0)
    {
        if(nave->getDestruido()==1)
        {
            var = 0;
             //Mix_PlayMusic(musica,-1);
            Mix_PlayChannel(3,sfxExplosionNave,0);
        }
        nave->render();
        if(nave->getDestruido() == 100)
        {
            nave =  FabricaObjetos::crearObjetos(FabricaObjetos::NAVE, renderer,NULL,NULL,NULL);
        }
    }
    else
    {
        nave->render();
    }



    GameObjet* temp;

    for (list<GameObjet*>::iterator itBalasEnemigas=listaBalasEnemigas.begin(); itBalasEnemigas != listaBalasEnemigas.end(); ++itBalasEnemigas)
    {
        GameObjet* tempBalaEnemigas = *itBalasEnemigas;

        (*itBalasEnemigas)->render();

    }



    for (list<GameObjet*>::iterator it=listaBalas.begin(); it != listaBalas.end(); ++it)
    {
         (*it)->render();
    }
    if(listEnemigos.size() > 0)
    {
        for (list<GameObjet*>::iterator itEnemigo=listEnemigos.begin(); itEnemigo != listEnemigos.end(); ++itEnemigo)
        {
            temp = (*itEnemigo);
            if(temp->getDestruido()> 0)
            {
                if(temp->getDestruido()==1){
                   Mix_PlayChannel(2,sfxExplosion,0);
                }
                (*itEnemigo)->render();
                if(temp->getDestruido() == 37)
                {
                    listEnemigos.remove(*itEnemigo);
                    break;
                }
            }
            else if(temp->getDestruido()== 0)
            {
                (*itEnemigo)->render();
            }
        }
    }

    for (list<GameObjet*>::iterator itEnemigo2=listEnemigos2.begin(); itEnemigo2 != listEnemigos2.end(); ++itEnemigo2)
    {
        (*itEnemigo2)->render();
    }

    SDL_RenderPresent(renderer);
}
void Game::cleam()
{
    SDL_DestroyWindow(ventana);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
bool Game::isRunning()
{
    return running;
}
