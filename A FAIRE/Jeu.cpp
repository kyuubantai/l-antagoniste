#include "Jeu.h"
#include <iostream>

using namespace std;

//char image = "data/carte.bmp";
Jeu::Jeu(): m_window(nullptr),m_surface(nullptr), m_texture(nullptr) {
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    m_window = SDL_CreateWindow("Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 1200, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (m_window == NULL) { 
        cout << "Erreur lors de la création de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
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

void Jeu::afficher_monde() {
    //m_surface = SDL_LoadBMP(image);
    if(m_surface == nullptr) {
     cout << "Erreur lors du chargement de l'image : " << image <<SDL_GetError();   
    }
    m_texture = SDL_CreateTextureFromSurface(m_renderer,m_surface);

    bool quit = false;
    SDL_Event event;
    while(!quit){
        while (SDL_PollEvent(&event)) {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        case SDLK_LEFT:
                            d.deplacement("g",m);
                            break;
                        case SDLK_RIGHT:
                            d.deplacement("d",m);
                            break;
                        case SDLK_UP:
                            d.deplacement("h",m);
                            break;
                        case SDLK_DOWN:
                            d.deplacement("b",m);
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
                }
                if(event.key.keysym.sym == SDLK_ESCAPE) quit = true;
        }

    }
}