#ifndef GAMEOBJET_H
#define GAMEOBJET_H
#include <SDL.h>

class GameObjet
{
    public:
        GameObjet(SDL_Renderer* renderer);
        virtual ~GameObjet();

        virtual void upDate();
        virtual void render();
        virtual void setDestruido(int destruido);
        virtual int getDestruido();

        SDL_Rect srcRect, desRect;

        virtual int getTipo();

        int xpos,ypos;

        SDL_Texture* objTexture;

        SDL_Renderer* _renderer;
        static const int velBala = 5;
        static const int velNave = 3;
        static const int velEnemigo = 2;
        int _tipo;
        int movimiento = 0;
        int _enemigo;
        int _destruido;




};

#endif // GAMEOBJET_H
