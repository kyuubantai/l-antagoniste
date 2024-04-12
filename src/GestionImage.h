
#ifndef _GESTIONIMAGE_H
#define _GESTIONIMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * @class GestionImage
 *
 * @brief Permet de charger les images dans le jeu.
 **/
class GestionImage {

    private:

        SDL_Surface *m_surface;
        SDL_Texture *m_texture;
        bool m_hasChanged;

    public:

        /**
        * @brief Constructeur de la classe : initialise m_surface, m_texture et m_hasChanged
        **/
        GestionImage();

        /**
        * @brief Destructeur de la classe.
        **/
        ~GestionImage();

        /**
        * @brief Permet de charger une image dans le jeu.
        * @param filename le chemin du fichier.
        * @param renderer le renderer de l'image.
        **/
        void loadFile (const char* filename, SDL_Renderer * renderer);

        /**
        * @brief Permet de charger l'apparence d'une des cartes dans le jeu.
        * @param filename le chemin du fichier.
        * @param renderer le renderer de l'image.
        **/
        void loadMap (SDL_Renderer * renderer,int i);

        /**
        * @brief Permet de charger l'apparence d'une des cartes dans le jeu.
        * @param renderer le renderer de l'image.
        * @param sprite_perso le chemin de l'image du personnage voulue.
        **/
        void loadPerso (SDL_Renderer * renderer,char sprite_perso);

        /**
        * @brief
        * @param renderer le renderer de l'image.
        **/
        void draw (SDL_Renderer * renderer, int x, int y, int w, int h);

        /**
        * @brief
        **/
        void creerDial(SDL_Renderer * renderer, int num_pnj,int num_dial);


        //SDL_Texture * getTexture() const;
};
//inline SDL_Texture * GestionImage::getTexture() const {return m_texture;};
#endif
