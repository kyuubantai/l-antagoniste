#ifndef __JEU__H
#define __JEU__H

#include "Monde.h"
//#include "Personnage.h"
//#include "Combat.h"
#include "Deplacement.h"
#include "GestionImage.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * @class Jeu
 *
 * @brief Assemble les éléments du jeu et les affiche avec SDL.
 **/
class Jeu {
    private:    

    //lien sur SDL_Window
        SDL_Window * m_window;
    //lien sur SDL_Renderer
        SDL_Renderer * m_renderer;
    // éventuellement d’autres données (ex. SDL_Surface et SDL_Texture)
        GestionImage map[12];
        GestionImage perso;
        GestionImage ennemi;
        GestionImage dialogue;
        SDL_Surface * m_surface;
        SDL_Texture * m_texture;
        bool m_hasChanged;
        Deplacement d;
        Monde m;
        char sprite_perso;
        int num_pnj=1000;
    public:
        Jeu();
        ~Jeu();
        void afficher_monde();
        void afficher_perso(char& sprite_perso);
        void afficher_dial();
        void boucle_jeu();
        void boucle_combat();

};

#endif