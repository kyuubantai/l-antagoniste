
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
        * @brief Permet de charger l'image du personnage en fonction de la direction où il se dirige.
        * @param renderer le renderer de l'image.
        * @param sprite_perso le chemin de l'image voulue du personnage.
        **/
        void loadPerso (SDL_Renderer * renderer,char sprite_perso);

        /**
        * @brief Dessine un rectangle grâce aux données en paramètre.
        * @param renderer le renderer de l'image.
        * @param x la coordonnée horizontale de l'angle supérieur gauche du rectangle.
        * @param y la coordonnée verticale de l'angle supérieur gauche du rectangle.
        * @param w la largeur du rectangle.
        * @param h la hauteur du rectangle.
        **/
        void draw (SDL_Renderer * renderer, int x, int y, int w, int h);

        /**
        * @brief Permet de créer les pages de dialogues en fonction du PNJ.
        * @param renderer le renderer de l'image.
        * @param num_pnj le numéro identifiant le pnj.
        * @param num_dial le numéro du dialogue en question.
        **/
        void creerDial(SDL_Renderer * renderer, int num_pnj,int num_dial);


        //SDL_Texture * getTexture() const;
};
//inline SDL_Texture * GestionImage::getTexture() const {return m_texture;};
#endif
