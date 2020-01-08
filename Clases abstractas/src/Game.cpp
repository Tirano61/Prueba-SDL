#include "Game.h"
#include <iostream>
#include "TextureManager.h"
#include "GameObjet.h"
#include <list>
#include "Asteride.h"
#include "Nave.h"
#include "Disparo.h"
#include "FabricaObjetos.h"

using namespace std;



GameObjet* nave;

list<GameObjet*> listaBalas;
list<GameObjet*> listEnemigos;
list<GameObjet*> listEnemigos2;
//list<GameObjet*>
GameObjet* enemigo;
int cantidad = 0;
Game::Game()
{

}

Game::~Game()
{

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
        renderer = SDL_CreateRenderer(ventana, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            cout << "Renderer created ... \n";
            //cout << "Cantidad :" << cantidad <<" \n";
        }
        running = true;
    }
    else
    {
        running = false;
    }
    nave =  FabricaObjetos::crearObjetos(FabricaObjetos::NAVE, renderer);


}
void Game::crearEnemigos()
{
    if(listEnemigos.size() < 9)
    {
        listEnemigos.push_back(FabricaObjetos::crearObjetos(FabricaObjetos::ENEMIGO,renderer));
    }
    if(listEnemigos2.size() < 9)
    {
        listEnemigos.push_back(FabricaObjetos::crearObjetos(FabricaObjetos::ENEMIGO,renderer));
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
                if(keys[SDL_SCANCODE_SPACE])
                {
                    if(listaBalas.size() <= 10)
                    {
                        listaBalas.push_back(new Disparo(renderer, nave->desRect.x + 25,nave->desRect.y - 10));
                        std::cout << "Se agrego un aBala A la LISta \n";
                    }
                }
                if(keys[SDL_SCANCODE_UP])
                {
                    if(!(nave->desRect.y <= 10)){
                       nave->desRect.y -=  12;
                    }
                }
                if(keys[SDL_SCANCODE_DOWN])
                {
                    if(nave->desRect.y <= (600 - 78)){
                       nave->desRect.y +=  12;
                    }
                }
                if(keys[SDL_SCANCODE_RIGHT])
                {
                    if(nave->desRect.x <= (800 - 60)){
                      nave->desRect.x +=  12;
                    }
                }
                if(keys[SDL_SCANCODE_LEFT])
                {
                    if(!(nave->desRect.x <= 10)){
                       nave->desRect.x -=  12;
                    }
                }

                break;
            default:
                break;
        }
    }

}
int contador = 0;
void Game::upDate()
{

    nave->upDate();

    int numero = 1;
    for (list<GameObjet*>::iterator it=listaBalas.begin(); it != listaBalas.end(); ++it)
    {
        GameObjet* temp = *it;
        temp->upDate();
        std::cout << "Se HIZO UPDATE A UNA BALA "  << numero << "\n";
        if(temp->desRect.y <= 0)
        {
             listaBalas.remove(*it);
             std::cout << "Se remobio BALA  \n";
             break;
        }
        numero ++;
    }

    if(contador == 25)
    {
        crearEnemigos();
        contador = 0;
    }

    for (list<GameObjet*>::iterator itEnemigo=listEnemigos.begin(); itEnemigo != listEnemigos.end(); ++itEnemigo)
    {
        GameObjet* tempEnemigo = *itEnemigo;
        if((tempEnemigo->desRect.y + 29) >= nave->desRect.y)
        {
            if(((tempEnemigo->desRect.x) > (nave->desRect.x + 60)) || ((tempEnemigo->desRect.x + 70) < (nave->desRect.x)))
            {
                tempEnemigo->upDate();
            }else{
                listEnemigos.remove(*itEnemigo);
                std::cout << "Choco con enemigo \n ";
                break;
            }
        }
        else
        {
            tempEnemigo->upDate();
        }

        if(tempEnemigo->desRect.y <= -10 || tempEnemigo->desRect.x <= -10)
        {
             listEnemigos.remove(*itEnemigo);
             //std::cout << "Enemigo eliminado \n ";
             break;
        }
    }


    for (list<GameObjet*>::iterator itEnemigo2=listEnemigos2.begin(); itEnemigo2 != listEnemigos2.end(); ++itEnemigo2)
    {
        GameObjet* tempEnemigo2 = *itEnemigo2;

        if((tempEnemigo2->desRect.y + 29) >= nave->desRect.y)
        {
            if(((tempEnemigo2->desRect.x +70) < (nave->desRect.x)) || ((tempEnemigo2->desRect.x) > (nave->desRect.x + 60)))
            {
                tempEnemigo2->upDate();
            }
            else
            {
                listEnemigos2.remove(*itEnemigo2);
                break;
            }

        }
        else
        {
            tempEnemigo2->upDate();
        }

        if(tempEnemigo2->desRect.y <= -10 || tempEnemigo2->desRect.x >= 800)
        {
            listEnemigos2.remove(*itEnemigo2);
            std::cout << "Enemigo 2 eliminado \n ";
            break;
        }

    }

    contador ++;

}

void Game::render()
{
    SDL_RenderClear(renderer);
    nave->render();

   for (list<GameObjet*>::iterator it=listaBalas.begin(); it != listaBalas.end(); ++it){
            (*it)->render();
            std::cout << "Se RENDERISO UNA BALA DE LA LISTA \n";
    }
    for (list<GameObjet*>::iterator itEnemigo=listEnemigos.begin(); itEnemigo != listEnemigos.end(); ++itEnemigo)
    {
        (*itEnemigo)->render();
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
