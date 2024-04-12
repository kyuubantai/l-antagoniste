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

        /**
        * @brief Constructeur du Jeu : initialise SDL, fenêtre et l'affichage.
        **/
        Jeu();

        /**
        * @brief Destructeur de la classe
        **/
        ~Jeu();

        /**
        * @brief Affiche la carte actuelle
        **/
        void afficher_monde();

        /**
        * @brief Affiche le personnage
        * @param sprite_perso Caractère permettant de savoir si le personnage est bien affiché.
        **/
        void afficher_perso(char& sprite_perso);

        /**
        * @brief Affiche les boites de dialogues.
        **/
        void afficher_dial();

        /**
        * @brief Récupère la saisie clavier et actualise l'affichage en conséquence.
        **/
        void boucle_jeu();

        /**
        * @brief 
        **/
        void boucle_combat();

};

#endif