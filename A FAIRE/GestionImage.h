
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
    GestionImage& operator=(const GestionImage& gi);

    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void loadMap(const char* filename, SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
};

#endif
