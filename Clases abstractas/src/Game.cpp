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
    nave =  FabricaObjetos::crearObjetos(FabricaObjetos::NAVE, renderer,NULL,NULL);


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
            listEnemigos.push_back(FabricaObjetos::crearObjetos(FabricaObjetos::ENEMIGO,renderer,NULL,NULL));
            contarEnemigos ++;

        }
        if(contarEnemigos1 < 9)
        {
            listEnemigos.push_back(FabricaObjetos::crearObjetos(FabricaObjetos::ENEMIGO,renderer,NULL,NULL));
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
            listEnemigos.push_back(FabricaObjetos::crearObjetos(FabricaObjetos::ENEMIGO1,renderer,NULL,NULL));
            contarEnemigos ++;

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
                if(keys[SDL_SCANCODE_SPACE])
                {
                    if(listaBalas.size() <= 10)
                    {
                        listaBalas.push_back(FabricaObjetos::crearObjetos(FabricaObjetos::BALA,renderer, nave->desRect.x + 25,nave->desRect.y - 10));
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

void Game::upDate()
{
    nave->upDate();

    int numero = 1;

    if(contador == 25)
    {
        crearEnemigos();
        contador = 0;
    }

    GameObjet* tempEnemigo;
    GameObjet* temp;

    for (list<GameObjet*>::iterator itEnemigo=listEnemigos.begin(); itEnemigo != listEnemigos.end(); ++itEnemigo)
    {
        tempEnemigo = *itEnemigo;

        if(((tempEnemigo->desRect.y + 29) >= temp->desRect.y) && (tempEnemigo->desRect.y) <= (temp->desRect.y))
        {
            if(!(((tempEnemigo->desRect.x) > (temp->desRect.x + 16)) || ((tempEnemigo->desRect.x + 70) < (temp->desRect.x))))
            {
                listaBalas.remove(temp);
                //listEnemigos.remove(*itEnemigo);
                tempEnemigo->setDestruido(1);
                std::cout << "Choco con enemigo \n ";
                break;
            }
        }
        if(((tempEnemigo->desRect.y + 29) >= nave->desRect.y) && (tempEnemigo->desRect.y) <= (nave->desRect.y))
        {
            if(((tempEnemigo->desRect.x) > (nave->desRect.x + 50)) || ((tempEnemigo->desRect.x + 70) < (nave->desRect.x)))
            {
                tempEnemigo->upDate();
            }else{
                //listEnemigos.remove(*itEnemigo);
                tempEnemigo->setDestruido(1);
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
                //listEnemigos2.remove(*itEnemigo2);
                tempEnemigo->setDestruido(true);
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

    for (list<GameObjet*>::iterator it=listaBalas.begin(); it != listaBalas.end(); ++it)
    {
        temp = *it;

        for (list<GameObjet*>::iterator itEnemigo=listEnemigos.begin(); itEnemigo != listEnemigos.end(); ++itEnemigo)
        {
            tempEnemigo = *itEnemigo;

            if(((tempEnemigo->desRect.y + 29) >= temp->desRect.y) && (tempEnemigo->desRect.y) <= (temp->desRect.y))
            {
                if(!(((tempEnemigo->desRect.x) > (temp->desRect.x + 16)) || ((tempEnemigo->desRect.x + 70) < (temp->desRect.x))))
                {
                    listaBalas.remove(*it);
                    tempEnemigo->setDestruido(1);
                    //listEnemigos.remove(tempEnemigo);
                    std::cout << "Se remobio BALA  \n";
                    break;
                }
            }
        }

        if(((tempEnemigo->desRect.y + 29) >= temp->desRect.y) && (tempEnemigo->desRect.y) <= (temp->desRect.y))
        {
            if(((tempEnemigo->desRect.x) > (temp->desRect.x + 16)) || ((tempEnemigo->desRect.x + 70) < (temp->desRect.x)))
            {
                temp->upDate();
            }
            else
            {
                tempEnemigo->setDestruido(1);

                listaBalas.remove(*it);
                //listEnemigos.remove(tempEnemigo);
                std::cout << "Se remobio BALA  \n";
                break;
            }
        }
        else
        {
            temp->upDate();
        }
        if(temp->desRect.y <= 0)
        {
             listaBalas.remove(*it);
             std::cout << "Se remobio BALA  \n";
             break;
        }

        numero ++;
    }

    contador ++;

}

void Game::render()
{
    SDL_RenderClear(renderer);
    nave->render();

   for (list<GameObjet*>::iterator it=listaBalas.begin(); it != listaBalas.end(); ++it){
            (*it)->render();
            //std::cout << "Se RENDERISO UNA BALA DE LA LISTA \n";
    }
    for (list<GameObjet*>::iterator itEnemigo=listEnemigos.begin(); itEnemigo != listEnemigos.end(); ++itEnemigo)
    {
        GameObjet* temp = (*itEnemigo);
        if(temp->getDestruido()<= 10)
        {
            (*itEnemigo)->render();
            std::cout << "SE REMOVIO EL ENEMIGO TENDRIA QUE EXPLOTAR \n";
            if(temp->getDestruido()== 10)
            {
                listEnemigos.remove(*itEnemigo);
                break;
            }
        }
        else if(temp->getDestruido()== 0)
        {
            (*itEnemigo)->render();
        }
        //(*itEnemigo)->render();
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
