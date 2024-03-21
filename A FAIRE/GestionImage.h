
#ifndef _GESTIONIMAGE_H
#define _GESTIONIMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class GestionImage {

private:

    SDL_Surface * m_surface;
    SDL_Texture * m_texture;
    bool m_hasChanged;

public:
    GestionImage();
    ~GestionImage();

    void loadFile (const char* filename, SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
};
inline SDL_Texture * GestionImage::getTexture() const {return m_texture;};
#endif
