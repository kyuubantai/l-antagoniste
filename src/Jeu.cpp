#include "Jeu.h"
#include <iostream>
using namespace std;
const int proportion = 5;



Jeu::Jeu(): m_window(nullptr),m_surface(nullptr), m_texture(nullptr) {
    //Création fenêtre
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    m_window = SDL_CreateWindow("L'Antagoniste", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 192*5, 112*5, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (m_window == NULL) { 
        cout << "Erreur lors de la création de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }
    m_renderer = SDL_CreateRenderer(m_window, -1,SDL_RENDERER_ACCELERATED);
    //Loads d'image
    for(int i = 0;i<3;i++){
    map[i].loadMap(m_renderer,i+1);
    }
    //Load Personnage
    perso.loadPerso(m_renderer,sprite_perso);
    sprite_perso='a';
    m=d.getMonde();
}

Jeu::~Jeu(){
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
        if (m_texture != nullptr) {
            SDL_DestroyTexture(m_texture);
         }
         if (m_surface != nullptr) {
            SDL_FreeSurface(m_surface);
        }
    SDL_Quit();
}
void Jeu::afficher_monde(){
    //int x,y;
    map[0].draw(m_renderer,0,0,192*proportion,112*proportion);
}

void Jeu::afficher_perso(char& sprite_perso){
    m=d.getMonde();
    perso.draw(m_renderer,m.getY()*16*proportion,m.getX()*16 * proportion,16*proportion,16 * proportion);
    if (sprite_perso!='a') {
        perso.loadPerso(m_renderer,sprite_perso);
        sprite_perso='a';
    }
}

void Jeu::boucle_jeu() {
    bool quit = false;
    SDL_Event event;
    while(!quit){
        while (SDL_PollEvent(&event)) {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        case SDLK_LEFT:
                            d.deplace('g');
                            sprite_perso='g';
                            cout<<m.getY()<<endl;
                            break;
                        case SDLK_RIGHT:
                            d.deplace('d');
                            sprite_perso='d';
                            break;
                        case SDLK_UP:
                            d.deplace('h');
                            sprite_perso='h';
                            cout<<m.getX()<<endl;
                            break;
                        case SDLK_DOWN:
                            d.deplace('b');
                            sprite_perso='b';
                            break;
                        default:
                            break;
                    }
                    break;
                case SDL_WINDOWEVENT:

                    switch (event.window.event) {

                        case SDL_WINDOWEVENT_CLOSE:   // exit game
                            quit=true;
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
        SDL_RenderClear(m_renderer);
        afficher_monde();
        afficher_perso(sprite_perso);
        SDL_RenderPresent(m_renderer);
    }
}