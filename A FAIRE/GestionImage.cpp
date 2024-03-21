#include "GestionImage.h"
#include <iostream>

using namespace std;
GestionImage::GestionImage(){
    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}
GestionImage::~GestionImage(){
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}

void GestionImage::loadFile(const char* filename, SDL_Renderer * renderer) {
    m_surface = IMG_Load(filename);
    if(!m_surface) {  
    cout << "Erreur lors du chargement de l'image" <<endl<<SDL_GetError()<<endl;
    }
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
}

void GestionImage::draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1){
    int a;
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    pos.w = (w < 0) ? m_surface->w : w;
    pos.h = (h < 0) ? m_surface->h : h;
     if (m_hasChanged)
    {
        a = SDL_UpdateTexture(m_texture, nullptr, m_surface->pixels, m_surface->pitch);
        m_hasChanged = false;
    }
    a = SDL_RenderCopy(renderer,m_texture,nullptr,&pos);
}

