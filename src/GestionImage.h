
#ifndef _GESTIONIMAGE_H
#define _GESTIONIMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class GestionImage {

private:

    SDL_Surface *m_surface;
    SDL_Texture *m_texture;
    bool m_hasChanged;

public:
    GestionImage();
    ~GestionImage();
    void free();
    void loadFile (const char* filename, SDL_Renderer * renderer);
    void loadMap (SDL_Renderer * renderer,int i);
    void loadPerso (SDL_Renderer * renderer,char sprite_perso);
    void draw (SDL_Renderer * renderer, int x, int y, int w, int h);
    //SDL_Texture * getTexture() const;
};
//inline SDL_Texture * GestionImage::getTexture() const {return m_texture;};
#endif
