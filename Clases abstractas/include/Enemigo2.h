#ifndef ENEMIGO2_H
#define ENEMIGO2_H
#include "GameObjet.h"

class Enemigo2 : public GameObjet
{
    public:
        Enemigo2(SDL_Renderer* renderer);
        virtual ~Enemigo2();

        void upDate();
        void render();

    protected:

    private:
};

#endif // ENEMIGO2_H
