#ifndef VENTANA_H
#define VENTANA_H
#include <SDL2/SDL.h>

class Ventana
{
    public:
        Ventana();
        virtual ~Ventana();

    protected:

    private:

        SDL_Window *_window;

};

#endif // VENTANA_H
