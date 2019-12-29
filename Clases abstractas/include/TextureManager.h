#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SDL2/SDL.h>

class TextureManager
{
    public:
        TextureManager();
        virtual ~TextureManager();

        static SDL_Texture* loadTexture(const char *file, SDL_Renderer* renderer);

    protected:

    private:
};

#endif // TEXTUREMANAGER_H
