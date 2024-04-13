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
    for(int i = 0;i<12;i++){
    map[i].loadMap(m_renderer,i);
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
    int nCarte =m.getCarte();
    map[nCarte].draw(m_renderer,0,0,192*proportion,112*proportion);
}

void Jeu::afficher_perso(char& sprite_perso){
    m=d.getMonde();
    perso.draw(m_renderer,m.getY()*16*proportion,m.getX()*16 * proportion,16*proportion,16 * proportion);
    if (sprite_perso!='a') {
        perso.loadPerso(m_renderer,sprite_perso);
        sprite_perso='a';
    }
}

void Jeu::afficher_dial(){
    int num_dial=d.getDialogue();
    dialogue.draw(m_renderer,proportion,78*proportion,190*proportion,30*proportion);
    dialogue.loadDial(m_renderer,num_pnj,num_dial);
        std::cout<<d.getDialogue()<<endl;
        std::cout<<d.getPnj()<<endl;
    if (d.getPnj()==51 && d.getDialogue()==3) { // remettre à 0 lorsqu'il y n'y a plus de dialogue
        d.setDialogue(1000);    
        d.setPnj(1000);
    }
    if (d.getPnj()==31 && d.getDialogue()==3) { // remettre à 0 lorsqu'il y n'y a plus de dialogue
        d.setDialogue(1000);    
        d.setPnj(1000);
    }
    if (d.getPnj()==32 && d.getDialogue()==2) { // remettre à 0 lorsqu'il y n'y a plus de dialogue
        d.setDialogue(1000);    
        d.setPnj(1000);
    }
    if (d.getPnj()==11 && d.getDialogue()==2) { // remettre à 0 lorsqu'il y n'y a plus de dialogue
        d.setDialogue(1000);    
        d.setPnj(1000);
    }
    if (d.getPnj()==12 && d.getDialogue()==4) { // remettre à 0 lorsqu'il y n'y a plus de dialogue
        d.setDialogue(1000);    
        d.setPnj(1000);
    }
    if (d.getPnj()==71 && d.getDialogue()==5) { // remettre à 0 lorsqu'il y n'y a plus de dialogue
        d.setDialogue(1000);    
        d.setPnj(1000);
    }
    if (d.getPnj()==72 && d.getDialogue()==4) { // remettre à 0 lorsqu'il y n'y a plus de dialogue
        d.setDialogue(1000);    
        d.setPnj(1000);
    }
    
    num_pnj=d.getPnj();
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
                        case SDLK_LEFT :
                        case SDLK_q :
                            d.deplace('g');
                            sprite_perso='g';
                            break;
                        case SDLK_RIGHT:
                        case SDLK_d :
                            d.deplace('d');
                            sprite_perso='d';
                            break;
                        case SDLK_UP:
                        case SDLK_z :
                            d.deplace('h');
                            sprite_perso='h';
                            break;
                        case SDLK_DOWN:
                        case SDLK_s :
                            d.deplace('b');
                            sprite_perso='b';
                            break;

                        case SDLK_f :
                            d.interaction();
                            num_pnj=d.getPnj();
                            break;
                    
                        default:
                            break;
                    }
                    break;
                case SDL_WINDOWEVENT:

                    switch (event.window.event) {

                        case SDL_WINDOWEVENT_CLOSE:   // exit 
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
        if (num_pnj != 1000) {
        afficher_dial();
        }
        SDL_RenderPresent(m_renderer);
    }
}