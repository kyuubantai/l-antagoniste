#ifndef __JEU__H
#define __JEU__H

#include "Monde.h"
#include "Combat.h"
#include "Deplacement.h"
#include <SDL2/SDL.h>

class Jeu {
    private:    

    //lien sur SDL_Window
        SDL_Window * m_window;
    //lien sur SDL_Renderer
        SDL_Renderer * m_renderer;
    // éventuellement d’autres données (ex. SDL_Surface et SDL_Texture)
        SDL_Surface * m_surface;
        SDL_Texture * m_texture;
        bool m_hasChanged;
    public:
        Jeu();
        ~Jeu();
        void afficher_monde(const Monde &m);
        void boucle_combat();

};

#endif