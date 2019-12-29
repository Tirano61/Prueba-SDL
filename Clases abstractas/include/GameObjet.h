#ifndef GAMEOBJET_H
#define GAMEOBJET_H
#include <SDL2/SDL.h>

class GameObjet
{
    public:
        GameObjet(const char* file, SDL_Renderer* renderer, int xpos, int ypos, int tipo, int enemigo);
        virtual ~GameObjet();

        void upDate();
        void render();
        SDL_Rect srcRect, desRect;

    private:

        int xpos,ypos;

        SDL_Texture* objTexture;

        SDL_Renderer* _renderer;
        static const int velBala = 5;
        static const int velNave = 3;
        static const int velEnemigo = 2;
        int _tipo;
        int movimiento = 0;
        int _enemigo;




};

#endif // GAMEOBJET_H
