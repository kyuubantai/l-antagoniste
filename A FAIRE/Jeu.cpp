#include "Jeu.h"
#include <iostream>

using namespace std;

Jeu::Jeu(): m_window(nullptr),m_surface(nullptr), m_texture(nullptr) {
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    m_window = SDL_CreateWindow("Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 1200, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (m_window == NULL) { 
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }
    m_renderer = SDL_CreateRenderer(m_window, -1,SDL_RENDERER_ACCELERATED); 
}

Jeu::~Jeu(){
        if (m_texture != nullptr) {
        SDL_DestroyTexture(m_texture);
    }
	if (m_surface != nullptr) {
        SDL_FreeSurface(m_surface);
    }
}

//void Jeu::afficher_monde()
