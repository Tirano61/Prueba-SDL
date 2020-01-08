#include "TextureManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


TextureManager::TextureManager()
{
    //ctor
}

TextureManager::~TextureManager()
{
    //dtor
}

SDL_Texture* TextureManager::loadTexture(const char *file, SDL_Renderer* renderer)
{
    SDL_Surface* surface = IMG_Load(file);
        if(!surface){
        std::cout << "No se pudo cargar la textura \n";
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);

    return texture;
}
